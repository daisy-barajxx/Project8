#include <iostream>
using namespace std;

#include "list.h"

int main() {
  List *lst1 = new List;

  for (int i = 1; i <= 10; i++)
    lst1->PutItemH(i);
  cout << "Print: \n";
  lst1->Print();
  cout << endl;

  cout << "Print in Reverse: \n";
  lst1->PrintRev();
  cout << endl;

  cout << "Length: " << lst1->GetLength() << endl;
  delete lst1;
  return 0;
}
