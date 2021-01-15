#include "base_event.h"
namespace mtm
{
    //#1
    //priority queue will be initialized by default constructor
    BaseEvent::BaseEvent(DateWrap date, std::string name) : 
        event_name(name), event_date(date) {
    }
    BaseEvent::BaseEvent(const BaseEvent& event) : 
        event_name(event.event_name), event_date(DateWrap(event.event_date)), 
        event_participants(PriorityQueue<long>(event.event_participants)) 
        {
    }
    //#2
    void BaseEvent::registerParticipant(const long student)
    {
        isVaildStudent(student);
        if (event_participants.containsElement(student))
        {
            throw AlreadyRegistered();
        }
        event_participants.addElement(student);
    }

    //#3
    void BaseEvent::unregisterParticipant(const long student)
    {
        isVaildStudent(student);
        if (!event_participants.removeElement(student))
        {
            throw NotRegistered();
        }
    }

    //#4
    std::ostream& BaseEvent::printShort(std::ostream& out) const
    {
        out << event_name << ' ' << event_date << std::endl; 
        return out;
    }

    //#5
    std::ostream& BaseEvent::printLong(std::ostream& out) const
    {
        this->printShort(out);
        this->event_participants.printPriorityQueue(out);
        return out;
    }

    //#6
    const DateWrap& BaseEvent::getDate() const
    {
        return event_date;
    }

    //#7
    //******pure virtual*****

    //#8
    bool operator==(const BaseEvent& event1, const BaseEvent& event2)
    {
        return event1.event_date == event2.event_date && event1.event_name.compare(event2.event_name) == 0;
    }

    //#9
    bool operator<(const BaseEvent& event1, const BaseEvent& event2)
    {
        if (event1.event_date == event2.event_date)
        {
            return event1.event_name.compare(event2.event_name) < 0;
        }
        return event1.event_date < event2.event_date;
    }

    //#10
    void isVaildStudent(const long student)
    {
        if (student < 1 || student > 1234567890)
        {
            throw InvalidStudent();
        }
    }
    const std::string BaseEvent::getName() const
    {
        return event_name;
    }
}