#include "ServerTcp.hpp"

using namespace TypeLink;

ServerTCP::ServerTCP() : CommunicationTCP(std::make_shared<Console>())
{
    this->_portTcp = 0;
    this->_maxConnections = 0;
    this->_connections = std::make_shared<std::vector<std::shared_ptr<Connection>>>();
}

ServerTCP::ServerTCP(std::shared_ptr<Console> console) : CommunicationTCP(console)
{
    this->_portTcp = 0;
    this->_maxConnections = 0;
    this->_connections = std::make_shared<std::vector<std::shared_ptr<Connection>>>();
}

ServerTCP::ServerTCP(uint16_t port, size_t maxConnections) : CommunicationTCP(std::make_shared<Console>())
{
    this->_portTcp = port;
    this->_maxConnections = maxConnections;
    this->_connections = std::make_shared<std::vector<std::shared_ptr<Connection>>>();
    this->initTcpSocket();
}

ServerTCP::ServerTCP(uint16_t port, size_t maxConnections, std::shared_ptr<Console> console) : CommunicationTCP(console)
{
    this->_portTcp = port;
    this->_maxConnections = maxConnections;
    this->_connections = std::make_shared<std::vector<std::shared_ptr<Connection>>>();
    this->initTcpSocket();
}

ServerTCP::ServerTCP(uint16_t port, size_t maxConnections, TimeoutTcp timeoutTcp) : CommunicationTCP(std::make_shared<Console>())
{
    this->_portTcp = port;
    this->_maxConnections = maxConnections;
    this->_connections = std::make_shared<std::vector<std::shared_ptr<Connection>>>();
    this->_timeoutRecvTcp = timeoutTcp.timeoutRecvTcp;
    this->_timeoutSendTcp = timeoutTcp.timeoutSendTcp;
    this->initTcpSocket();
}

ServerTCP::ServerTCP(uint16_t port, size_t maxConnections, TimeoutTcp timeoutTcp, std::shared_ptr<Console> console) : CommunicationTCP(console)
{
    this->_portTcp = port;
    this->_maxConnections = maxConnections;
    this->_connections = std::make_shared<std::vector<std::shared_ptr<Connection>>>();
    this->_timeoutRecvTcp = timeoutTcp.timeoutRecvTcp;
    this->_timeoutSendTcp = timeoutTcp.timeoutSendTcp;
    this->initTcpSocket();
}

ServerTCP::~ServerTCP()
{
    this->removeAllTcpConnections();
    this->closeTcpSocket();
    this->_console->info("ServerTCP: Socket closed");
}

void ServerTCP::resetTcpFdSet()
{
    FD_ZERO(&this->_rdfd);
    FD_ZERO(&this->_wdfd);
    FD_SET(this->_sock, &this->_rdfd);
    FD_SET(this->_sock, &this->_wdfd);
    for (auto &connection : *this->_connections)
        connection->resetFdSet(&this->_rdfd, &this->_wdfd);
}

void ServerTCP::initTcpSocket()
{
    this->_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->_sock == -1)
        throw this->_console->throwException("ServerTcp: socket() failed");
    this->_sin.sin_family = AF_INET;
    this->_sin.sin_addr.s_addr = INADDR_ANY;
    this->_sin.sin_port = htons(this->_portTcp);
    if (bind(this->_sock, (struct sockaddr *)&this->_sin, sizeof(this->_sin)) == -1)
        throw this->_console->throwException("ServerTcp: bind() failed");
    if (listen(this->_sock, this->_maxConnections) == -1)
        throw this->_console->throwException("ServerTcp: listen() failed");
    if (setsockopt(this->_sock, SOL_SOCKET, SO_RCVTIMEO, &this->_timeoutRecvTcp, sizeof(this->_timeoutRecvTcp)) == -1)
        throw this->_console->throwException("ServerTcp: setsockopt() timeoutRecv failed");
    if (setsockopt(this->_sock, SOL_SOCKET, SO_SNDTIMEO, &this->_timeoutSendTcp, sizeof(this->_timeoutSendTcp)) == -1)
        throw this->_console->throwException("ServerTcp: setsockopt() timeoutSend failed");
    this->_maxFd = this->_sock;
    this->_console->info("ServerTCP: Socket initialized");
}

void ServerTCP::acceptTcpConnection()
{
    this->resetTcpFdSet();
    if (select(this->_maxFd + 1, &this->_rdfd, NULL, NULL, &this->_timeoutRecvTcp) >= 0) {
        if (FD_ISSET(this->_sock, &this->_rdfd)) {
            std::shared_ptr<Connection> connection = std::make_shared<Connection>(this->_console);
            struct sockaddr_in sin;
            socklen_t sin_len = sizeof(sin);
            int sock = accept(this->_sock, (struct sockaddr *)&sin, &sin_len);

            if (sock == -1)
                throw this->_console->throwException("Error: accept() failed");
            connection->setSocket(sock);
            connection->setAddress(sin);
            this->_connections->push_back(connection);

            if (this->_connections->size() > this->_maxConnections) {
                this->_console->warn("Connection " + connection->getIp() + ":" + std::to_string(connection->getPort()) + " refused (max connections reached)");
                this->removeTcpConnection(sock);
                return;
            }

            FD_SET(sock, &this->_rdfd);
            FD_SET(sock, &this->_wdfd);
            if (sock > this->_maxFd)
                this->_maxFd = sock;

            this->_console->info("Connection " + connection->getIp() + ":" + std::to_string(connection->getPort()) + " accepted");
        }
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Connection>>> ServerTCP::getTcpConnections()
{
    return this->_connections;
}

void ServerTCP::sendTcpPacketTo(int sock, std::shared_ptr<Packet> data)
{
    for (auto &connection : *this->_connections) {
        if (connection->getSocket() == sock) {
            try {
                this->resetTcpFdSet();
                this->sendComTcpPacketTo(sock, data);
            } catch (const std::exception &error) {
                this->_console->warn("ServerTcp: sendTcpPacketTo() failed, sock " + std::to_string(sock) + " disconnected");
                this->removeTcpConnection(sock);
            }
            return;
        }
    }
    this->_console->warn("ServerTcp: sendTcpPacketTo() failed, sock not found");
}

void ServerTCP::sendTcpPacketToAll(std::shared_ptr<Packet> data)
{
    for (auto &connection : *this->_connections) {
        try {
            this->resetTcpFdSet();
            this->sendComTcpPacketTo(connection->getSocket(), data);
        } catch (const std::exception &error) {
            throw this->_console->throwException(error.what());
        }
    }
}

std::shared_ptr<Packet> ServerTCP::recvTcpPacketFrom(int sock)
{
    for (auto &connection : *this->_connections) {
        if (connection->getSocket() == sock) {
            try {
                this->resetTcpFdSet();
                return this->recvComTcpPacketFrom(sock);
            } catch (const std::exception &error) {
                throw this->_console->throwException(error.what());
            }
        }
    }
    return nullptr;
}

void ServerTCP::removeTcpConnection(int sock)
{
    for (auto it = this->_connections->begin(); it != this->_connections->end(); ++it) {
        if (it->get()->getSocket() == sock) {
            this->_connections->erase(it);
            break;
        }
    }
    for (auto &connection : *this->_connections) {
        if (connection->getSocket() > this->_maxFd)
            this->_maxFd = connection->getSocket();
    }
}

void ServerTCP::removeAllTcpConnections()
{
    for (auto &connection : *this->_connections)
        connection->closeConnection();
    this->_connections->clear();
    this->_maxFd = this->_sock;
}