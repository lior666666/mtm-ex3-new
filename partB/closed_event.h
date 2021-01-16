#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_
#include "base_event.h"

namespace mtm{
    class ClosedEvent : public BaseEvent{
        PriorityQueue<long> event_invited;
    public:
        ClosedEvent() = default;
        ClosedEvent& operator=(const ClosedEvent&);
        ClosedEvent(const ClosedEvent& event);
        ClosedEvent(DateWrap date, std::string name);
        ~ClosedEvent() {}
        const PriorityQueue<long> getInvited() const;
        void addInvitee(const long student);
        void registerParticipant(const long student) override;
        BaseEvent* clone() const override;
    };
}
#endif