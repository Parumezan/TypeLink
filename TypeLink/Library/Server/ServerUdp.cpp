#include "ServerUdp.hpp"

using namespace TypeLink;

ServerUDP::ServerUDP() : CommunicationUDP(std::make_shared<Console>())
{
    this->_portUdp = 0;
}

ServerUDP::ServerUDP(std::shared_ptr<Console> console) : CommunicationUDP(console)
{
    this->_portUdp = 0;
}

ServerUDP::ServerUDP(uint16_t port) : CommunicationUDP(std::make_shared<Console>())
{
    this->_portUdp = port;
    this->initUdpSocket();
}

ServerUDP::ServerUDP(uint16_t port, std::shared_ptr<Console> console) : CommunicationUDP(console)
{
    this->_portUdp = port;
    this->initUdpSocket();
}

ServerUDP::ServerUDP(uint16_t port, TimeoutUdp timeoutUdp) : CommunicationUDP(std::make_shared<Console>())
{
    this->_portUdp = port;
    this->_timeoutRecvUdp = timeoutUdp.timeoutRecvUdp;
    this->_timeoutSendUdp = timeoutUdp.timeoutSendUdp;
    this->initUdpSocket();
}

ServerUDP::ServerUDP(uint16_t port, TimeoutUdp timeoutUdp, std::shared_ptr<Console> console) : CommunicationUDP(console)
{
    this->_portUdp = port;
    this->_timeoutRecvUdp = timeoutUdp.timeoutRecvUdp;
    this->_timeoutSendUdp = timeoutUdp.timeoutSendUdp;
    this->initUdpSocket();
}

ServerUDP::~ServerUDP()
{
    this->closeUdpSocket();
    this->_console->info("ServerUDP: socket closed");
}

void ServerUDP::resetUdpFdSet()
{
    FD_ZERO(&this->_rdfd);
    FD_ZERO(&this->_wdfd);
    FD_SET(this->_sock, &this->_rdfd);
    FD_SET(this->_sock, &this->_wdfd);
}

void ServerUDP::initUdpSocket()
{
    this->_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->_sock == -1)
        throw this->_console->throwException("ServerUdp: socket() failed");
    this->_sin.sin_family = AF_INET;
    this->_sin.sin_addr.s_addr = INADDR_ANY;
    this->_sin.sin_port = htons(this->_portUdp);
    if (bind(this->_sock, (struct sockaddr *)&this->_sin, sizeof(this->_sin)) == -1)
        throw this->_console->throwException("ServerUdp: bind() failed");
    if (setsockopt(this->_sock, SOL_SOCKET, SO_RCVTIMEO, &this->_timeoutRecvUdp, sizeof(this->_timeoutRecvUdp)) == -1)
        throw this->_console->throwException("ServerUdp: setsockopt() timeoutRecv failed");
    if (setsockopt(this->_sock, SOL_SOCKET, SO_SNDTIMEO, &this->_timeoutSendUdp, sizeof(this->_timeoutSendUdp)) == -1)
        throw this->_console->throwException("ServerUdp: setsockopt() timeoutSend failed");
    this->_console->info("ServerUDP: socket initialized");
}

void ServerUDP::sendUdpPacketTo(int sock, std::shared_ptr<Packet> data)
{
    try {
        this->resetUdpFdSet();
        this->sendComUdpPacketTo(sock, data);
    } catch (std::exception &error) {
        this->_console->warn("ServerUDP: sendUdpPacketTo() failed");
        throw this->_console->throwException(error.what());
    }
}

std::shared_ptr<Packet> ServerUDP::recvUdpPacket()
{
    try {
        this->resetUdpFdSet();
        return this->recvComUdpPacket(this->_sock);
    } catch (std::exception &error) {
        this->_console->warn("ServerUDP: recvUdpPacket() failed");
        throw this->_console->throwException(error.what());
    }
    return nullptr;
}