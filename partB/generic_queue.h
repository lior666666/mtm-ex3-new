#ifndef GENERIC_QUEUE_H_
#define GENERIC_QUEUE_H_
#include <iostream>
    namespace mtm {
    template<class T>
    class PriorityQueue
    {
        T data;
        PriorityQueue<T>* next;
        PriorityQueue<T>* iterator;
        public:
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
                if(this->next != NULL)
                {
                    PriorityQueue<T>* current_pointer = this->next; 
                    PriorityQueue<T>* next_pointer = current_pointer->next; 
                    while(next_pointer != NULL)
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
                if(queue_to_copy.next != NULL)
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
            //checks if element already in the list, true if he is false in not. 
            bool containsElement(T data)
            {
                PriorityQueue<T>* current_pointer = next; 
                if(current_pointer !=NULL)
                {  
                    while(current_pointer != NULL)
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
            //adds a new element to the list by it's priotity. return true if sucsses, false if element already in the list. 
            // !! ITERATOR IS NOT DEFINDED AFTER THIS FUNCTION. 
            void addElement(T data) 
            {
                PriorityQueue<T>* current_pointer = NULL;
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
                        while (next_pointer != NULL)
                        { 
                            if(data < next_pointer->data && current_pointer->data < data) // asumming T has '<' operator.
                            {
                                PriorityQueue<T>* temp_pointer = new PriorityQueue<T>;
                                temp_pointer->data = data; 
                                current_pointer->next = temp_pointer;
                                temp_pointer->next = next_pointer;
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
            void addElement(T* data_pointer) 
            {
               addElement((*data_pointer));
            }
            void addElement(T& data_pointer) 
            {
               addElement((*data_pointer));
            }

            //removes an elenemt from the list. returns true if the elemnt removed, and false if the elemnt not in the list. 
            // !! ITERATOR IS NOT DEFINDED AFTER THIS FUNCTION. 
            bool removeElement(T data)
            {
               if(next != NULL)
               {
                    PriorityQueue<T>* current_pointer = this;
                    PriorityQueue<T>* next_pointer = next;  
                    while(next_pointer != NULL)
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

            // removes the first element in the list. 
            void removeTop()
            {
                if(next != NULL)
                {
                    PriorityQueue<T>* current_pointer = this;
                    PriorityQueue<T>* next_pointer = next;
                    current_pointer->next = current_pointer->next->next; 
                    next_pointer->next = NULL;
                    delete next_pointer; 
                }
            }

            // nitialize the iterator to the top of the list and return it. 
            PriorityQueue<T>* getIterator()
            {
                iterator = next; 
                return iterator; 
            }

            //returns the data of the current elemnt.      
            T& getData()
            {
                return iterator->data;
            }

            // moves the iterator to the next element in the list and returns it. 
            PriorityQueue<T>* getNext()
            {
                iterator = iterator->next; 
                return iterator;
            }

            std::ostream& printPriorityQueue(std::ostream& out) const
            {
                if(next != NULL)
                {
                    PriorityQueue<T>* temp_pointer = next; 
                    while (temp_pointer != NULL)
                    {
                        out << temp_pointer->data << std::endl; 
                        temp_pointer = temp_pointer->next; 
                    }
                    return out; 
                }
                return out; 
            }

            // returns the size of the list. 
            int getSize()
            {
                int counter = 0; 
                PriorityQueue<T>* temp_pointer = next; 
                while (temp_pointer != NULL)
                {
                    counter++;
                    temp_pointer = temp_pointer->next; 
                }
                return counter; 
            }
            friend bool operator==(const PriorityQueue<T>& queue1, const PriorityQueue<T>& queue2)
            {
                PriorityQueue<T>* queue1_pointer = queue1.next;
                PriorityQueue<T>* queue2_pointer = queue2.next;
                if (queue1.getSize() != queue2.getSize())
                {
                    return false;
                }
                while (queue1_pointer->next != NULL)
                {
                    if (queue1_pointer->data != queue2_pointer->data)
                    {
                        return false;
                    }
                    queue1_pointer = queue1_pointer->next;
                    queue2_pointer = queue2_pointer->next;
                }
                return true;
            }
    };
    
}
#endif