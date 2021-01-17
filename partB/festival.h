#ifndef FESTIVAL_H_
#define FESTIVAL_H_
#include "event_container.h"
namespace mtm{
    class Festival : public EventContainer{
        DateWrap event_date; 
    public:
        Festival(DateWrap date);  

        /**
        * ~Festival: destructor. Free the festival.
        */
        ~Festival();

        /**
        * Festival: copy constructor.
        * @param container - the festival to copy.
        */
        Festival(const Festival& container);
        
        void add(const BaseEvent& event) override;
        
        /**
        *  clone: clones and allocates a new Festival as this.
        * @return
        * 	returns an adress for an EventContainer pointer.
        */   
        EventContainer* clone() const override;
    };
}
#endif