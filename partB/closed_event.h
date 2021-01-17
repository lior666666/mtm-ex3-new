#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_
#include "base_event.h"

namespace mtm{
    class ClosedEvent : public BaseEvent{
        PriorityQueue<long> event_invited;
    public:
        ClosedEvent() = default;

        ClosedEvent(const ClosedEvent& event) = default;

        ClosedEvent& operator=(const ClosedEvent&) = default;

        ~ClosedEvent() = default;

        ClosedEvent(DateWrap date, std::string name);

        /**
        * getInvited: Get the invited participants list of the current event.
        * @return
        * 	The invited participants list of the current event.
        */
        const PriorityQueue<long> getInvited() const;

        void addInvitee(const long student);

        void registerParticipant(const long student) override;
        
        BaseEvent* clone() const override;
    };
}
#endif