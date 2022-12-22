#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "Console.hpp"
#include "ClientTcp.hpp"
#include "ClientUdp.hpp"
#include "Includes.hpp"

namespace TypeLink {
    class Client : public ClientTCP, public ClientUDP {
        public:
            Client();
            Client(std::shared_ptr<Console> console);
            Client(std::string ip, uint16_t portTcp, uint16_t portUdp, std::shared_ptr<Console> console);
            Client(ClientInit init, std::shared_ptr<Console> console);
            ~Client();
    };  
} // namespace TypeLink

#endif /* !CLIENT_HPP_ */