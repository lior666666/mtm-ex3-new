#include "base_event.h"

const char SPACE = ' ';
const int MINIMUN_STUDENT_ID = 1;
const int MAXMUN_STUDENT_ID = 1234567890;

namespace mtm
{
    BaseEvent::BaseEvent(DateWrap date, std::string name) : 
        event_name(std::string(name)), event_date(DateWrap(date)) {
    }

    void BaseEvent::registerParticipant(const long student)
    {
        isVaildStudent(student);
        if (event_participants.containsElement(student))
        {
            throw AlreadyRegistered();
        }
        event_participants.addElement(student);
    }

    void BaseEvent::unregisterParticipant(const long student)
    {
        isVaildStudent(student);
        if (!event_participants.removeElement(student))
        {
            throw NotRegistered();
        }
    }

    std::ostream& BaseEvent::printShort(std::ostream& out) const
    {
        out << event_name << SPACE << event_date << std::endl; 
        return out;
    }

    std::ostream& BaseEvent::printLong(std::ostream& out) const
    {
        this->printShort(out);
        this->event_participants.printPriorityQueue(out);
        return out;
    }

    const DateWrap& BaseEvent::getDate() const
    {
        return event_date;
    }

    const std::string BaseEvent::getName() const
    {
        return event_name;
    }

    const PriorityQueue<long> BaseEvent::getParticipants() const
    {
        return event_participants;
    }

    bool operator==(const BaseEvent& event1, const BaseEvent& event2)
    {
        return event1.event_date == event2.event_date && event1.event_name.compare(event2.event_name) == 0;
    }

    bool BaseEvent::isSmaller(BaseEvent* event2)
    {
        if (event_date == event2->event_date)
        {
            return event_name.compare(event2->event_name) < 0;
        }
        return event_date < event2->event_date;
    }

    bool BaseEvent::isEqual(BaseEvent* event2)
    {
        return event_date == event2->event_date && event_name.compare(event2->event_name) == 0; 
    }

    void isVaildStudent(const long student)
    {
        if (student < MINIMUN_STUDENT_ID || student > MAXMUN_STUDENT_ID)
        {
            throw InvalidStudent();
        }
    }
}