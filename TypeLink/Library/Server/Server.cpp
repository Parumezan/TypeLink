#include "Server.hpp"

using namespace TypeLink;

Server::Server() : ServerTCP(), ServerUDP()
{
}

Server::Server(std::shared_ptr<Console> console) : ServerTCP(console), ServerUDP(console)
{
}

Server::Server(uint16_t portTcp, uint16_t portUdp, size_t maxConnections, std::shared_ptr<Console> console) : ServerTCP(portTcp, maxConnections, console), ServerUDP(portUdp, console)
{
}

Server::Server(ServerInit init, std::shared_ptr<Console> console) : ServerTCP(init.portTcp, init.maxConnections, init.timeoutTcp, console), ServerUDP(init.portUdp, init.timeoutUdp, console)
{
}

Server::~Server()
{
}