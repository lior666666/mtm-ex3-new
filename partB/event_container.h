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
            EventContainer(const EventContainer& container);
            virtual void add(const BaseEvent& event);
            /** ~EventContainer: Destructor to destroy the class and free all the memory */
            virtual ~EventContainer() {}
            class EventIterator{
                /** pointer that will move through the events. */
                PriorityQueue<BaseEvent*>* pointer; 
                /** pointer to the head of the events list to know through which list to move and to keep it.*/
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
            /** added a virtual clone function to clone diferent event containers. */
            virtual EventContainer* clone() const = 0;
    };
}
#endif