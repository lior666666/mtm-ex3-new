#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_
#include "base_event.h"

namespace mtm{
    class OpenEvent : public BaseEvent{ 
    public:
        OpenEvent() = default;

        OpenEvent(const OpenEvent& event) = default;

        OpenEvent& operator=(const OpenEvent&) = default;

        ~OpenEvent() = default;

        OpenEvent(DateWrap date, std::string name);

        BaseEvent* clone() const override;
    };
}
#endif