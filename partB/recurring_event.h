#ifndef RECURRING_EVENT_H
#define RECURRING_EVENT_H
#include "event_container.h"
namespace mtm{
    template<class EventType>
    class RecurringEvent : public EventContainer
    {
        DateWrap first_event_date; 
        std::string event_name;
        int num_event_occurrences;
        int days_event_interval; 
    public:
        RecurringEvent<EventType>(DateWrap first_date, std::string name, int num_occurrences, int days_interval) :
            EventContainer(),first_event_date(first_date) , event_name(name), 
            num_event_occurrences(num_occurrences), days_event_interval(days_interval) 
        {
            if (num_event_occurrences < 1)
            {
                throw InvalidNumber();
            }
            if (days_event_interval < 1)
            {
                throw InvalidInterval(); 
            }
            DateWrap temp_date = first_event_date; 
            events_list.addElement(EventType(temp_date, event_name).clone());
            for (int i = 1; i < num_event_occurrences; i++)
            {
                temp_date += days_event_interval;
                events_list.addElement(EventType(temp_date, event_name).clone(), NULL);
            }
        }

        /**
        * ~RecurringEvent: Destructor to destroy the class and free all the memory
        */
        ~RecurringEvent<EventType>()
        {
            PriorityQueue<BaseEvent*>* current_pointer = events_list.getIterator();
            BaseEvent* pointer; 
            while (current_pointer != NULL)
            {
                pointer = events_list.popTop();
                delete pointer; 
                current_pointer = events_list.getIterator();
            }
        } 

        /**
        * RecurringEvent: copy constructor.
        * @param container - the RecurringEvent to copy.
        */
        RecurringEvent<EventType>(const RecurringEvent<EventType>& container) :
            EventContainer(container), first_event_date(container.first_event_date), 
            event_name(container.event_name), num_event_occurrences(container.num_event_occurrences), 
            days_event_interval(container.days_event_interval)
        {
        }

        /**
        * clone: clones and allocates a new RecurringEvent as this.
        * @return
        * 	returns an adress for an EventContainer pointer.
        */    
        EventContainer* clone() const
        {
            return new RecurringEvent(*this);
        }
    };
}
#endif