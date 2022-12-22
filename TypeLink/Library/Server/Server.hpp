#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "Console.hpp"
#include "ServerUdp.hpp"
#include "ServerTcp.hpp"
#include "Includes.hpp"

namespace TypeLink {
    class Server : public ServerTCP, public ServerUDP {
        public:
            Server();
            Server(std::shared_ptr<Console> console);
            Server(uint16_t portTcp, uint16_t portUdp, size_t maxConnections, std::shared_ptr<Console> console);
            Server(ServerInit init, std::shared_ptr<Console> console);
            ~Server();
    };
} // namespace TypeLink

#endif /* !SERVER_HPP_ */