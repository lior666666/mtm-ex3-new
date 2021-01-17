#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_
#include "base_event.h"

namespace mtm{
    class ClosedEvent : public BaseEvent{
        PriorityQueue<long> event_invited;
    public:
        /**
        * ClosedEvent: default empty constructor. 
        */
        ClosedEvent() = default;

        /**
        * operator=: assignment operator. Takes the data from the given ClosedEvent to the current one.
        * @param closed_event - the ClosedEvent to assign.
        */
        ClosedEvent& operator=(const ClosedEvent&);

        /**
        * ClosedEvent: copy constructor.
        * @param event - the ClosedEvent to copy.
        */
        ClosedEvent(const ClosedEvent& event);

        ClosedEvent(DateWrap date, std::string name);

        /**
        * ~ClosedEvent: destructor. Free the event.
        */
        ~ClosedEvent() {}

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