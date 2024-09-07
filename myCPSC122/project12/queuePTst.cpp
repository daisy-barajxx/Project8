#include <iostream>
using namespace std;

#include "queueP.h"


int main()
{

 PQueue* que = new PQueue;
 
 for (int i = 5; i > 0; i--)
  que->Enqueue(i);
  que->Print();
  cout << endl << endl << endl;

  que->Dequeue();
  que->Print();
  cout << endl << endl << endl;
  
 delete que;
 
}
