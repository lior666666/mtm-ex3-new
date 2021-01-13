#include "base_event.h"
namespace mtm
{
    //#1
    //priority queue will be initialized by default constructor
    BaseEvent::BaseEvent(DateWrap date, char* name) : 
        event_name(name), event_date(date) {
    }

    //#2
    //******pure virtual*****

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
        return event1.event_date == event2.event_date && strcmp(event1.event_name, event2.event_name) == 0;
    }

    //#9
    bool operator<(const BaseEvent& event1, const BaseEvent& event2)
    {
        if (event1.event_date == event2.event_date)
        {
            return strcmp(event1.event_name, event2.event_name) < 0;
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
}