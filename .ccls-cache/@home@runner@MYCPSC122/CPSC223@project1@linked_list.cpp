/* 
Group Name: Jake K, Liya T, Kayu C, Daisy B
Class: CPSC223, Section 1
Date Submitted: 
Assignment: Managing and collecting tree shade data per block
Description: 
*/
#include <iostream>
#include <climits>

using namespace std;

#include "linked_list.hpp"

template<typename T>  
int ListD<T>::Search(const itemType target) const 
{
    doubleNode<T>* curr = head;
    int pos = 0;
    while(curr != nullptr && curr->item != target) {
      pos++;
      curr = curr->item; // curr == curr->next;
    }
    if (curr == nullptr || curr->item != target)
      return -1; 
    return (pos + 1);
}

template<typename T> 
void ListD<T>::Insert(T item, int pos)
{
  //create new node and set its values
  doubleNode<T> *tmp = new doubleNode<T>; 

 //new node goes between these two nodes
 doubleNode<T> *insertPtA = FindPosition(pos);  
 doubleNode<T> *insertPtB = insertPtA->next; 

 tmp->item = item;

 tmp->prev = insertPtA;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
} // done

template<typename T>
void ListD<T>::Delete(int pos)
{
  doubleNode<T> *ptA = FindPosition(pos);
  doubleNode<T> *ptB = ptA->next;
  doubleNode<T> *ptC = ptB->next;
  ptA->next = ptC;
  ptC->prev = ptB;
  delete ptB;
  length--;
} // done

template<typename T>
void ListD<T>::Print() const
{
 doubleNode<T>* cur = head;
 while(cur != NULL)
 {
  cout << cur->item << endl;
  cur = cur->next;
 }
}

template<typename T>
doubleNode<T> *ListD<T>::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than this.
 doubleNode<T> *cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} // done

template<typename T>
void ListD<T>::PrintForward()
{
 doubleNode<T> *cur = head->next;
 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
  cout << endl;
} //done

template<typename T>
void ListD<T>::PrintBackward()
{
  doubleNode<T> *cur = tail->prev;
  int i = 0;
  while (i < length)
  {
    cout << cur->item << endl;
    cur = cur->prev;
    i++;
  }
  cout << endl;
} // done

template<typename T> 
int ListD<T>::GetLength() const
{
  return length;
}

template<typename T>
void ListD<T>::Sort() 
{
  doubleNode<T> *cur = head->next;
  if (length == 1 || length == 0) 
  {
    cout << "List is sorted" << endl;
    return;
  }
  while (cur->next != nullptr)
  {
    doubleNode<T> *min = cur;
    doubleNode<T> *tmp = cur->next;
    while (tmp != nullptr)
    {
      if (tmp->item < min->item) 
      {
        min = tmp;
      }
      tmp = tmp->next;
    }
    itemType tmpM = cur->item;
    cur->item = min->item;
    min->item = tmpM;
    cur = cur->next;
  }
} //done