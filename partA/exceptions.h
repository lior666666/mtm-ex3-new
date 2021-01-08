#include <iostream> 
namespace mtm
{
    class Exception : public std::exception 
    {
        public:
            class NegativeDays{};
            class InvalidDate{}; 
            class AllocationFailed{}; 
    };
}