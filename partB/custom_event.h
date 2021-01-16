#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_
#include "base_event.h"

namespace mtm{
    template<class CanRegister>
    class CustomEvent : public BaseEvent{
        CanRegister register_condition;
    public:
        //#1
        //priority queue will be initialized by default constructor
        CustomEvent() = default;
        CustomEvent(DateWrap date, std::string name, CanRegister condition) : 
            BaseEvent(date, name), register_condition(condition) {
        }

        //#2
        ~CustomEvent() {}

        //#3
        void registerParticipant(const long student) override
        {
            isVaildStudent(student);
            if (!register_condition(student))
            {
                throw RegistrationBlocked();
            }
            if (event_participants.containsElement(student))
            {
                throw AlreadyRegistered();
            }
            event_participants.addElement(student);
        }

        /*//#4
        BaseEvent* clone() const override
        {
            DateWrap copied_date = DateWrap(this->event_date);
            std::string copied_name = event_name;
            CustomEvent* copied_event = NULL;
            *copied_event = CustomEvent(copied_date, copied_name, CanRegister(register_condition));
            copied_event->event_participants = PriorityQueue<long>(this->event_participants);
            return copied_event;
        }*/

        const CanRegister getRegisterCondition() const
        {
            return register_condition;
        }

        CustomEvent(const CustomEvent& event) : 
            BaseEvent(event),register_condition(event.register_condition)
        {

        }

        //#2
        BaseEvent* clone() const
        {
            return new CustomEvent(*this);
        }
    };
}
#endif