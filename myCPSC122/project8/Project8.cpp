/* 
  Team Name: Daisy Barajas and Liya Tekie
   Course: CPSC122
   Date Submitted: 04/05/2024
   Assignment Name: Project 8
*/

#include <iostream>
using namespace std;

#include "8-ListT.h"

ListT::ListT()
{
  length = 0;
  head = NULL;
  tail = NULL;
}

ListT::~ListT()
{
  do (DeleteItem())
    while (lst->length == 0);
  head = NULL;
  tail = NULL;
  length = 0;
}

void ListT::PutItemH(itemType item)
{
 length = 0;
 node* tmp = new node;
 tmp->item = item;
 tmp->next = head;

 head = tmp; 
 if (length == 0)
  tail = tmp;  
 length++;
}

void ListT::Print() const
{
 node* cur = head;
 while(cur != NULL)
 {
  cout << cur->item << endl;
  cur = cur->next;
 }
}

void ListT::PutItemT(const itemType itemIn) 
{
  node* tmp = new node;
  tmp->item = itemIn;
  // if (this->IsEmpty())
  //   head = tmp;
  // tail->next = tmp;
  tail = tmp;
  length++;
}

itemType ListT::GetItemT() const
{
  node* cur = tail; 
  while (tail != NULL)
    return tail->item;
  return itemType();
}
itemType ListT::GetItemH() const 
{
  node* cur = head;
  if (head != NULL)
    return head->item;
  return itemType();
}

bool ListT::IsEmpty() const 
{
  return length == 0;
}

int ListT::GetLength() const 
{
  return length;
}

void ListT::DeleteItemH() 
{
  if (head != NULL) 
  {
    node* tmp = head; 
    head = head->next;
    delete tmp;
    length--;
  }
    
}
void ListT::DeleteItemT() 
{
  if (tail != NULL)

}
int ListT::DeleteItem(const itemType target) {
  
}

//g++ Project8.cpp 8-ListTTst.cpp 
//./a.out 