#include "event_container.h"
namespace mtm{
    EventContainer::EventContainer(const EventContainer& container) 
    {

        PriorityQueue<BaseEvent*> container_list = container.events_list;
        PriorityQueue<BaseEvent*>* current_pointer = container_list.getIterator();
        BaseEvent* new_event = container_list.getData()->clone(); 
        events_list.addElement(new_event); // for the first element when list is still empty we need to use the first type function. 
        current_pointer = container_list.getNext();
        while(current_pointer!=NULL)
        {
            BaseEvent* new_next_event = container_list.getData()->clone(); 
            events_list.addElement(new_next_event);
            current_pointer = container_list.getNext();
        }
    }
    EventContainer::EventIterator::EventIterator(const EventIterator& event_iterator) :
        pointer(event_iterator.pointer), head_list(event_iterator.head_list)
    {

    }
    EventContainer::EventIterator& EventContainer::EventIterator::operator=(const EventIterator& iterator)
    {
        if (this == &iterator) {
            return *this;
        }
        pointer = iterator.pointer;
        head_list = iterator.head_list;
        return *this;
    }
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
    void EventContainer::add(const BaseEvent& event)
        {
            throw NotSupported(); 
        }
}