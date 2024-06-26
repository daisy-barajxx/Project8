/*
  Group Name: Daisy Barajas and Liya Tekie
  Class: CPSC 122, Section 1
  Date Submitted: March 22, 2024
  Descriptions: This program will test the functions of the List class.
*/

#include <iostream>
using namespace std;

#include "6-List.h"

int main()
{

 List* lst1 = new List; // dynamically allocating memeory for a list
 List lst; // statically allocating memory for a list
 
 cout << "IsEmpty test 1" << endl;
 cout << "Output 1" << endl;
 cout << lst1->IsEmpty() << endl; 
 cout << endl;
 

 
 cout << "GetLength test 1" << endl;
 cout << "Output 0" << endl;
 cout << lst1->GetLength() << endl; 
 cout << endl;
 

 cout << "PutItemH 1 thorugh 5 Static List" << endl;
 cout << "Output 5 through 1" << endl;
 for (int i = 1; i < 6; i++)
  lst.PutItemH(i); // put the items in the list accordingly to the most recent item which is 5 and moving up from there
 lst.Print(); // print the list

 cout << "PutItemH 1 thorugh 5 Dynamic List" << endl;
 cout << "Output 5 through 1" << endl;
 for (int i = 1; i < 6; i++)
  lst1->PutItemH(i); // done the same thing as the static list but with the dynamic list
 lst1->Print();

 
 cout << "IsEmpty test 2" << endl;
 cout << "Output 0" << endl;
 cout << lst1->IsEmpty() << endl; 
 cout << endl;
 


 cout << "GetLength test 2" << endl;
 cout << "Output 5" << endl;
 cout << lst1->GetLength() << endl; 
 cout << endl;
 

  
 cout << "GetItemH test 1" << endl;
 cout << "Output 5" << endl;
 cout << lst1->GetItemH()<< endl; 
 cout << endl;
 

 
 cout << "Print test 2" << endl;
 cout << "Output 5 through 1" << endl;
 lst1->Print(); 
 cout << endl;


 
 cout << "DeleteItemH test 1" << endl;
 cout << "Output 4 through 1" << endl;
 lst1->DeleteItemH(); // delete the first item in the list
 lst1->Print(); // print the list
 cout << endl;
 

 
 cout << "Find tests 1 through 4" << endl;
 lst1->Print(); // print the list in reverse order
 cout << "Output 1 " << endl;
 cout << lst1->Find(5) << endl; 
 cout << "Output 3" << endl;
 cout << lst1->Find(3) << endl;
 cout << "Output 5" << endl;
 cout << lst1->Find(1) << endl;
 cout << "Output -1" << endl; cout << lst1->Find(0) << endl;
  // should be 0
 cout << endl;

 delete lst1; // delete the list
 

 
 cout << "DeleteItem tests" << endl;
 List* lst2 = new List; // dynaically allocating memory for a list
 cout << "target is at head and elsewhere" << endl;
 cout << "output should be 2 0 2 3 2 0 3" << endl; 
 lst2->PutItemH(3);
 lst2->PutItemH(2);
 lst2->PutItemH(0);
 lst2->PutItemH(2);
 lst2->Print();
 cout << endl;
 cout << lst2->DeleteItem(2) << endl; 
 cout << endl;
 lst2->Print();
 cout << endl;

 cout << "target is followed by a target" << endl;
 cout << "output should be 2 1 0 3" << endl;
 lst2->PutItemH(2);
 lst2->PutItemH(2);
 lst2->PutItemH(1);
 cout << lst2->DeleteItem(2) << endl;
 cout << endl;
 lst2->Print();
 cout << endl;

 cout << "target is at tail" << endl;
 cout << "output should be 1 1 0" << endl;
 cout << lst2->DeleteItem(3) << endl;
 cout << endl;
 lst2->Print();

 cout << "target is at tail and just previous to tail" << endl;
 cout << "output should be 2 0" << endl;
 lst2->DeleteItem(0);
 lst2->DeleteItem(3);
 cout << endl;
 lst2->PutItemH(1);
 lst2->PutItemH(0);
 cout << endl;
 cout << lst2->DeleteItem(1) << endl;
 cout << endl;
 lst2->Print(); 
 delete lst2;


 return 0;
}