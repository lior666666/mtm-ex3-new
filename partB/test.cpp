#include <iostream>
#include "generic_queue.h"
using namespace mtm;
int main()
{
    PriorityQueue<int> q; 
    q.addElement(5);
    q.addElement(3);
    q.addElement(2);
    q.addElement(1);
    q.addElement(7);
    Node<int>* tmp = q.getIterator();
    q.removeElement(3);
    while(tmp!=NULL)
    {
        std::cout<<q.getData()<<' '; 
        tmp = q.getNext();
    }
    std::cout<<std::endl;
    return 0;
}



