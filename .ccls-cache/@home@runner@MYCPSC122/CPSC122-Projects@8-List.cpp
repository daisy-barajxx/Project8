/*
  Group Name: Daisy Barajas and Liya Tekie
  Class: CPSC 122, Section 1
  Date Submitted: April 5, 2024
  Description: This program will test the functions of the List class that includes a head and tail.
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
// destorys dynamically declared memory 
ListT::~ListT()
{
  node* cur = head;
  while(cur != NULL)
    {
      node* tmp = cur;
      cur = cur -> next;
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
  if (head == NULL)
    return true;
  else 
    return false;
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
  tmp -> next = tail;
  
  tail = tmp;
  if (length == 0)
    tail = tmp;
  length++;
}
/*
 pre: an instance of ListT exists and is not empty
 post: Returns the contents pointed to by the head of the list 
 */
 itemType ListT::GetItemH() const 
{
  node* cur = head;
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
    if (head == NULL)
      tail = NULL; // if the list is empty 
    delete tmp;
    length--;
  }
  else
    cout << "Head is deleted" << endl;
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
    if (head == tail) 
    {
      head = NULL;
      tail = NULL;
    } else if (head != NULL) 
    {
      node* cur = head;
      while (cur -> next != tail) 
        cur = cur -> next;
      tail = cur;
      tail -> next = NULL;
      delete tmp;
      length--;
    } else {
      cout << "Tail is empty" << endl;
    }
  } 
}
/*
 pre: an instance of ListT exists and is not empty
 post: returns the number of nodes in the list that store target 
 */
 int ListT::FindItem(const itemType target) const 
{
  node* headd = new node;
  int count = 0;
  node* cur = headd;
  while (cur != NULL) // traverses the list
    {
      if (cur -> item == target) // if the item is found in the list
        count++;
      cur = cur -> next; // traverse the list
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
  node* tmp = cur;
  if (prev == NULL)
    tail = NULL;
  else if (head == NULL) 
  {
    cout << "List is empty" << endl;
    return 0;
  }
  
  while (cur != NULL)
    {
      if (cur -> item == target)
      {
        cur = cur -> next;
        delete tmp;
        count++;
      } else {
          prev = cur;
        cur = cur -> next;
      }
    }
  return count;
}