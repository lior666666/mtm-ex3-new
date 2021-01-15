#ifndef ONE_TIME_EVENT_H
#define ONE_TIME_EVENT_H
#include "event_container.h"
namespace mtm{
    template<class EventType>
    class OneTimeEvent : public EventContainer 
    {
        DateWrap event_date; 
        std::string event_name; 
        public:
        OneTimeEvent<EventType>(DateWrap date, std::string name): EventContainer(), event_date(date) ,event_name(name)
        { 
            events_list.addElement(EventType(event_date, event_name).clone()); 
        }
        ~ OneTimeEvent<EventType>()
        {
            PriorityQueue<BaseEvent*>* current_pointer = events_list.getIterator();
            BaseEvent* pointer; 
            while(current_pointer != NULL)
            {
                pointer = events_list.popTop();
                delete pointer; 
                current_pointer = events_list.getIterator();
            } 
        }
        void add(const BaseEvent& event) override
        {
            throw NotSupported(); 
        }
    };
}
#endif