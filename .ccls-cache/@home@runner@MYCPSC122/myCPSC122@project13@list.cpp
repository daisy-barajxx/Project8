/*
  Daisy Barajas
  CMPC 122
  Project 13
*/

#include <iostream>
using namespace std;

#include "list.h"

// Non-recursive functions. I have written them for you.
List::List() 
{ 
  head = NULL; 
}

List::~List() 
{ 
  Destructor(head);
}

bool List::IsEmpty() 
{
  if (head == NULL)
    return true;
  return false;
}

void List::PutItemH(itemType item)
{
  node *tmp = new node;
  tmp->item = item;
  tmp->next = head;
  head = tmp;
  tmp = NULL;
}

itemType List::GetItemH() 
{
  if (!IsEmpty())
    return head->item;
  return 0;
}

void List::DeleteItemH() 
{
  node *cur = head;
  head = head->next;
  delete cur;
  cur = NULL;
}

// Write the following functions recursively or in such a way that they use
// recursive functions.

void List::Print(node *cur)
{
  if (cur != NULL) {
    cout << cur->item << endl;
    Print(cur->next);
  }
  return;
}

void List::Print() 
{ 
  Print(head);
}

void List::PrintRev(node *cur) 
{
  if (cur != NULL) 
  {
    PrintRev(cur->next);
    cout << cur->item << endl;
  }
  return;
}

void List::PrintRev() 
{ 
  PrintRev(head); 
}

int List::GetLength() 
{ 
  return GetLength(head); 
}

int List::GetLength(node *cur) 
{
  if (cur == NULL)
    return 0;
  return GetLength(cur->next) + 1;
}

void List::Destructor(node *cur) 
{
  if (cur != NULL) 
  {
    Destructor(cur->next);
    delete cur;
  }
}
