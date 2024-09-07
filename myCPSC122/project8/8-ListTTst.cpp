#include <iostream>
using namespace std;

#include "8-ListT.h"

int main()
{
 //Static list 
 ListT lst;
  cout << lst.IsEmpty() << endl;
  cout << endl;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
  cout << "List before destorying the list: " << endl;
 lst.Print();
  cout << endl;
  
  cout << "List after deleting an item: " << endl;
  lst.Print();
  cout << endl;
/*
ListT lst2;
  for(int i = 5; i > 0; i--) 
    lst2.PutItemH(i);
  lst2.DeleteItemH();
  lst2.Print();
  cout << endl;
*/
 return 0;
}
