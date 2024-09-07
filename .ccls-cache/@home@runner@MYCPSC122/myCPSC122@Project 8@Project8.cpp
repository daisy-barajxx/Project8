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
  node* cur = head;
  while (cur != NULL) 
    {
      node* tmp = cur;
      cur = cur->next;
      delete cur;
    }
  head = NULL;
  tail = NULL;
  length = 0;
  cout << "List is destroyed" << endl;
  Print();
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
 tail = NULL;
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
  if (this->IsEmpty())
    head = tmp;
  tail->next = tmp;
  tail = tmp;
  length++;
}

itemType ListT::GetItemT() const
{
  while (tail != NULL)
    return tail->item;
  return itemType();
}
itemType ListT::GetItemH() const 
{
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
  if (head == NULL)
  {
    cout << "List does not exist" << endl;
  return -1;
  }
  return length;
}

void ListT::DeleteItemH() 
{
  if (head != NULL) 
    delete head->next;
  length--;
}

//g++ Project8.cpp 8-ListTTst.cpp 
//./a.out 