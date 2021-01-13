#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_
#include "base_event.h"
#include "closed_event.h"
#include "custom_event.h"
#include "open_event.h"

namespace mtm{
    class EventContainer {
        protected:
        PriorityQueue<BaseEvent> events_list; 
        public:
          class EventIterator{
            PriorityQueue<BaseEvent>* pointer; 
            PriorityQueue<BaseEvent>* head_list; 
            public:
                EventIterator();
                ~EventIterator();
                EventIterator(const EventIterator& event_iterator);
                EventIterator& operator=(const EventIterator&);
                EventIterator& operator++();
                const BaseEvent& operator*();
                friend bool operator==(const EventIterator& event_iterator1, EventIterator& event_iterator2);
                friend bool operator!=(const EventIterator& event_iterator1, EventIterator& event_iterator2);
                friend class EventContainer; 
            };
            virtual void add(const BaseEvent& event) = 0; 
            EventIterator begin(); 
            EventIterator end(); 
    };
}
#endif