#ifndef COMMUNICATIONUDP_HPP_
#define COMMUNICATIONUDP_HPP_

#include "Network.hpp"
#include "Console.hpp"
#include "Includes.hpp"

namespace TypeLink {
    class CommunicationUDP : public Network {
        protected:
            struct timeval _timeoutRecvUdp;
            struct timeval _timeoutSendUdp;
            void sendComUdpPacketTo(int sock, std::shared_ptr<Packet> data);
            std::shared_ptr<Packet> recvComUdpPacket(int sock);
        public:
            CommunicationUDP(std::shared_ptr<Console> console);
            ~CommunicationUDP();
            void closeUdpSocket();
    };
} // namespace TypeLink

#endif /* !COMMUNICATIONUDP_HPP_ */