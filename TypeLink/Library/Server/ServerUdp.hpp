#ifndef SERVERUDP_HPP_
#define SERVERUDP_HPP_

#include "CommunicationUdp.hpp"
#include "Console.hpp"
#include "Includes.hpp"

namespace TypeLink {
    class ServerUDP : public CommunicationUDP {
        protected:
            uint16_t _portUdp;
            void resetUdpFdSet();
        public:
            ServerUDP();
            ServerUDP(std::shared_ptr<Console> console);
            ServerUDP(uint16_t port);
            ServerUDP(uint16_t port, std::shared_ptr<Console> console);
            ServerUDP(uint16_t port, TimeoutUdp timeoutUdp);
            ServerUDP(uint16_t port, TimeoutUdp timeoutUdp, std::shared_ptr<Console> console);
            ~ServerUDP();
            void initUdpSocket();
            void sendUdpPacketTo(int sock, std::shared_ptr<Packet> data);
            std::shared_ptr<Packet> recvUdpPacket();
    };
} // namespace TypeLink

#endif /* !SERVERUDP_HPP_ */