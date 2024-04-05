#include <iostream>
using namespace std;

#include "8-ListT.h"

ListT::ListT()
{
  length = 0;
  head = NULL;
  tail = NULL;
}
// destorys dynamically declared memory 
ListT::~ListT()
{
  node* temp = head;
  while(temp != NULL)
    {
      head = temp -> next;
      delete temp; 
      temp = head;
    }
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
/*
 pre: an instance of ListT exists
 post: returns true if list is empty, false otherwise
 */ 
 bool ListT::IsEmpty() const 
{
  return (head == NULL || tail == NULL);
}
/*
 pre: an instance of ListT exists
 post: returns length of the list 
 */
 int ListT::GetLength() const 
{
  return length;
}
/*
 pre: an instance of listT exists
 post: node containing itemIn is at the tail of the list 
 */ 
 void ListT::PutItemT(const itemType itemIn) 
{
  length = 0;
  node * tmp = new node;
  tmp -> item = itemIn;
  tmp -> next = NULL;
  tail -> next = tmp;
  tail = tmp;
  if (length == 0)
    head = tmp;
  length++;
  tmp = NULL;
}
/*
 pre: an instance of ListT exists and is not empty
 post: Returns the contents pointed to by the head of the list 
 */
 itemType ListT::GetItemH() const 
{
  if (head != NULL)
    return head -> item;
  else 
    return itemType();
}
/*
 pre: an instance of listT exists and is not empty
 post: Node pointed to by head is deleted 
 */
 void ListT::DeleteItemH() 
{
  if (head != NULL) 
  {
    node* tmp = head;
    head = head -> next;
    delete tmp;
    length--;
  }
  else
    cout << "List is empty" << endl;
}
/*
 pre: an instance of list exists and is not empty
 post: Returns the contents of the node at the tail of the list. 
 */
 itemType ListT::GetItemT() const
{
  if (tail != NULL)
    return tail -> item;
  else
    return itemType();
}
/*
 pre: an instance of list exists and is not empty
 post: node at the tail of the list is deleted 
 */
 void ListT::DeleteItemT()
{
  if (tail != NULL)
  {
    node* tmp = tail;
    tail = tail -> next;
    delete tmp;
    length--;
  }
  else 
    cout << "List is empty" << endl;
}
/*
 pre: an instance of ListT exists and is not empty
 post: returns the number of nodes in the list that store target 
 */
 int ListT::FindItem(const itemType target) const 
{
  int count = 0;
  node* cur = head;
  while (cur != NULL)
    {
      if (cur -> item == target)
        count++;
      cur = cur -> next;
    }
  return count;
}
/*
 pre:  an instance of List exists and is not empty 
 post: deletes all nodes that store target.  Returns
       the number of nodes deleted 
 */
 int ListT::DeleteItem(const itemType target)
{
  int count = 0;
  node* cur = head;
  node* prev = NULL;
  while (cur != NULL)
    {
      if (cur -> item == target)
      {
        if(prev == NULL)
        {
          head = head -> next;
          delete cur;
          cur = head;
        }
        else
        {
          prev -> next = cur -> next;
          delete cur;
          cur = prev -> next;
        }
        count++; // counts the sequence
        length--; // deletes the sequence
      }
      else
      {
        prev = cur;
        cur = cur -> next;
      }
    }
  return count;
}