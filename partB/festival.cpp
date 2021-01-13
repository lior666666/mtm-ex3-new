#include "festival.h"
namespace mtm{

    // I added a default date constructor, so it's should work 
    Festival::Festival(DateWrap date): EventContainer(), event_date(date)
    {}
    void Festival::add(BaseEvent& event)
    {
        if(event.getDate() != event_date)
        {
            throw DateMismatch(); 
        }
        else
        {
            BaseEvent* copy_event = event.clone(); 
            events_list.addElement(copy_event); 
        }
    } 
    
}