#include "event_container.h"
namespace mtm{

    EventContainer::EventContainer(){} // made by default generic list constructor. 
    EventContainer::EventIterator::EventIterator()
    {
        pointer = NULL; 
        head_list = NULL; 
    } 
    EventContainer::EventIterator& EventContainer::EventIterator::operator++()
    {
        pointer = (*head_list).getNext();
        return *this;
    }
    const BaseEvent& EventContainer::EventIterator::operator*()
    {
        return (*head_list).getData(); 
    }
    bool operator==(const EventContainer::EventIterator& event_iterator1, EventContainer::EventIterator& event_iterator2)
    {
        return event_iterator1.pointer == event_iterator2.pointer;
    }
    bool operator!=(const EventContainer::EventIterator& event_iterator1, EventContainer::EventIterator& event_iterator2)
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