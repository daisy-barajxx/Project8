/*
  Team Name: Daisy Barajas and Liya Tekie
  Course: CPSC122
  Assignment: Project 12
*/
//Queue using List and composition 
#include <iostream>
using namespace std;
#include "queueP.h"
//note Queue is the queue implemented through inheritance or composition.  Find the files
//under B-Inheritance.  

PQueue::PQueue() : QueueI()
{}

PQueue::PQueue(PQueue* q) : QueueI(q)
{}

void PQueue::Enqueue(itemType newItem)
{ 
  if (head == nullptr || newItem < head->item) { 
    PutItemH(newItem); // add item to the queue
  }
  else 
  {
    node* tmp = PtrTo(newItem); // find the position to insert based on item value
    if (tmp != nullptr){
      PutItemT(newItem); // add item to the queue
    }
  }
}

node* PQueue::PtrTo(itemType newItem)
{
  node* tmp = head;
  while(tmp != nullptr && tmp->next != nullptr && tmp->next->item < newItem) 
  {
    tmp = tmp->next;
  }
 return tmp; // return the pointer to the position
}
	
