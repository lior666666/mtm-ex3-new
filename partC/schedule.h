#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "../partB/event_container.h"

namespace mtm{
    class Schedule {
        PriorityQueue<BaseEvent*> events_board; 

    public:
        Schedule() = default;
        ~Schedule();
        BaseEvent* findEvent(const DateWrap date, const std::string name) const;
        void addEvents(const EventContainer& event_container);
        /**
        *  isContains: checks if one of the events inside the EventContainer with same name and date also insite the schedule. 
        *
        * @param event_container - pointer to an EventContainer. 
        * @return
        * 	true - if there is event from the event container that is also in schedule.
        * 	false - if there are no events at all from the event container that are also inside schedule.
        */
        bool isContains(EventContainer* event_container); 
        void registerToEvent(const DateWrap date, const std::string name, const long student);
        void unregisterFromEvent(const DateWrap date, const std::string name, const long student);
        void printAllEvents() const;
        void printMonthEvents(const int month, const int year) const;
        void printEventDetails(const DateWrap date, const std::string name) const;
        template<typename Predicate>
        void printSomeEvents(Predicate print_condition, bool verbose = false) const
        {
            PriorityQueue<BaseEvent*> temp = events_board;
            PriorityQueue<BaseEvent*>* event_pointer = temp.getIterator();
            while (event_pointer != NULL)
            {
                BaseEvent* current_event = temp.getData();
                if(print_condition(*current_event) == true)
                {
                    if (verbose == true)
                    {
                        current_event->printLong(std::cout);
                        std::cout << std::endl;
                    }
                    else
                    {
                        current_event->printShort(std::cout);
                        std::cout << std::endl;
                    }
                    
                }
                event_pointer = temp.getNext();
            }
        }
    };
}
#endif