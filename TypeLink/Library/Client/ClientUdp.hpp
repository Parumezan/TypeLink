#ifndef CLIENTUDP_HPP_
#define CLIENTUDP_HPP_

#include "CommunicationUdp.hpp"
#include "Console.hpp"
#include "Includes.hpp"

namespace TypeLink {
    class ClientUDP : public CommunicationUDP {
        protected:
            struct timeval _timeoutRecvUdp;
            struct timeval _timeoutSendUdp;
            std::string _ipUdp;
            uint16_t _portUdp;
            void resetUdpFdSet();
        public:
            ClientUDP();
            ClientUDP(std::shared_ptr<Console> console);
            ClientUDP(std::string ip, uint16_t port);
            ClientUDP(std::string ip, uint16_t port, std::shared_ptr<Console> console);
            ClientUDP(std::string ip, uint16_t port, TimeoutUdp timeoutUdp);
            ClientUDP(std::string ip, uint16_t port, TimeoutUdp timeoutUdp, std::shared_ptr<Console> console);
            ~ClientUDP();
            void initUdpSocket();
            void sendUdpPacket(std::shared_ptr<Packet> data);
            std::shared_ptr<Packet> recvUdpPacket();
    };
} // namespace TypeLink

#endif /* !CLIENTUDP_HPP_ */