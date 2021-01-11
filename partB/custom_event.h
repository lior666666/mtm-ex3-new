#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_
#include "base_event.h"

namespace mtm{
    template<class CanRegister>
    class CustomEvent : BaseEvent{
        CanRegister register_condition;
    public:
        //#1
        //priority queue will be initialized by default constructor
        CustomEvent(DateWrap date, char* name, CanRegister condition) : 
            BaseEvent(date, name), register_condition(condition) {
        }

        //#2
        void registerParticipant(const long student) override
        {
            isVaildStudent(student);
            if (!register_condition(student))
            {
                throw RegistrationBlocked();
            }
            if (!event_participants.addElement(student))
            {
                throw AlreadyRegistered();
            }
        }

        //#3
        BaseEvent* clone() const override
        {
            DateWrap copied_date = DateWrap(this->event_date);
            char* copied_name = new char[strlen(this->event_name)];
            strcpy(copied_name, this->event_name);
            CustomEvent copied_event(copied_date, copied_name, CanRegister(register_condition));
            return &copied_event;
        }
    };
}
#endif