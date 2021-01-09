#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <iostream> 
#include <exception> 

namespace mtm
{
    class Exception : public std::exception {};
    class NegativeDays : public Exception{};
    class InvalidDate : public Exception{}; 
    class AllocationFailed : public Exception{}; 
}
#endif