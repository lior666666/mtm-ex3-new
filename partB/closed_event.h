#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_
#include "base_event.h"

namespace mtm{
    class ClosedEvent : public BaseEvent{
        PriorityQueue<int> event_invited;
    public:
        ClosedEvent() = default;
        ClosedEvent(DateWrap date, std::string name);
        ClosedEvent(const ClosedEvent& event);
        ~ClosedEvent() {}
        void addInvitee(const int student);
        void registerParticipant(const int student) override;
        BaseEvent* clone() const override;
    };
}
#endif

