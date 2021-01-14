#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_
#include "base_event.h"

namespace mtm{
    class OpenEvent : public BaseEvent{ 
    public:
        OpenEvent() = default;
        OpenEvent(DateWrap date, std::string name);
        ~OpenEvent() {}
        BaseEvent* clone() const override;
    };
}
#endif