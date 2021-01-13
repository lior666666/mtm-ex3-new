#ifndef RECURRING_EVENT_H
#define RECURRING_EVENT_H
#include "event_container.h"
namespace mtm{

    template<class EventType>
    class RecurringEvent : public EventContainer
    {
        DateWrap first_date; 
        char* event_name;
        int num_occurrences;
        int days_interval; 
    };
}