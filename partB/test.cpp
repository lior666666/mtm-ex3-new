#include <iostream>
#include "generic_queue.h"
using namespace mtm;
int main()
{
    PriorityQueue<int> q; 
    for(int i = 9; i>=1; i--)
    {
        q.addElement(i); 
    }
    std::cout<<q;
    
    if(!q.addElement(1))
         std::cout<<"already in!"<<std::endl;
    if(!q.addElement(9))
         std::cout<<"already in!"<<std::endl;
        
    std::cout<<q.getSize()<<std::endl;
    q.removeTop();
    if(!q.removeElement(15))
        std::cout<<"no such element!!"<<std::endl;
    PriorityQueue<int> cp2; 
    PriorityQueue<int> cp;
    cp2.addElement(2);
    cp2 = cp = q; 
    PriorityQueue<int>* tmp = cp.getIterator();
    while(tmp!=NULL)
    {
        std::cout<<cp.getData()<<' '; 
        tmp = cp.getNext();
    }
    std::cout<<std::endl;
    PriorityQueue<int>* tmp2 = cp2.getIterator();
    while(tmp2!=NULL)
    {
        std::cout<<cp2.getData()<<' '; 
        tmp2 = cp2.getNext();
    }
    std::cout<<cp.getSize()<<std::endl;
    std::cout<<cp2.getSize()<<std::endl;
    std::cout<<std::endl;
    



    return 0;
}



