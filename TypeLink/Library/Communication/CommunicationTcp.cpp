#include "CommunicationTcp.hpp"

using namespace TypeLink;

CommunicationTCP::CommunicationTCP(std::shared_ptr<Console> console) : Network(console)
{
    this->_timeoutRecvTcp.tv_sec = 0;
    this->_timeoutRecvTcp.tv_usec = 0;
    this->_timeoutSendTcp.tv_sec = 0;
    this->_timeoutSendTcp.tv_usec = 0;
}

CommunicationTCP::~CommunicationTCP()
{
}

void CommunicationTCP::sendComTcpPacketTo(int sock, std::shared_ptr<Packet> data)
{
    if (select(sock + 1, NULL, &this->_wdfd, NULL, &this->_timeoutSendTcp) >= 0) {
        if (FD_ISSET(sock, &this->_wdfd)) {
            try {
                this->tcpSendPacket(sock, data);
            } catch (std::exception &error) {
                throw this->_console->throwException(error.what());
            }
        }
    }
}

std::shared_ptr<Packet> CommunicationTCP::recvComTcpPacketFrom(int sock)
{
    if (select(sock + 1, &this->_rdfd, NULL, NULL, &this->_timeoutRecvTcp) >= 0) {
        if (FD_ISSET(sock, &this->_rdfd)) {
            try {
                return this->tcpReceivePacket(sock);
            } catch (std::exception &error) {
                throw this->_console->throwException(error.what());
            }
        }
    }
    return nullptr;
}

void CommunicationTCP::closeTcpSocket()
{
    this->closeSocket();
}