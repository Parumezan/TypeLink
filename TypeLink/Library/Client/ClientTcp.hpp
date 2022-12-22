#ifndef CLIENTTCP_HPP_
#define CLIENTTCP_HPP_

#include "CommunicationTcp.hpp"
#include "Console.hpp"
#include "Includes.hpp"

namespace TypeLink {
    class ClientTCP : public CommunicationTCP {
        protected:
            struct timeval _timeoutRecvTcp;
            struct timeval _timeoutSendTcp;
            std::string _ipTcp;
            uint16_t _portTcp;
            void resetTcpFdSet();
        public:
            ClientTCP();
            ClientTCP(std::shared_ptr<Console> console);
            ClientTCP(std::string ip, uint16_t port);
            ClientTCP(std::string ip, uint16_t port, std::shared_ptr<Console> console);
            ClientTCP(std::string ip, uint16_t port, TimeoutTcp timeoutTcp);
            ClientTCP(std::string ip, uint16_t port, TimeoutTcp timeoutTcp, std::shared_ptr<Console> console);
            ~ClientTCP();
            void initTcpSocket();
            void connectTcpSocket();
            void sendTcpPacket(std::shared_ptr<Packet> data);
            std::shared_ptr<Packet> recvTcpPacket();
    };
} // namespace TypeLink

#endif /* !CLIENTTCP_HPP_ */