#include "closed_event.h"
namespace mtm
{
    //#1
    //priority queue will be initialized by default constructor
    ClosedEvent::ClosedEvent(DateWrap date, std::string name) : 
        BaseEvent(date, name) {
    }

    //#2
    void ClosedEvent::addInvitee(const long student)
    {
        isVaildStudent(student);
        if (event_invited.containsElement(student))
        {
            throw AlreadyInvited();
        }
        event_invited.addElement(student);
    }

    //#3
    void ClosedEvent::registerParticipant(const long student)
    {
        isVaildStudent(student);
        if (!event_invited.containsElement(student))
        {
            throw RegistrationBlocked();
        }
        if (event_participants.containsElement(student))
        {
            throw AlreadyRegistered();
        }
        event_participants.addElement(student);
    }

    /*//#4
    BaseEvent* ClosedEvent::clone() const
    {
        DateWrap copied_date = DateWrap(this->event_date);
        std::string copied_name = event_name;
        ClosedEvent* copied_event = NULL;
        *copied_event = ClosedEvent(copied_date, copied_name);
        copied_event->event_participants = PriorityQueue<long>(this->event_participants);
        copied_event->event_invited = PriorityQueue<long>(this->event_invited);
        return copied_event;
    }*/

    /*ClosedEvent& ClosedEvent::operator=(const ClosedEvent& event)
    {
        if (this == &event) {
		    return *this;
        }
        event_name = event.getName();
        event_date = event.getDate();
        event_participants = event.getParticipants();
        event_invited = event.getInvited();
        return *this;
    }*/

    //#8
    const PriorityQueue<long> ClosedEvent::getInvited() const
    {
        return event_invited;
    }

    ClosedEvent::ClosedEvent(const ClosedEvent& event) : 
        BaseEvent(event), event_invited(PriorityQueue<long>(event.event_invited)) 
    {
    }

    //#2
    BaseEvent* ClosedEvent::clone() const
    {
        return new ClosedEvent(*this);
    }
}