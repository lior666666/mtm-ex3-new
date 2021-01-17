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
        OneTimeEvent<EventType>() = default;

        OneTimeEvent<EventType>(const OneTimeEvent<EventType>& event) = default;

        OneTimeEvent<EventType>& operator=(const OneTimeEvent<EventType>&) = default;
        
        OneTimeEvent<EventType>(DateWrap date, std::string name) :
            EventContainer(), event_date(date) ,event_name(name)
        { 
           events_list.addElement(EventType(event_date, event_name).clone()); 
        }

        /**
        * ~OneTimeEvent: destructor. Destroy the class and free all the memory.
        */
        ~OneTimeEvent<EventType>()
        {
            BaseEvent* pointer; 
            pointer = events_list.popTop();
            delete pointer; 
        }

        /**
        *  clone: clones and allocates a new OneTimeEvent as this.
        * @return
        * 	returns an adress for an EventContainer pointer.
        */    
        EventContainer* clone() const
        {
            return new OneTimeEvent(*this);
        }
    };
}
#endif