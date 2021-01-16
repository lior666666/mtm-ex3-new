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
        ~OneTimeEvent<EventType>()
        {
            BaseEvent* pointer; 
            pointer = events_list.popTop();
            delete pointer; 
        }
        OneTimeEvent<EventType>(const  OneTimeEvent<EventType>& container): EventContainer(container), event_date(container.event_date),event_name(container.event_name)
        {}
        EventContainer* clone() const
        {
            return new OneTimeEvent(*this);
        }
    };
}
#endif