#include <iostream>
using namespace std;

#include "2-List.h"

//Constructor
List::List() 
{       
 length = 0;
 head = NULL;
}

//No need to write this function
//List::~List() //this function is written as DeleteItemH()

void List::PutItemH(itemType itemIn)
{
 node* tmp = new node; // initualize the heap 
 tmp->item = itemIn;
 tmp->next = head;
 head = tmp;
 length++;
}

void List::Print() const
{
 node* cur = head;
 while(cur != NULL)
  {
   cout << cur->item << endl; // same thing as head
   cur = cur->next;
  }
}