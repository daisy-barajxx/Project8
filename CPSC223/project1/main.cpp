/* 
Group Name: Jake K, Liya T, Kayu C, Daisy B
Class: CPSC223, Section 1
Date Submitted: 
Assignment: Managing and collecting tree shade data per block
Description: 
*/
#include <climits>
#include <iostream>
#include <string>

using namespace std;

#include "linked_list.cpp"

int main()
{
  int street_id;
  int block_num; 
  int tree_num;

  cout << "Welcome, you are in the Logan Neighborhood.\n";
  for (street_id != nullptr) {
  cout << "What street would you like to visit?\n";
  cout << "E Sharp Ave (Enter 1), E Sinto Ave (Enter 2), E Mission Ave (Enter 3), E Augusta Ave (Enter 4)";
  cout << " E Nora Ave (Enter 5), E Indiana Ave (Enter 6)\n";
  cin >> street_id;
    switch (street_id) {
      case '1':
        cout << "You are on the East side of Sharp Ave.\n";
        cout << "Would you like to see the number of trees on the block or exit the street?";
        cin >> block_num;
        
        break;
    }
    }
}