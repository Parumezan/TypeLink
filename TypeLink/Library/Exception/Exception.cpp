#include "Exception.hpp"

using namespace TypeLink;

Exception::Exception(std::string const &msg)
{
    this->_msg = msg;
}

Exception::~Exception() throw()
{
}

const char *Exception::what() const throw()
{
    return this->_msg.c_str();
}