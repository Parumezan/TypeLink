#include "ClientUdp.hpp"

using namespace TypeLink;

ClientUDP::ClientUDP() : CommunicationUDP(std::make_shared<Console>())
{
}

ClientUDP::ClientUDP(std::shared_ptr<Console> console) : CommunicationUDP(console)
{
}

ClientUDP::ClientUDP(std::string ip, uint16_t port) : CommunicationUDP(std::make_shared<Console>())
{
    this->_ipUdp = ip;
    this->_portUdp = port;
    this->initUdpSocket();
}

ClientUDP::ClientUDP(std::string ip, uint16_t port, std::shared_ptr<Console> console) : CommunicationUDP(console)
{
    this->_ipUdp = ip;
    this->_portUdp = port;
    this->initUdpSocket();
}

ClientUDP::ClientUDP(std::string ip, uint16_t port, TimeoutUdp timeoutUdp) : CommunicationUDP(std::make_shared<Console>())
{
    this->_ipUdp = ip;
    this->_portUdp = port;
    this->initUdpSocket();
    this->_timeoutRecvUdp = timeoutUdp.timeoutRecvUdp;
    this->_timeoutSendUdp = timeoutUdp.timeoutSendUdp;
}

ClientUDP::ClientUDP(std::string ip, uint16_t port, TimeoutUdp timeoutUdp, std::shared_ptr<Console> console) : CommunicationUDP(console)
{
    this->_ipUdp = ip;
    this->_portUdp = port;
    this->initUdpSocket();
    this->_timeoutRecvUdp = timeoutUdp.timeoutRecvUdp;
    this->_timeoutSendUdp = timeoutUdp.timeoutSendUdp;
}

ClientUDP::~ClientUDP()
{
    this->closeUdpSocket();
    this->_console->info("ClientUDP: socket closed");
}

void ClientUDP::resetUdpFdSet()
{
    FD_ZERO(&this->_rdfd);
    FD_ZERO(&this->_wdfd);
    FD_SET(this->_sock, &this->_rdfd);
    FD_SET(this->_sock, &this->_wdfd);
}

void ClientUDP::initUdpSocket()
{
    this->_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->_sock == -1)
        throw this->_console->throwException("Error: socket() failed");
    this->_sin.sin_family = AF_INET;
    this->_sin.sin_port = htons(this->_portUdp);
    if (inet_pton(AF_INET, this->_ipUdp.c_str(), &this->_sin.sin_addr) == 0)
        throw this->_console->throwException("Error: inet_aton() failed");
    this->_console->info("ClientUDP: Socket initialized");
}

void ClientUDP::sendUdpPacket(std::shared_ptr<Packet> data)
{
    this->resetUdpFdSet();
    try {
        this->sendComUdpPacketTo(this->_sock, data);
    } catch (std::exception &error) {
        throw this->_console->throwException(error.what());
    }
}

std::shared_ptr<Packet> ClientUDP::recvUdpPacket()
{
    this->resetUdpFdSet();
    try {
        return this->recvComUdpPacket(this->_sock);
    } catch (std::exception &error) {
        throw this->_console->throwException(error.what());
    }
}