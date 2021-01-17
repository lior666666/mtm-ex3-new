#include "open_event.h"
namespace mtm
{
    OpenEvent::OpenEvent(DateWrap date, std::string name) : 
        BaseEvent(date, name) {
    }

    OpenEvent::OpenEvent(const OpenEvent& event) : 
        BaseEvent(event) 
        {
    }
    
    BaseEvent* OpenEvent::clone() const
    {
        return new OpenEvent(*this);
    }
}