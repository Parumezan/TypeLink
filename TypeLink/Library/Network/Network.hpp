#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include "Console.hpp"
#include "Includes.hpp"

namespace TypeLink {
    class Network {
        protected:
            std::shared_ptr<Console> _console;
            int _sock;
            struct sockaddr_in _sin;
            fd_set _rdfd;
            fd_set _wdfd;
            void setSocket(int sock);
            void closeSocket();
            void resetSocket();
            void tcpSendPacket(int sock, std::shared_ptr<Packet> data);
            void udpSendPacket(int sock, std::shared_ptr<Packet> data);
            std::shared_ptr<Packet> tcpReceivePacket(int sock);
            std::shared_ptr<Packet> udpReceivePacket(int sock);
        public:
            Network(std::shared_ptr<Console> console);
            ~Network();
    };
} // namespace TypeLink

#endif /* !NETWORK_HPP_ */