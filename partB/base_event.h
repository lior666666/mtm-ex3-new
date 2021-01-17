#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include "../partA/exceptions.h"
#include "generic_queue.h"
#include "../partA/date_wrap.h"
#include <string.h>

namespace mtm{
    class BaseEvent{ 
    protected:
        std::string event_name;
        DateWrap event_date;
        PriorityQueue<long> event_participants;
    public:
        BaseEvent() = default;

        BaseEvent(const BaseEvent& event) = default;

        BaseEvent& operator=(const BaseEvent&) = default;

        virtual ~BaseEvent() = default;

        BaseEvent(DateWrap date, std::string name);

        virtual void registerParticipant(const long student);

        void unregisterParticipant(const long student);

        std::ostream& printShort(std::ostream& out) const;

        std::ostream& printLong(std::ostream& out) const;

        /**
        * getDate: Get the date of the current event.
        * @return
        * 	The date of the current event.
        */
        const DateWrap& getDate() const;

        /**
        * getName: Get the name of the current event.
        * @return
        * 	The name of the current event.
        */
        const std::string getName() const;

        /**
        * getParticipants: Get the participants list of the current event.
        * @return
        * 	The participants list of the current event.
        */
        const PriorityQueue<long> getParticipants() const;

        virtual BaseEvent* clone() const = 0;

        /**
        * operator==: Returns if the given two external events are equal.
        * @param event1 - First event.
        * @param event2 - Second event.
        * @return
        * 	True if the events are equal, false otherwise.
        */
        friend bool operator==(const BaseEvent& event1, const BaseEvent& event2);

        /**
        * isSmaller: Returns the event with the previous date.
        *   If the dates are equal, returns the event with the smaller lexicographic value of name.
        * @param event2 - event to compare.
        * @return
        * 	True if the current event is smaller by this rule, false otherwise.
        */
        bool isSmaller(BaseEvent* event2);

        /**
        * isEqual: Returns if the current event is equal to the given external event.
        * @param event2 - event to compare.
        * @return
        * 	True if the events are equal, false otherwise.
        */
        bool isEqual(BaseEvent* event2);
    };

    /**
    * isVaildStudent: check if the student number is between 1 to 1234567890. If not, throw exception.
    * @param student - student to check.
    */
    void isVaildStudent(const long student);
}
#endif