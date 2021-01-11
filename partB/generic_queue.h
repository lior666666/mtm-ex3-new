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
            PriorityQueue<T>(const PriorityQueue<T>& queue_to_copy)
            {
                data = queue_to_copy.data; 
                if(queue_to_copy.next!=NULL)
                {
                    next = new PriorityQueue<T>;
                    PriorityQueue<T>* temp_pointer = queue_to_copy.next; 
                    PriorityQueue<T>* current_pointer = next; 
                    while(temp_pointer->next!=NULL)
                    {
                        current_pointer->data = temp_pointer->data; 
                        current_pointer->next = new PriorityQueue<T>;
                        current_pointer = current_pointer->next;
                        temp_pointer = temp_pointer->next;
                    }
                    current_pointer->data = temp_pointer->data;
                }
                else
                {
                    next = NULL; 
                }
            }
            
            PriorityQueue<T>& operator=(const PriorityQueue<T>& queue_to_copy)
            {
                if(this == &queue_to_copy)
                {
                    return *this;
                }
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
                data = queue_to_copy.data; 
                if(queue_to_copy.next!=NULL)
                {
                    next = new PriorityQueue<T>;
                    PriorityQueue<T>* temp_pointer = queue_to_copy.next; 
                    PriorityQueue<T>* current_pointer = next; 
                    while(temp_pointer->next!=NULL)
                    {
                        current_pointer->data = temp_pointer->data; 
                        current_pointer->next = new PriorityQueue<T>;
                        current_pointer = current_pointer->next;
                        temp_pointer = temp_pointer->next;
                    }
                    current_pointer->data = temp_pointer->data;
                }
                else
                {
                    next = NULL; 
                }
                return *this;
            }
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
            bool addElement(T data) 
            {
                if(containsElement(data))
                {
                    return false; 
                }
                PriorityQueue<T>* current_pointer = NULL;
                if(next == NULL) 
                {
                    // The list is empty
                    current_pointer = new PriorityQueue<T>;
                    current_pointer->data = data; // assuming T has a copy constructor. 
                    current_pointer->next = NULL;
                    next = current_pointer; 
                    return true; 
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
                        return true; 
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
                                return true;  
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
                            return true; 
                        } 
                    }
                }
                return false;
            }
            /*
            bool removeCurrent()
            {
               PriorityQueue<T>* current_pointer = this;
               PriorityQueue<T>* next_pointer = next;   
            }*/
            bool removeElement(T data)
            {
               if(next != NULL)
               {
                    PriorityQueue<T>* current_pointer = this;
                    PriorityQueue<T>* next_pointer = next;  
                    while(next_pointer!=NULL)
                        {
                            if(next_pointer->data == data)
                            {  
                                //PriorityQueue<T>* temp_pointer = next_pointer;
                                current_pointer->next = current_pointer->next->next; 
                                next_pointer->next = NULL;
                                delete next_pointer;
                                return true; 
                            }
                            current_pointer = next_pointer;
                            next_pointer = current_pointer->next;
                        }
               }
               return false; 
            }
            PriorityQueue<T>* getIterator()
            {
                iterator = next; 
                return iterator; 
            }

            //not sure if we sholud have const version or regular one or both. 
            
           
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
