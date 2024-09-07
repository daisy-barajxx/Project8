#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

template<typename T>
ListD<T>::ListD() 
{
 InitializeVars();
}

template<typename T>
ListD<T>::~ListD()
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
  cout << "Released the List" << endl;
}//done

template<typename T>
ListD<T>::ListD(ListD<T> &lst)
{
 InitializeVars();
 //returns a pointer to the first node, which is what we want here
 doubleNode<T> *cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
  {
  cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
  }
} //done

template<typename T>
void ListD<T>::InitializeVars()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}//done

template<typename T>
doubleNode<T> *ListD<T>::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
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
int ListD<T>::DeleteAll(T item)
{
  int ct = 0;
  doubleNode<T> *cur = head->next;
  while (cur != tail) 
  {
    if(cur->item == item) 
    {
      doubleNode<T> *tmp = cur;
      cur = cur->next;
      delete tmp;
      ct++;
      length--;
    } else {
      cur = cur->next;
    }
  }
  return ct;
} // done

