
#include "calc.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
 Calc* C = new Calc(argv[1]);
  
C->DisplayInFix();
 delete C;
 return 0;
}
// g++ -o calc calcTst.o calc.o stack2.o list.o
