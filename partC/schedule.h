#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "../partB/event_container.h"

namespace mtm{
    class Schedule {
        PriorityQueue<BaseEvent*> events_board; 
    public:
        Schedule() = default;
        void addEvents(EventContainer&);
    };
}
#endif