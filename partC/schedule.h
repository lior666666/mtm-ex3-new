#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "../partB/event_container.h"

namespace mtm{
    class Schedule {
        PriorityQueue<BaseEvent*> events_board; 
    public:
        Schedule() = default;
        void addEvents(EventContainer&);
        void registerToEvent(const DateWrap date, const std::string name, const long student);
        void unregisterFromEvent(const DateWrap date, const std::string name, const long student);
        void printAllEvents();
        void printMonthEvents(const int month, const int year);
        void printEventDetails(const DateWrap date, const std::string name);
        template<typename Predicate>
        void printSomeEvents(Predicate print_condition, bool verbose = false)
        {
            PriorityQueue<BaseEvent*>* event_pointer = events_board.getIterator();
            while (event_pointer != NULL)
            {
                BaseEvent* current_event = (*event_pointer).getData();
                if (print_condition(*current_event) == true)
                {
                    if (verbose == true)
                    {
                        (*current_event).printLong(std::cout);
                        std::cout << std::endl;
                    }
                    else
                    {
                        (*current_event).printShort(std::cout);
                        std::cout << std::endl;
                    }
                    
                }
                event_pointer = event_pointer->getNext();
            }
        }
    };
}
#endif