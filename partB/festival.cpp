#include "festival.h"
namespace mtm{

    // I added a default date constructor, so it's should work 
    Festival::Festival(DateWrap date): EventContainer(), event_date(date)
    {}

     Festival::~Festival()
     {
        PriorityQueue<BaseEvent*>* current_pointer = events_list.getIterator();
        BaseEvent* pointer; 
        while(current_pointer != NULL)
        {
            pointer = events_list.popTop();
            delete pointer; 
            current_pointer = events_list.getIterator();
        }
     }

    void Festival::add(const BaseEvent& event)
    {
        if(event.getDate() != event_date)
        {
            throw DateMismatch();
        }
        else
        {
            BaseEvent* event_pointer = event.clone(); 
            if(events_list.getSize()==0)// in case list is empty we can use the first function, there is no order anyway yet.  
            {
                events_list.addElement(event_pointer);
            }
            else
            {
                PriorityQueue<BaseEvent*>* current_pointer = events_list.getIterator();
                if(event_pointer->getName().compare(events_list.getData()->getName()) <= 0 )
                {
                    events_list.addElement(event_pointer, &events_list); // worth checking if this one is working. 
                }
                else
                {
                    PriorityQueue<BaseEvent*>* previous_pointer = events_list.getIterator();
                    current_pointer = events_list.getNext();
                    while(current_pointer!= NULL)
                    {
                        if(event_pointer->getName().compare(events_list.getData()->getName()) <= 0 )
                        {
                           events_list.addElement(event_pointer, previous_pointer);
                           break;
                        }
                        previous_pointer = current_pointer; 
                        current_pointer = events_list.getNext();
                    }
                    if(current_pointer == NULL)
                    {
                        events_list.addElement(event_pointer, NULL);
                    }
                }
            }
        }
    } 
    
}