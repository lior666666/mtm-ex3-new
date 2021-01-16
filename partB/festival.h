#ifndef FESTIVAL_H_
#define FESTIVAL_H_
#include "event_container.h"
namespace mtm{
    class Festival : public EventContainer{
        DateWrap event_date; 
        public:
        Festival(DateWrap date);  
        ~Festival();
        Festival(const Festival& container);
        void add(const BaseEvent& event) override;
        EventContainer* clone() const override;
    };
}
#endif