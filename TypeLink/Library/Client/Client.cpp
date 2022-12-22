#include "Client.hpp"

using namespace TypeLink;

Client::Client() : ClientTCP(), ClientUDP()
{
}

Client::Client(std::shared_ptr<Console> console) : ClientTCP(console), ClientUDP(console)
{
}

Client::Client(std::string ip, uint16_t portTcp, uint16_t portUdp, std::shared_ptr<Console> console) : ClientTCP(ip, portTcp, console), ClientUDP(ip, portUdp, console)
{
}

Client::Client(ClientInit init, std::shared_ptr<Console> console) : ClientTCP(init.ip, init.portTcp, console), ClientUDP(init.ip, init.portUdp, console)
{
}

Client::~Client()
{
}