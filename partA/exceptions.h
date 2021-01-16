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
    class AllocationFailed : public Exception{}; // ****replace it!!!
    //partB
    class NotRegistered : public Exception{};
    class InvalidStudent : public Exception{};
    class AlreadyRegistered : public Exception{};
    class AlreadyInvited : public Exception{};
    class RegistrationBlocked : public Exception{};
    class NotSupported : public Exception{};
    class DateMismatch : public Exception{};
    class InvalidNumber : public Exception{};
    class InvalidInterval : public Exception{};
    //partC
    class EventAlreadyExists : public Exception{};
    class EventDoesNotExist : public Exception{};
    //dry
    class BadInput : public Exception{};
}
#endif