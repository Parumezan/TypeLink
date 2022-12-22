#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include "Includes.hpp"

namespace TypeLink
{
    class Exception : public std::exception
    {
        private:
            std::string _msg;

        public:
            Exception(std::string const &msg);
            ~Exception() throw();
            const char *what() const throw();
    };
} // namespace TypeLink

#endif /* !EXCEPTION_HPP_ */