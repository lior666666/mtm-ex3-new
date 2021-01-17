#ifndef FESTIVAL_H_
#define FESTIVAL_H_
#include "event_container.h"
namespace mtm{
    class Festival : public EventContainer{
        DateWrap event_date; 
        public:
        Festival(DateWrap date);  
        /** ~Festival: Destructor to destroy the class and free all the memory */
        ~Festival();
        Festival(const Festival& container);
        void add(const BaseEvent& event) override;
        /**
        *  clone: clones and allocates a new Festival as this.
        *  @param this - the Festival to clone
        * @return
        * 	returns an adress for an EventContainer pointer.
        */   
        EventContainer* clone() const override;
    };
}
#endif