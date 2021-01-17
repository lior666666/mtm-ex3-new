#ifndef GENERIC_QUEUE_H_
#define GENERIC_QUEUE_H_
#include <iostream>
    namespace mtm {
    template<class T>
    /** A class that stores generic elements by order that you decide on.*/
    class PriorityQueue
    {
        T data;
        /** Pointer to point to the next element in list. */
        PriorityQueue<T>* next;
        /** Iterator that provides the user with the option to go through the list by order.*/
        PriorityQueue<T>* iterator;
        public:
            /**
            *  PriorityQueue<T>: Constructor of the class, creats a new empty list.
            */
            PriorityQueue<T>()
            {
                iterator = NULL;
                next = NULL; 
            }
            /**
            *  ~PriorityQueue<T>: Destructor of the class, destroys the class and frees the memory.
            */
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
            /**
            *  PriorityQueue<T>: Copy Constructor of the class, creats a new copy of the list it gets by reference.  
            *
            * @param  queue_to_copy - a reference of another Priority Queue to copy.
            */
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
            /**
            *  operator=: Makes a new copy of the list and moves it to the new Priority Queue.
            *
            * @param queue_to_copy - a reference of another Priority Queue to copy.
            * @return
            * 	A new Queue in case of success.
            */
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
            /**
            *  containsElement: cheks if the element that the queue recieves already in the queue. 
            *  Note: it's users responsibility to provide an operator= to the data he sends. 
            * @param data - the element that needs to be checked. 
            * @return
            * 	true - if data exists in queue. 
            * 	false - if data is not there. 
            */ 
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
            /**
            *  addElement: Adds a new element to the list by it's priotity by operator< that is provided by the user. In case the element already in the list,
            *  it won't add it again!
            *  Iterator is undefined after the function is done.   
            * @param data - the data that needs to be added to the queue. 
            */
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
             /**
            *  addElement: Adds a new element to the list after the location the was recieved from the second argument. 
            *  If you want to add the argument to the end of the list, you shoul pass NULL to the second argument. 
            *  If you you want it to be at the beginning, you should pass the head of the list(the list itself).  
            *  Iterator is undefined after the function is done.   
            * @param data - the data that needs to be added to the queue. 
            * @param location - a pointer that points to one of the elements in the list, and the data will be inserted in a new elemnt after the location. 
            */
            void addElement(T data, PriorityQueue<T>* location)// should not call if list is empty!!! 
            { 
                if(location == this)
                {
                    PriorityQueue<T>* current_pointer = this;
                    PriorityQueue<T>* next_pointer = current_pointer->next;
                    PriorityQueue<T>* temp_pointer = new PriorityQueue<T>;
                    temp_pointer->data = data; 
                    current_pointer->next = temp_pointer;
                    temp_pointer->next = next_pointer;
                }
                else if(location == NULL)
                {
                    PriorityQueue<T>* current_pointer = this->next;
                    PriorityQueue<T>* next_pointer = current_pointer->next;  
                    while(next_pointer != NULL) 
                    {
                       current_pointer = next_pointer; 
                       next_pointer = next_pointer->next;  
                    }
                    PriorityQueue<T>* temp_pointer = new PriorityQueue<T>;
                    temp_pointer->data = data; 
                    current_pointer->next = temp_pointer; 
                }
                else
                {
                    PriorityQueue<T>* current_pointer = this->next;
                    while(current_pointer != NULL)
                    {
                        if(current_pointer == location)
                        {
                            PriorityQueue<T>* temp_pointer = new PriorityQueue<T>;
                            temp_pointer->data = data; 
                            temp_pointer->next = current_pointer->next;
                            current_pointer->next = temp_pointer;
                        }
                        current_pointer = current_pointer->next;
                    }
                }
            }
            /**
            * removeElement: Removes an element from the queue with the same data as received. returns true , and . 
            * Note: relies on operator= from the user for the data that is provided. 
            * @param data - the data of the element that needs to be removed from the queue. 
            * @return
            * 	true - if the elemnt removed
            * 	false - if an elemnt with same data is not in the list.
            */
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

            // 
            /**
            * popTop: Removes the first element from the list and returns it's data.
            * @return
            * 	returns the data of the elemnt that was removed. 
            */
            T popTop()
            {
                 T value;
                if(next != NULL)
                {
                    value = next->data; 
                    PriorityQueue<T>* current_pointer = this;
                    PriorityQueue<T>* next_pointer = next;
                    current_pointer->next = current_pointer->next->next; 
                    next_pointer->next = NULL;
                    delete next_pointer; 
                }
                else
                {
                   value = NULL; 
                }
                return value; 
            }   
            /**
            * getIterator: Initialize the iterator to the top of the list and return it.
            * @return
            * 	returns the iterator of the list that points to it's head.  
            */
            PriorityQueue<T>* getIterator()
            {
                iterator = next; 
                return iterator; 
            }

            /**
            * getData: Returns the data of the element which the iterator points on.
            * @return
            * 	returns the data of the element which the iterator points on.
            */
            T getData()
            {
                return iterator->data;
            } 
            /**
            * getNext: Moves the iterator to the next element in the list and returns it.
            * @return
            * 	returns the iterator of the list. 
            */
            PriorityQueue<T>* getNext()
            {
                iterator = iterator->next; 
                return iterator;
            }
            /**
            * printPriorityQueue: Prints the list by order. Each element in a new line. 
            * @param out - the ostream where should the output go. 
            * @return
            * 	returns the to the ostream. 
            */
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
           /**
            * getSize: returns the size of the queue depending on how much elements are in it.
            * @return
            *  returns the size of the list. 
            */
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
            /**
            *  operator== compares between 2 lists.
            *
            * @param queue1 - the first queue. 
            * @param queue2 - the second queue. 
            * @return
            * 	true - if both lists are equal.
            * 	false - if lists are not equal.
            */
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