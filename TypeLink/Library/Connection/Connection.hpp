#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include "Network.hpp"
#include "Console.hpp"
#include "Includes.hpp"

namespace TypeLink
{
    class Connection : public Network {
        public:
            Connection(std::shared_ptr<Console> console);
            Connection(int sock, struct sockaddr_in sin, std::shared_ptr<Console> console);
            ~Connection();
            int getSocket();
            std::string getIp();
            uint16_t getPort();
            struct sockaddr_in getSockaddrIn();
            void setSocket(int sock);
            void setIp(std::string ip);
            void setPort(uint16_t port);
            void setAddress(struct sockaddr_in sin);
            void resetFdSet(fd_set *rdfd, fd_set *wdfd);
            void closeConnection();
    };
} // namespace TypeLink

#endif /* !CONNECTION_HPP_ */