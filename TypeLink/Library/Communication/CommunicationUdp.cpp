#include "CommunicationUdp.hpp"

using namespace TypeLink;

CommunicationUDP::CommunicationUDP(std::shared_ptr<Console> console) : Network(console)
{
    this->_timeoutRecvUdp.tv_sec = 0;
    this->_timeoutRecvUdp.tv_usec = 0;
    this->_timeoutSendUdp.tv_sec = 0;
    this->_timeoutSendUdp.tv_usec = 0;
}

CommunicationUDP::~CommunicationUDP()
{
}

void CommunicationUDP::sendComUdpPacketTo(int sock, std::shared_ptr<Packet> data)
{
    if (select(sock + 1, NULL, &this->_wdfd, NULL, &this->_timeoutSendUdp) >= 0) {
        if (FD_ISSET(sock, &this->_wdfd)) {
            try {
                this->udpSendPacket(sock, data);
            } catch (std::exception &error) {
                throw this->_console->throwException(error.what());
            }
        }
    }
}

std::shared_ptr<Packet> CommunicationUDP::recvComUdpPacket(int sock)
{
    if (select(sock + 1, &this->_rdfd, NULL, NULL, &this->_timeoutRecvUdp) >= 0) {
        if (FD_ISSET(sock, &this->_rdfd)) {
            try {
                return this->udpReceivePacket(sock);
            } catch (std::exception &error) {
                throw this->_console->throwException(error.what());
            }
        }
    }
    return nullptr;
}

void CommunicationUDP::closeUdpSocket()
{
    this->closeSocket();
}