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
    //******pure virtual*****

    //#7
    void isVaildStudent(const long student)
    {
        if (student < 1 || student > 1234567890)
        {
            throw InvalidStudent();
        }
    }
}