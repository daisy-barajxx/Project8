#include <iostream>
using namespace std;

#include "5-ListTmpl.h"

template <typename T>
List<T>::List()
{
  
}

template <typename T>
List<T>::~List()
{
  doubleNode<T> *cur = head->next;
  doubleNode<T> *tmp = cur;
  while (cur != tail) 
  {
    cur = cur->next;
    delete tmp;
  }
  delete tail;
  delete head;
  length = 0;
  cout << "Destroyed List" << endl;
}

template <typename T>
void List<T>::PutItemH(const T newItem)
{
 node<T>* tmp = new node<T>;
 tmp->item = newItem;
 tmp->next = head;
 head = tmp;
 length++;
}

template <typename T>
bool List<T>::IsEmpty() const
{
 if (length == 0)
  return true;
 return false;
}


template <typename T>
int List<T>::GetLength() const
{
 return 0;
}


template <typename T>
T List<T>::GetItemH() const
{
 return head->item; 
}

template <typename T>
void List<T>::DeleteItemH()
{
}

template <typename T>
void List<T>::Print() const
{
 node<T>* tmp = head;
 int ct = 0;
 while (ct < length)
 {
  cout << tmp->item << endl;
  tmp = tmp->next;
  ct++;
 } 
	
}
template <typename T>
int List<T>::Find(const T item) const
{
 return -1;
}

template <typename T>
void List<T>:: DeleteItem(const int pos)
{
}
