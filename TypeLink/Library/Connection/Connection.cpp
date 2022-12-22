#include "Connection.hpp"

using namespace TypeLink;

Connection::Connection(std::shared_ptr<Console> console) : Network(console)
{
    this->_sock = -1;
    this->_sin.sin_family = AF_INET;
    this->_sin.sin_addr.s_addr = INADDR_ANY;
    this->_sin.sin_port = htons(0);
}

Connection::Connection(int sock, struct sockaddr_in sin, std::shared_ptr<Console> console) : Network(console)
{
    this->_sock = sock;
    this->_sin = sin;
}

Connection::~Connection()
{
    this->closeConnection();
    this->_console->info("Connection " + this->getIp() + ":" + std::to_string(this->getPort()) + " closed");
}

int Connection::getSocket()
{
    return this->_sock;
}

std::string Connection::getIp()
{
    return inet_ntoa(this->_sin.sin_addr);
}

uint16_t Connection::getPort()
{
    return ntohs(this->_sin.sin_port);
}

struct sockaddr_in Connection::getSockaddrIn()
{
    return this->_sin;
}

void Connection::setSocket(int sock)
{
    this->_sock = sock;
}

void Connection::setIp(std::string ip)
{
    this->_sin.sin_addr.s_addr = inet_addr(ip.c_str());
}

void Connection::setPort(uint16_t port)
{
    this->_sin.sin_port = htons(port);
}

void Connection::setAddress(struct sockaddr_in sin)
{
    this->_sin = sin;
}

void Connection::resetFdSet(fd_set *rdfd, fd_set *wdfd)
{
    FD_SET(this->_sock, rdfd);
    FD_SET(this->_sock, wdfd);
}

void Connection::closeConnection()
{
    close(this->_sock);
}