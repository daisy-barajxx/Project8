/* 
Group Name: Jake K, Liya T, Kayu C, Daisy B
Class: CPSC223, Section 1
Date Submitted: 
Assignment: Managing and collecting tree shade data per block
Description: implementations and tests for the search, delete, insert, and print
*/

#include <climits>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "linked_list.cpp"

template <typename T> void TestInsert();
template<typename T> void TestDelete();
template<typename T> void TestSearch();
template<typename T> void TestPrint();

int main()
{
  TestInsert<int>();
  TestDelete<int>();
  TestSearch<int>();
  TestPrint<int>();
}

template <typename T>
void TestInsert() {
  ListD<T> *lst = new ListD<T>;
  for (int i = 1; i <= 5; i++)
    lst->Insert(i,i);

  cout << "Test general case insert: \n";
  cout << "Passes Insert Test 1 if 1 - 5 appear on subsequent lines \n";
  lst->PrintForward();
  cout << endl;

  cout << "test insert at the head" << endl;
  cout << "Passed Insert Test 2 if 0 appears in position 1" << endl;
  lst->Insert(0, 1);
  lst->PrintForward();
  cout << endl;

  cout << "test insert at the tail" << endl;
  cout << "Passed Insert Test 3 if 100 appears in final position" << endl;
  lst->Insert(100, 7);
  lst->PrintForward();
  cout << endl;

  cout << "test insert within the list" << endl;
  lst->Insert(50, 5);
  cout << "Passed Insert Test 4 if 50 appears in middle position" << endl;
  lst->PrintForward();
  cout << endl;
}

template <typename T> 
void TestDelete() {
  ListD<T> *lst2 = new ListD<T>;
  int i, j = 0;
  while (i <= 10) {
    lst2->Insert(i, i);
    i++;
  }

  cout << "Before delete: \n";
  lst2->Sort();
  lst2->PrintForward();

  // Attempt to delete elements that may or may not exist
  cout << "Attempting to delete element 3, 6, 9:\n";
  lst2->Delete(3); // deletes 3
  lst2->Delete(5); // deletes 6
  lst2->Delete(7); // deletes 9

  cout << "List after element deletion:\n";
  lst2->Sort();
  lst2->PrintForward();
}