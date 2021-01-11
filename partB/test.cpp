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
    //q.removeElement(1);
    //PriorityQueue<int> cp(q); 
    PriorityQueue<int> cp = q;
    PriorityQueue<int>* tmp = cp.getIterator();
    while(tmp!=NULL)
    {
        std::cout<<cp.getData()<<' '; 
        tmp = cp.getNext();
    }
    std::cout<<std::endl;
    return 0;
}



