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
    BaseEvent* Schedule::findEvent(const DateWrap date, const std::string name) const
    {
        PriorityQueue<BaseEvent*> temp = events_board; // because it's const we had to make a temp copy. 
        PriorityQueue<BaseEvent*>* event_pointer = temp.getIterator();
        while (event_pointer != NULL)
        {
            BaseEvent* current_event = temp.getData();
            if (current_event->getName().compare(name) == 0 && current_event->getDate() == date)
            {
                return current_event;
            }
            event_pointer = temp.getNext();
        }
        throw EventDoesNotExist();
        return NULL; 
    }

    bool Schedule::isContains(EventContainer* event_container)
    {
        EventContainer::EventIterator temp_pointer = event_container->begin();
        EventContainer::EventIterator ending = event_container->end();
        while (temp_pointer != ending)
        {
            PriorityQueue<BaseEvent*>* current_schedule_pointer = events_board.getIterator();
            BaseEvent& event = *temp_pointer; 
            while(current_schedule_pointer !=NULL)
            {
                if (event.isEqual(events_board.getData()))
                {
                    delete event_container;
                    throw EventAlreadyExists();
                    return true; 
                }
                current_schedule_pointer = events_board.getNext();
            }
            ++temp_pointer;
        }
        return false; 
    }   

    void Schedule::addEvents(const EventContainer& event_container_main)
    {
        EventContainer* event_container = event_container_main.clone();
        if(!isContains(event_container))
        {
            EventContainer::EventIterator event_pointer = event_container->begin();
            EventContainer::EventIterator ending = event_container->end();
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
        delete event_container; 
    }

    void Schedule::registerToEvent(const DateWrap date, const std::string name, const long student)
    {
        BaseEvent* needed_event = findEvent(date, name);
        if(needed_event != NULL) // MAYBEE WE CAN REMOVE THAT SINCE WE THROWING AN EXECPTION IN FIND EVENT. 
        {
            needed_event->registerParticipant(student);
        }
    }

    void Schedule::unregisterFromEvent(const DateWrap date, const std::string name, const long student)
    {
        BaseEvent* needed_event = findEvent(date, name);
        if(needed_event != NULL) // MAYBEE WE CAN REMOVE THAT SINCE WE THROWING AN EXECPTION IN FIND EVENT. 
        {
            needed_event->unregisterParticipant(student);
        }
    }
    
    void Schedule::printAllEvents() const
    {
        PriorityQueue<BaseEvent*> temp = events_board; // because it's const we had to make a temp copy. 
        PriorityQueue<BaseEvent*>* event_pointer = temp.getIterator();
        while (event_pointer != NULL)
        {
            BaseEvent* current_event = temp.getData();
            current_event->printShort(std::cout);
            std::cout << std::endl;
            event_pointer = temp.getNext();
        }
    }

    void Schedule::printMonthEvents(const int month, const int year) const
    {
        PriorityQueue<BaseEvent*> temp = events_board; // because it's const we had to make a temp copy. 
        PriorityQueue<BaseEvent*>* event_pointer = temp.getIterator();
        while (event_pointer != NULL)
        {
            BaseEvent* current_event = temp.getData();
            DateWrap date = current_event->getDate();
            if(date.month() == month && date.year() == year)
            {
                current_event->printShort(std::cout);
                std::cout << std::endl;
            }
            event_pointer =temp.getNext();
        }
    }

    void Schedule::printEventDetails(const DateWrap date, const std::string name) const
    {
        BaseEvent* needed_event = findEvent(date, name);
        needed_event->printLong(std::cout);
        std::cout << std::endl;
    }

}