#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include "../partA/exceptions.h"
#include "generic_queue.h"
#include "../partA/date_wrap.h"
#include <string.h>

namespace mtm{
    class BaseEvent{ 
    protected:
        std::string event_name;
        DateWrap event_date;
        PriorityQueue<long> event_participants;
    public:
        BaseEvent() = default; 
        BaseEvent(DateWrap date, std::string name);
        BaseEvent(const BaseEvent& event);
        virtual ~BaseEvent() {}
        virtual void registerParticipant(const long student);
        void unregisterParticipant(const long student);
        std::ostream& printShort(std::ostream& out) const;
        std::ostream& printLong(std::ostream& out) const;
        const DateWrap& getDate() const;
        const std::string getName() const;
        const PriorityQueue<long> getParticipants() const;
        virtual BaseEvent* clone() const = 0;
        friend bool operator==(const BaseEvent& event1, const BaseEvent& event2);
        /**
        *  isSmaller: compares between 2 events and check if the first one comes before the second one by it's date or name in case dates are equal.
        * @param event2 - pointer to the second event to compare.  
        * @param this - pointer to the first event. 
        * @return
        * 	true - if the first event comes before the second one.
        * 	false - if the second event comes before the first one.
        */    
        bool isSmaller(BaseEvent* event2);
        /**
        *  isSmaller: compares between 2 events and check if they are equal. 
        * @param event2 - pointer to the second event to compare.  
        * @param this - pointer to the first event to compare. 
        * @return
        * 	true - if the first event equals to the second one by name and date.
        * 	false - if the events are not equal.
        */    
        bool isEqual(BaseEvent* event2);
    };
    void isVaildStudent(const long student);
}
#endif