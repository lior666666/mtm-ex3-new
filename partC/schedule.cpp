#include "schedule.h"
#include "../partB/event_container.h"

namespace mtm{
    void Schedule::addEvents(EventContainer& event_container)
    {
        EventContainer::EventIterator event_pointer = event_container.begin();
        EventContainer::EventIterator last_event = event_container.end();
        while (event_pointer != last_event)
        {
            if (events_board.containsElement(&(*event_pointer)))
            {
                throw EventAlreadyExists();
            }
            ++event_pointer;
        }
        if (events_board.containsElement(&(*last_event))) // check last event
        {
            throw EventAlreadyExists();
        }
        //in this point we should add all events. need to check if the board is empty
    }
}