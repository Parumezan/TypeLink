#include "ClientTcp.hpp"

using namespace TypeLink;

ClientTCP::ClientTCP() : CommunicationTCP(std::make_shared<Console>())
{
}

ClientTCP::ClientTCP(std::shared_ptr<Console> console) : CommunicationTCP(console)
{
}

ClientTCP::ClientTCP(std::string ip, uint16_t port) : CommunicationTCP(std::make_shared<Console>())
{
    this->_ipTcp = ip;
    this->_portTcp = port;
    this->initTcpSocket();
}

ClientTCP::ClientTCP(std::string ip, uint16_t port, std::shared_ptr<Console> console) : CommunicationTCP(console)
{
    this->_ipTcp = ip;
    this->_portTcp = port;
    this->initTcpSocket();
}

ClientTCP::ClientTCP(std::string ip, uint16_t port, TimeoutTcp timeoutTcp) : CommunicationTCP(std::make_shared<Console>())
{
    this->_ipTcp = ip;
    this->_portTcp = port;
    this->initTcpSocket();
    this->_timeoutRecvTcp = timeoutTcp.timeoutRecvTcp;
    this->_timeoutSendTcp = timeoutTcp.timeoutSendTcp;
}

ClientTCP::ClientTCP(std::string ip, uint16_t port, TimeoutTcp timeoutTcp, std::shared_ptr<Console> console) : CommunicationTCP(console)
{
    this->_ipTcp = ip;
    this->_portTcp = port;
    this->initTcpSocket();
    this->_timeoutRecvTcp = timeoutTcp.timeoutRecvTcp;
    this->_timeoutSendTcp = timeoutTcp.timeoutSendTcp;
}

ClientTCP::~ClientTCP()
{
    this->closeTcpSocket();
    this->_console->info("ClientTCP: socket closed");
}

void ClientTCP::resetTcpFdSet()
{
    FD_ZERO(&this->_rdfd);
    FD_ZERO(&this->_wdfd);
    FD_SET(this->_sock, &this->_rdfd);
    FD_SET(this->_sock, &this->_wdfd);
}

void ClientTCP::initTcpSocket()
{
    this->_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->_sock == -1)
        throw this->_console->throwException("Error: socket() failed");
    this->_sin.sin_family = AF_INET;
    this->_sin.sin_port = htons(this->_portTcp);
    if (inet_pton(AF_INET, this->_ipTcp.c_str(), &this->_sin.sin_addr) == 0)
        throw this->_console->throwException("Error: inet_aton() failed");
    this->_console->info("ClientTCP: Socket initialized");
}

void ClientTCP::connectTcpSocket()
{
    if (connect(this->_sock, (struct sockaddr *)&this->_sin, sizeof(this->_sin)) == -1)
        throw this->_console->throwException("Error: connect() failed");
}

void ClientTCP::sendTcpPacket(std::shared_ptr<Packet> data)
{
    this->resetTcpFdSet();
    try {
        this->sendComTcpPacketTo(this->_sock, data);
    } catch (std::exception &error) {
        throw this->_console->throwException(error.what());
    }
}

std::shared_ptr<Packet> ClientTCP::recvTcpPacket()
{
    this->resetTcpFdSet();
    try {
        return this->recvComTcpPacketFrom(this->_sock);
    } catch (std::exception &error) {
        throw this->_console->throwException(error.what());
    }
}