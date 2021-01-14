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
        virtual ~BaseEvent() {}
        virtual void registerParticipant(const long student);
        void unregisterParticipant(const long student);
        std::ostream& printShort(std::ostream& out) const;
        std::ostream& printLong(std::ostream& out) const;
        const DateWrap& getDate() const;
        virtual BaseEvent* clone() const = 0;
        friend bool operator==(const BaseEvent& event1, const BaseEvent& event2);
        friend bool operator<(const BaseEvent& event1, const BaseEvent& event2);
    };
    void isVaildStudent(const long student);
}
#endif