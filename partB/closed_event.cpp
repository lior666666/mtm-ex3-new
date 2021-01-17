#include "closed_event.h"
namespace mtm
{
    ClosedEvent::ClosedEvent(DateWrap date, std::string name) : 
        BaseEvent(date, name) {
    }

    void ClosedEvent::addInvitee(const long student)
    {
        isVaildStudent(student);
        if (event_invited.containsElement(student))
        {
            throw AlreadyInvited();
        }
        event_invited.addElement(student);
    }

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

    const PriorityQueue<long> ClosedEvent::getInvited() const
    {
        return event_invited;
    }

    ClosedEvent::ClosedEvent(const ClosedEvent& event) : 
        BaseEvent(event), event_invited(PriorityQueue<long>(event.event_invited)) 
    {
    }

    BaseEvent* ClosedEvent::clone() const
    {
        return new ClosedEvent(*this);
    }
}