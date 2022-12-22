#ifndef COMMUNICATIONTCP_HPP_
#define COMMUNICATIONTCP_HPP_

#include "Network.hpp"
#include "Console.hpp"
#include "Includes.hpp"

namespace TypeLink {
    class CommunicationTCP : public Network {
        protected:
            struct timeval _timeoutRecvTcp;
            struct timeval _timeoutSendTcp;
            void sendComTcpPacketTo(int sock, std::shared_ptr<Packet> data);
            std::shared_ptr<Packet> recvComTcpPacketFrom(int sock);
        public:
            CommunicationTCP(std::shared_ptr<Console> console);
            ~CommunicationTCP();
            void closeTcpSocket();
    };
} // namespace TypeLink

#endif /* !COMMUNICATIONTCP_HPP_ */