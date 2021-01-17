#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_
#include "base_event.h"

namespace mtm{
    class OpenEvent : public BaseEvent{ 
    public:
        /**
        * OpenEvent: default empty constructor. 
        */
        OpenEvent() = default;

        /**
        * OpenEvent: copy constructor.
        * @param event - the OpenEvent to copy.
        */
        OpenEvent(const OpenEvent& event);

        OpenEvent(DateWrap date, std::string name);

        /**
        * ~OpenEvent: destructor. Free the event.
        */
        ~OpenEvent() {}

        BaseEvent* clone() const override;
    };
}
#endif