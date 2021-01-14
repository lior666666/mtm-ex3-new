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
        RecurringEvent<EventType>(DateWrap first_date, std::string name, int num_occurrences, int days_interval) : EventContainer(),first_event_date(first_date) , event_name(name), 
        num_event_occurrences(num_occurrences), days_event_interval(days_interval) 
        {
            if(num_event_occurrences < 1)
            {
                throw InvalidNumber();
            }
            if(days_event_interval < 1)
            {
                throw InvalidInterval(); 
            }
            DateWrap temp_date = first_event_date; 
            BaseEvent* temp_event = EventType(temp_date, event_name);
            events_list.addElement(temp_event);
            for (int i = 0; i < num_event_occurrences; i++)
            {
                temp_date += days_event_interval; 
                BaseEvent* next_temp_event = EventType(temp_date, event_name);
                events_list.addElement(next_temp_event);
            }
        }
        void add(const BaseEvent& event) override
        {
            throw NotSupported(); 
        }

    };

}
#endif