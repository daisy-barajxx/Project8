/* 
Group Name: Jake K, Liya T, Kayu C, Daisy B
Class: CPSC223, Section 1
Date Submitted: 
Assignment: Managing and collecting tree shade data per block
Description: Program illustrates a linked list both head and tail pointers 
*/
#ifndef LIST_H
#define LIST_H

typedef int itemType;

template<typename T>
struct doubleNode
{
 doubleNode* prev;
 T item;
 doubleNode* next;
};

template<typename T>
class ListD
{
  public: 
    ListD(); // an instance of ListT exists


    // the current object is an exact and deep copy of what lst points to 
    ListD(ListD<T> &lst); 

 
    // new node is inserted at postion pos. 
    void Insert(T item, int pos);   

    // find the position of an integer 
    int Search(const itemType target) const; 

    // node at postion, pos, is deleted 
    void Delete(int pos);    

    
    // The item value of each node, from head to tail, is displayed on the screen, excluding the dummy nodes. 
    void PrintForward();

     
    // The item value of each node, from tail to head, is displayed on the screen, excluding dummy nodes.
    void PrintBackward();

    // returns the length of the tree distances
    int GetLength() const; 

    // contents of list nodes are displayed on subsequent lines, head to        tail 
    void Print() const; 

    // Nodes in the list are in ascending order. The algorithm used to put nodes in order is selection sort. Use the functions
     void Sort();

    // returns the number of nodes in the list that are stored
    int FindItem(const itemType target) const; 

  private:

    // Returnes inseriton point A (see the implemention of insert) used in inserting a node in a list
    doubleNode<T> *FindPosition(int pos);
   
    // Dummy nodes are created and private variables initialized
    void InitializeVars(); 

    int length;         //length of the list
    doubleNode<T> *head;   //points to the first dummy node 
    doubleNode<T> *tail;   //points to the last dummy node  
};
#endif

