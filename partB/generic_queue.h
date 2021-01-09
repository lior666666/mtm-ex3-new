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

            void addElement(T data) 
            {
                if(first == NULL) 
                {
                    // The list is empty
                    next_pointer = new Node<T>;
                    next_pointer->data = data; // assuming T has a copy constructor. 
                    current_pointer = next_pointer;
                    next_pointer->next = NULL;
                    first = current_pointer;

                } 
                else 
                {
                    // The list isn't empty
                   if(data < current_pointer->data) // data smaller than first node in list 
                    {
                        current_pointer = new Node<T>;
                        current_pointer->data = data; // assuming T has a copy constructor.
                    }
                    current_pointer->next = next_pointer;
                    first = current_pointer;
                    else
                    {
                        // The list has more than one element
                        while (next_pointer!= NULL)
                        { 
                            if(data < next_pointer->data && current_pointer->data <data)
                            {
                                Node<T>* temp_pointer = new Node<T>;
                                temp_pointer = data; // assuming T has a copy constructor.
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
                            next_pointer->data = data; // assuming T has a copy constructor. 
                            next_pointer->next = NULL; 
                            current_pointer->next = next_pointer; 
                        }
                        current_pointer = first;
                        next_pointer = current_pointer->next;    
                    }
                }
            }
        void deleteElement (T data)
        {
            while(cu)
        }


        T get(int index) 
        {
            if(index == 0) 
            {
                // Get the iterator element
                return this->iterator->data;
            } else 
            {
                // Get the index'th element
                Node<T>*  next_pointer = this->iterator;
                for(int i = 0; i < index; ++i) 
                {
                    curr = curr->next;
                }
                return curr->data;
            }
        }

        T operator[](int index) 
        {
            return get(index);
        }

    };
}

