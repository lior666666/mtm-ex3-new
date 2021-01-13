#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include "../partA/exceptions.h"
#include "generic_queue.h"
#include "../partA/date_wrap.h"
#include <string.h>

namespace mtm{
    class BaseEvent{ 
    protected:
        char* event_name;
        DateWrap event_date;
        PriorityQueue<long> event_participants;
    public:
        BaseEvent(DateWrap date, char* name);
        virtual void registerParticipant(const long student) = 0;
        void unregisterParticipant(const long student);
        std::ostream& printShort(std::ostream& out) const;
        std::ostream& printLong(std::ostream& out) const;
        const DateWrap& getDate(); 
        virtual BaseEvent* clone() const = 0;
    };
    void isVaildStudent(const long student);
}
#endif