#include "schedule.h"
#include "../partB/event_container.h"

namespace mtm{

    BaseEvent* findEvent(PriorityQueue<BaseEvent*> events_board, const DateWrap date, const std::string name)
    {
        PriorityQueue<BaseEvent*>* event_pointer = events_board.getIterator();
        while (event_pointer != NULL)
        {
            BaseEvent* current_event = (*event_pointer).getData();
            if ((*current_event).getName() == name && (*current_event).getDate() == date)
            {
                return current_event;
            }
            event_pointer = event_pointer->getNext();
        }
        throw EventDoesNotExist();
    }

    void Schedule::addEvents(EventContainer& event_container)
    {
    }

    void Schedule::registerToEvent(const DateWrap date, const std::string name, const long student)
    {
        (*findEvent(events_board, date, name)).registerParticipant(student);
    }

    void Schedule::unregisterFromEvent(const DateWrap date, const std::string name, const long student)
    {
        (*findEvent(events_board, date, name)).unregisterParticipant(student);
    }
    
    void Schedule::printAllEvents()
    {
        PriorityQueue<BaseEvent*>* event_pointer = events_board.getIterator();
        while (event_pointer != NULL)
        {
            BaseEvent* current_event = (*event_pointer).getData();
            (*current_event).printShort(std::cout);
            std::cout << std::endl;
            event_pointer = event_pointer->getNext();
        }
    }

    void Schedule::printMonthEvents(const int month, const int year)
    {
        PriorityQueue<BaseEvent*>* event_pointer = events_board.getIterator();
        while (event_pointer != NULL)
        {
            BaseEvent* current_event = (*event_pointer).getData();
            DateWrap date = (*current_event).getDate();
            if (date.month() == month && date.year() == year)
            {
                (*current_event).printShort(std::cout);
                std::cout << std::endl;
            }
            event_pointer = event_pointer->getNext();
        }
    }

    void Schedule::printEventDetails(const DateWrap date, const std::string name)
    {
        (*findEvent(events_board, date, name)).printLong(std::cout);
        std::cout << std::endl;
    }
}