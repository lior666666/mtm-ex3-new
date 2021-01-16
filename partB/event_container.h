#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_
#include "base_event.h"
#include "closed_event.h"
#include "custom_event.h"
#include "open_event.h"

namespace mtm{
    class EventContainer {
        protected:
        PriorityQueue<BaseEvent*> events_list; 
        public:
            EventContainer() = default;
            virtual ~EventContainer() {}
            virtual void add(const BaseEvent& event) = 0;
            class EventIterator{
                PriorityQueue<BaseEvent*>* pointer; 
                PriorityQueue<BaseEvent*>* head_list;
            public:
                EventIterator() = default;
                virtual ~EventIterator(){};
                EventIterator(const EventIterator& event_iterator);
                EventIterator& operator=(const EventIterator&);
                EventIterator& operator++();
                BaseEvent& operator*();
                friend bool operator==(const EventIterator& event_iterator1, const EventIterator& event_iterator2);
                friend bool operator!=(const EventIterator& event_iterator1, const EventIterator& event_iterator2);
                friend class EventContainer; 
            };
            EventContainer::EventIterator begin();
            EventContainer::EventIterator end(); 
    };
}
#endif