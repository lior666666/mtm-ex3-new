#include "schedule.h"
#include "../partB/event_container.h"

namespace mtm{
    Schedule::~Schedule()
    {
        PriorityQueue<BaseEvent*>* current_pointer = events_board.getIterator();
        BaseEvent* pointer; 
        while(current_pointer != NULL)
        {
            pointer = events_board.popTop();
            delete pointer; 
            current_pointer = events_board.getIterator();
        } 
    }
    void Schedule::addEvents(EventContainer& event_container)
    {
        if(!isContains(event_container))
        {
            EventContainer::EventIterator event_pointer = event_container.begin();
            EventContainer::EventIterator ending = event_container.end();
            while (event_pointer != ending)
            {
                PriorityQueue<BaseEvent*>* current_schedule_pointer = events_board.getIterator(); 
                BaseEvent& event = *event_pointer; 
                BaseEvent* add_event = event.clone();
                if(events_board.getSize() == 0)
                {
                    events_board.addElement(add_event); 
                }
                else
                {
                    if(event.isSmaller(events_board.getData()))
                    {
                        events_board.addElement(add_event, &events_board); 
                    }
                    else
                    {   
                        PriorityQueue<BaseEvent*>* previous_schedule_pointer = events_board.getIterator(); 
                        current_schedule_pointer = events_board.getNext();
                        while(current_schedule_pointer !=NULL)
                        {
                            if(event.isSmaller(events_board.getData()))
                            {
                                events_board.addElement(add_event, previous_schedule_pointer); 
                                break;
                            }
                            previous_schedule_pointer = current_schedule_pointer;
                            current_schedule_pointer = events_board.getNext();
                        }
                        if(current_schedule_pointer == NULL)
                        {
                            events_board.addElement(add_event, NULL);
                        }
                    }
                }   
                ++event_pointer;
            }
        }
    }
    bool Schedule::isContains(EventContainer& event_container)
    {
        EventContainer::EventIterator temp_pointer = event_container.begin();
        EventContainer::EventIterator ending = event_container.end();
        while (temp_pointer != ending)
        {
            PriorityQueue<BaseEvent*>* current_schedule_pointer = events_board.getIterator();
            BaseEvent& event = *temp_pointer; 
            while(current_schedule_pointer !=NULL)
            {
                if (event.isEqual(events_board.getData()))
                {
                    throw EventAlreadyExists();
                    return true; 
                }
            }
            ++temp_pointer;
        }
        return false; 
    }    
}