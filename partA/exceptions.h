#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <iostream> 
#include <exception> 

namespace mtm
{
    class Exception : public std::exception {};
    //partA
    class NegativeDays : public Exception{};
    class InvalidDate : public Exception{}; 
    class AllocationFailed : public Exception{};
    //partB
    class NotRegistered : public Exception{};
    class InvalidStudent : public Exception{};
    class AlreadyRegistered : public Exception{};
    class AlreadyInvited : public Exception{};
    class RegistrationBlocked : public Exception{};
}
#endif