#ifndef SERVERTCP_HPP_
#define SERVERTCP_HPP_

#include "CommunicationTcp.hpp"
#include "Console.hpp"
#include "Connection.hpp"
#include "Includes.hpp"

namespace TypeLink {
    class ServerTCP : public CommunicationTCP {
        protected:
            uint16_t _portTcp;
            uint16_t _maxFd;
            size_t _maxConnections;
            std::shared_ptr<std::vector<std::shared_ptr<Connection>>> _connections;
            void resetTcpFdSet();
        public:
            ServerTCP();
            ServerTCP(std::shared_ptr<Console> console);
            ServerTCP(uint16_t port, size_t maxConnections);
            ServerTCP(uint16_t port, size_t maxConnections, std::shared_ptr<Console> console);
            ServerTCP(uint16_t port, size_t maxConnections, TimeoutTcp timeoutTcp);
            ServerTCP(uint16_t port, size_t maxConnections, TimeoutTcp timeoutTcp, std::shared_ptr<Console> console);
            ~ServerTCP();
            void initTcpSocket();
            void acceptTcpConnection();
            std::shared_ptr<std::vector<std::shared_ptr<Connection>>> getTcpConnections();
            void sendTcpPacketTo(int sock, std::shared_ptr<Packet> data);
            void sendTcpPacketToAll(std::shared_ptr<Packet> data);
            std::shared_ptr<Packet> recvTcpPacketFrom(int sock);
            void removeTcpConnection(int sock);
            void removeAllTcpConnections();
    };
} // namespace TypeLink

#endif /* !SERVERTCP_HPP_ */