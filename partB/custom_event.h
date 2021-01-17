#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_
#include "base_event.h"

namespace mtm{
    template<class CanRegister>
    class CustomEvent : public BaseEvent{
        CanRegister register_condition;
    public:
        CustomEvent() = default;

        CustomEvent(const CustomEvent& event) = default;

        CustomEvent& operator=(const CustomEvent&) = default;

        ~CustomEvent() = default;

        CustomEvent(DateWrap date, std::string name, CanRegister condition) : 
            BaseEvent(date, name), register_condition(condition) {
        }


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

        /**
        * getRegisterCondition: Get the register condition of the current event.
        * @return
        * 	The register condition of the current event.
        */
        const CanRegister getRegisterCondition() const
        {
            return register_condition;
        }

        BaseEvent* clone() const
        {
            return new CustomEvent(*this);
        }
    };
}
#endif