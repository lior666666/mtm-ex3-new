#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_
#include "base_event.h"

namespace mtm{
    class OpenEvent : public BaseEvent{ 
    public:
        OpenEvent() = default;
        //OpenEvent& operator=(const OpenEvent&);
        OpenEvent(const OpenEvent& event);
        OpenEvent(DateWrap date, std::string name);
        ~OpenEvent() {}
        BaseEvent* clone() const override;
    };
}
#endif