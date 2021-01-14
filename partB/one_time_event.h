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
        void add(const BaseEvent& event) override
        {
            throw NotSupported(); 
        }
    };
}
#endif