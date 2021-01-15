#include "closed_event.h"
namespace mtm
{
    //#1
    //priority queue will be initialized by default constructor
    ClosedEvent::ClosedEvent(DateWrap date, std::string name) : 
        BaseEvent(date, name) {
    }
    ClosedEvent::ClosedEvent(const ClosedEvent& event) : BaseEvent(event), event_invited(PriorityQueue<int>(event.event_invited)) 
        {}
    //#2
    void ClosedEvent::addInvitee(const int student)
    {
        isVaildStudent(student);
        if (event_invited.containsElement(student))
        {
            throw AlreadyInvited();
        }
        event_invited.addElement(student);
    }

    //#3
    void ClosedEvent::registerParticipant(const int student)
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

    //#4
    BaseEvent* ClosedEvent::clone() const
    {
        /*
        DateWrap copied_date = DateWrap(this->event_date);
        std::string copied_name = event_name;
        ClosedEvent* copied_event = NULL;
        *copied_event = ClosedEvent(copied_date, copied_name);
        copied_event->event_participants = PriorityQueue<int>(this->event_participants);
        copied_event->event_invited = PriorityQueue<int>(this->event_invited);
        return copied_event;*/
        return new ClosedEvent(*this);
    }
}