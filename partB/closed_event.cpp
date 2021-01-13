#include "closed_event.h"
namespace mtm
{
    //#1
    //priority queue will be initialized by default constructor
    ClosedEvent::ClosedEvent(DateWrap date, char* name) : 
        BaseEvent(date, name) {
    }

    //#2
    void ClosedEvent::addInvitee(const long student)
    {
        isVaildStudent(student);
        if (!event_invited.addElement(student))
        {
            throw AlreadyInvited();
        }
    }

    //#3
    void ClosedEvent::registerParticipant(const long student)
    {
        isVaildStudent(student);
        if (!event_invited.containsElement(student))
        {
            throw RegistrationBlocked();
        }
        if (!event_participants.addElement(student))
        {
            throw AlreadyRegistered();
        }
    }

    //#4
    BaseEvent* ClosedEvent::clone() const
    {
        DateWrap copied_date = DateWrap(this->event_date);
        char* copied_name = new char[strlen(this->event_name)];
        strcpy(copied_name, this->event_name);
        ClosedEvent* copied_event = new ClosedEvent(copied_date, copied_name);
        copied_event->event_participants = *(new PriorityQueue<long>(this->event_participants));
        copied_event->event_invited = *(new PriorityQueue<long>(this->event_invited));
        return copied_event;
    }
}