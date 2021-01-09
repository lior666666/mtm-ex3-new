#ifndef GENERIC_QUEUE_H_
#define GENERIC_QUEUE_H_
#include <iostream>
namespace mtm{
    template<class T>
    struct Node {
        Node<T>* next;
        T data; 
    };

    template<class T>
    class PriorityQueue
    {
        Node<T>* next_pointer;
        Node<T>* current_pointer;
        Node<T>* first;
        public:
            Node<T>* iterator;
            PriorityQueue<T>()
            {
                iterator = NULL;
                next_pointer = NULL;
                current_pointer = NULL; 
                first = NULL; 
            }
            ~PriorityQueue<T>()
            {
                while(next_pointer!=NULL)
                {
                   delete(current_pointer);
                   current_pointer = next_pointer;
                   next_pointer = next_pointer->next;  
                }
                delete(current_pointer);
            }
            /*
            PriorityQueue<T>(const PriorityQueue<T>& queue_to_copy)
            {
                while(queue_to_copy.current_pointer!=NULL)
                {
                   current_pointer = new Node<T>;
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
                   current_pointer = new Node<T>;
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
                if(first == NULL) 
                {
                    // The list is empty
                    current_pointer = new Node<T>;
                    current_pointer->data = data; // assuming T has a copy constructor. 
                    current_pointer->next = NULL;
                    first = current_pointer;
                } 
                else 
                {
                    // The list isn't empty
                   if(data < current_pointer->data) // data smaller than first node in list 
                    {
                        current_pointer = new Node<T>;
                        current_pointer->data = data; 
                        current_pointer->next = first;
                        first = current_pointer;
                        next_pointer = first->next; 
                    }
                    else
                    {
                        // The list has more than one element
                        while (next_pointer!= NULL)
                        { 
                            if(data < next_pointer->data && current_pointer->data <data) // asumming T has '<' operator.
                            {
                                Node<T>* temp_pointer = new Node<T>;
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
                            next_pointer = new Node<T>;
                            next_pointer->data = data; 
                            next_pointer->next = NULL; 
                            current_pointer->next = next_pointer; 
                        }
                        current_pointer = first;
                        next_pointer = current_pointer->next;    
                    }
                }
            }

            void removeElement(T data)
            {
               if(first != NULL)
               {
                    if(first->data == data)
                    {
                        Node<T>* temp_pointer = first;
                        first = first->next; 
                        delete(temp_pointer);
                    }
                    else
                    {
                        while(next_pointer!=NULL)
                        {
                            if(next_pointer->data == data)
                            {
                                Node<T>* temp_pointer = next_pointer;
                                next_pointer = next_pointer->next;
                                current_pointer->next = next_pointer; 
                                delete(temp_pointer);
                                break;
                            }
                            next_pointer = next_pointer->next;
                            current_pointer = current_pointer->next;
                        }
                    }
                    current_pointer = first; 
                    if(current_pointer !=NULL)
                    {
                        next_pointer = current_pointer->next; 
                    }
                    else
                    {
                        next_pointer =  NULL; 
                    }
                    
               }
            }
            Node<T>* getIterator()
            {
                iterator = first; 
                return iterator; 
            }

            //not sure if we sholud have const version or regular one or both. 
            
            bool containsElement(T data)
            {
                while(current_pointer!=NULL)
                {
                    if(current_pointer->data == data)
                    {
                        return true; 
                    }
                }
                current_pointer = first; 
                return false; 
            }
            T getData()
            {
                return iterator->data;
            }
            Node<T>* getNext()
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
