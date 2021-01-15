#include "open_event.h"
namespace mtm
{
    //#1
    //priority queue will be initialized by default constructor
    OpenEvent::OpenEvent(DateWrap date, std::string name) : 
        BaseEvent(date, name) {
    }

    OpenEvent& OpenEvent::operator=(const OpenEvent& event)
    {
        if (this == &event) {
		    return *this;
        }
        event_name.assign((std::string)event.getName());
        event_date = event.getDate();
        event_participants = event.getParticipants();
        return *this;
    }

    //#2
    BaseEvent* OpenEvent::clone() const
    {
        DateWrap copied_date = DateWrap(this->event_date);
        std::string copied_name = this->event_name;
        OpenEvent* copied_event = NULL;
        *copied_event = OpenEvent(copied_date, copied_name);
        copied_event->event_participants = PriorityQueue<long>(this->event_participants);
        return copied_event;
    }
}