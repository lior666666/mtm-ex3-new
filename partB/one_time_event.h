#ifndef ONE_TIME_EVENT_H
#define ONE_TIME_EVENT_H
#include "event_container.h"
namespace mtm{
    template<class EventType>
    class OneTimeEvent : public EventContainer 
    {
        DateWrap event_date; 
        char* event_name; 
        public:
        OneTimeEvent<EventType>(DateWrap date, char* name): EventContainer(), event_date(date) ,event_name(name)) 
        {   
           events_list.addElement(EventType(event_date, event_name));  
        }
        void add(BaseEvent& event) override
        {
            throw NotSupported(); 
        }
    };
}
#endif