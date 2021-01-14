#include "event_container.h"
namespace mtm{

    EventContainer::EventIterator& EventContainer::EventIterator::operator++()
    {
        pointer = (*head_list).getNext();
        return *this;
    }
    BaseEvent& EventContainer::EventIterator::operator*()
    {
        BaseEvent* temp_event = (*head_list).getData();
        return *temp_event; 
    }
    bool operator==(const EventContainer::EventIterator& event_iterator1, const EventContainer::EventIterator& event_iterator2)
    {
        return event_iterator1.pointer == event_iterator2.pointer;
    }
    bool operator!=(const EventContainer::EventIterator& event_iterator1, const EventContainer::EventIterator& event_iterator2)
    {
        return event_iterator1.pointer != event_iterator2.pointer;
    }
    EventContainer::EventIterator EventContainer::begin()
    {
        EventContainer::EventIterator temp;
        temp.pointer = events_list.getIterator();
        temp.head_list = &events_list; 
        return temp; 
    }
    EventContainer::EventIterator EventContainer::end()
    {
        EventContainer::EventIterator temp;
        temp.pointer = NULL;
        temp.head_list = &events_list; 
        return temp;   
    }
}