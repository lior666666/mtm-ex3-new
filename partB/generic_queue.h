#ifndef GENERIC_QUEUE_H_
#define GENERIC_QUEUE_H_
#include <iostream>
    namespace mtm {
    template<class T>
    class PriorityQueue
    {
        T data;
        PriorityQueue<T>* next;
        public:
            PriorityQueue<T>* iterator;
            PriorityQueue<T>()
            {
                iterator = NULL;
                next = NULL; 
            }
            
            ~PriorityQueue<T>()
            {
                if(this->next !=NULL)
                {
                    PriorityQueue<T>* current_pointer = this->next; 
                    PriorityQueue<T>* next_pointer = current_pointer->next; 
                    while(next_pointer!=NULL)
                    {
                        PriorityQueue<T>* temp_pointer = current_pointer;
                        current_pointer = next_pointer;
                        temp_pointer->next = NULL; 
                        delete temp_pointer;
                        next_pointer = next_pointer->next;  
                    }
                    delete current_pointer;
                }
            }
            
            /*
            PriorityQueue<T>(const PriorityQueue<T>& queue_to_copy)
            {
                while(queue_to_copy.current_pointer!=NULL)
                {
                   current_pointer = new PriorityQueue<T>;
                   current_pointer->data = queue_to_copy.current_pointer->data; 
                   current_pointer = current_pointer->next; 
                   queue_to_copy.current_pointer = queue_to_copy.current_pointer->next; 
                }
                queue_to_copy.current_pointer = queue_to_copy.first;
                if(queue_to_copy.first != NULL)
                {
                   queue_to_copy.next_pointer = queue_to_copy.current_pointer->next; 
                }
                else
                {
                   queue_to_copy.next_pointer = NULL;  
                }
                first = queue_to_copy.first;
                current_pointer = queue_to_copy.current_pointer;
                next_pointer = queue_to_copy.next_pointer; 
            }**/
            /*
            PriorityQueue<T>& operator=(const PriorityQueue<T>& queue_to_copy)
            {
                if(this == &queue_to_copy)
                {
                    return *this;
                }
                while(next_pointer!=NULL)
                {
                   delete(current_pointer);
                   current_pointer = next_pointer;
                   next_pointer = next_pointer->next;  
                }
                delete(current_pointer);
                while(queue_to_copy.current_pointer!=NULL)
                {
                   current_pointer = new PriorityQueue<T>;
                   current_pointer->data = queue_to_copy.current_pointer->data; 
                   current_pointer = current_pointer->next; 
                   queue_to_copy.current_pointer = queue_to_copy.current_pointer->next; 
                }
                queue_to_copy.current_pointer = queue_to_copy.first;
                if(queue_to_copy.first != NULL)
                {
                   queue_to_copy.next_pointer = queue_to_copy.current_pointer->next; 
                }
                else
                {
                   queue_to_copy.next_pointer = NULL;  
                }
                first = queue_to_copy.first;
                current_pointer = queue_to_copy.current_pointer;
                next_pointer = queue_to_copy.next_pointer; 
                return *this;
            }**/
            void addElement(T data) 
            {
                PriorityQueue<T>* current_pointer;
                if(next == NULL) 
                {
                    // The list is empty
                    current_pointer = new PriorityQueue<T>;
                    current_pointer->data = data; // assuming T has a copy constructor. 
                    current_pointer->next = NULL;
                    next = current_pointer; 
                } 
                else // The list not empty
                {
                    current_pointer = this;
                    PriorityQueue<T>* next_pointer = current_pointer->next;   
                    
                    if(data < next_pointer->data) // if data smaller than the first element. 
                    {
                        PriorityQueue<T>* temp_pointer = new PriorityQueue<T>;
                        temp_pointer->data = data; 
                        current_pointer->next = temp_pointer;
                        temp_pointer->next = next_pointer;
                    }
                    else 
                    {
                        current_pointer = this->next;
                        PriorityQueue<T>* next_pointer = current_pointer->next;   
                        while (next_pointer!= NULL)
                        { 
                            if(data < next_pointer->data && current_pointer->data < data) // asumming T has '<' operator.
                            {
                                PriorityQueue<T>* temp_pointer = new PriorityQueue<T>;
                                temp_pointer->data = data; 
                                current_pointer->next = temp_pointer;
                                temp_pointer->next = next_pointer;
                                break; 
                            }
                                current_pointer = next_pointer;
                                next_pointer = next_pointer->next;    
                        }
                        if(next_pointer == NULL && current_pointer->data < data) 
                        {
                            PriorityQueue<T>* temp_pointer = new PriorityQueue<T>;
                            temp_pointer->data = data;  
                            temp_pointer->next = NULL; 
                            current_pointer->next = temp_pointer; 
                        } 
                    }
                }
            }

            void removeElement(T data)
            {
               if(next != NULL)
               {
                    PriorityQueue<T>* current_pointer = this;
                    PriorityQueue<T>* next_pointer = current_pointer->next;  
                    /*
                    if(current_pointer->data == data)
                    {
                        PriorityQueue<T>* temp_pointer = current_pointer;
                        this->next = next_pointer; 
                        temp_pointer->next = NULL;
                        current_pointer->next = NULL;
                        delete temp_pointer;
                    }*/
                    //else
                   // {
                        while(next_pointer!=NULL)
                        {
                            if(next_pointer->data == data)
                            {  
                                PriorityQueue<T>* temp_pointer = next_pointer;
                                next_pointer = next_pointer->next;
                                current_pointer->next = next_pointer; 
                                temp_pointer->next = NULL;
                                //delete temp_pointer;
                                break;
                            }
                            current_pointer = next_pointer;
                            next_pointer = current_pointer->next;
                        }
                   //}
               }

            }
            PriorityQueue<T>* getIterator()
            {
                iterator = next; 
                return iterator; 
            }

            //not sure if we sholud have const version or regular one or both. 
            
            bool containsElement(T data)
            {
                PriorityQueue<T>* current_pointer = next; 
                if(current_pointer !=NULL)
                {  
                    while(current_pointer!=NULL)
                    {
                        if(current_pointer->data == data)
                        {
                            return true; 
                        }
                        current_pointer = current_pointer->next;
                    }
                }
                return false;
            }
            T getData()
            {
                return iterator->data;
            }
            PriorityQueue<T>* getNext()
            {
                iterator = iterator->next; 
                return iterator;
            } 
            /*
            const T getFirstData() 
            {
                return first->data; 
            }**/
    };
}
#endif
