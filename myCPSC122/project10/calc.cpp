/*
  Team Name: Daisy Barajas and Liya Tekie
  Course: CPSC122
  Assignment: Project 10, Part 1
*/
#include <iostream>
#include "calc.h"
#include <cstdlib> 
#include <cstring>
#include <fstream>

using namespace std;


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(const char *argvIn)
{
  stk = new Stack(); // dynamically allocate a stack 
  valueTbl = new int[26]; // allocating dynamic array
  valueIdx = 0;
  int len = strlen(argvIn);
  inFix = new char[len]; // allocating dynamic array
  strcpy(inFix, argvIn);
  if (!CheckTokens()) {
    cout << "CheckTokens test failed and is not balanced." << endl; 
    exit(EXIT_FAILURE);
  }
  else 
  cout << "CheckTokens is balanced." << endl; 
  
  if (!CheckParens()) {
    cout << "CheckParens test failed and the number of parens are not balanced." << endl;
    exit(EXIT_FAILURE);
  }
  else
    cout << "CheckParens is balanced." << endl;

  Parse();
} 

// releasing dynamicaly allocated memory
Calc::~Calc()
{
  delete stk;
  delete[] valueTbl; 
  delete[] inFix; 
} // done
 
bool Calc::CheckTokens()
{
  for (int i = 0; inFix[i] != '\0'; i++) {
    if(!(inFix[i] == '+'|| inFix[i] == '-' || inFix[i] == '*' 
      || inFix[i] == '(' || inFix[i] == ')' || 
      ((isalpha(inFix[i]) && isupper(inFix[i]))) || isdigit(inFix[i])))
    {
      cout << "Invalid Input" << endl;
      return false; 
    }
  }
  return true; 
}

bool Calc::CheckParens()
{
  bool bal = true; 
  int i = 0;
  char ch = inFix[i];
  while (bal && ch != '\0') 
    {
      if (ch == '(')
        stk->Push(ch);
      else if (ch == ')') 
      {
        if (!stk->IsEmpty())
          stk->Pop();
        else
          bal = false;
      }
      i++;
      ch = inFix[i];
    }
    if (bal && stk->IsEmpty())
      return true;
    return false;
}

void Calc::MakeValueTbl()
{
  valueIdx = 0;
  for (int i = 0; i < 26; i++)
  valueTbl[i] = 0;
}

int Calc::FindLast(int cur) 
{
  
  int last = cur;
  while (isdigit(inFix[last])) 
  {
    last++;
  }
  return last-1; // return last digit
}

void Calc::Parse()
{
  cout << "Parse Invoked" << endl;

  char* input = new char[strlen(inFix)];
  strcpy(input, inFix);
  MakeValueTbl();
  int len = strlen(input);
  int i = 0; // initialize loop idx
  int j = 0;
  while (i < len) 
  { 
    if (isdigit(input[i])) 
    {
      int last = FindLast(i);
      char* tmp = new char[last-i +1];
     //cout << "i = " << i << "\t Last " << last-i + 1 << endl;
      int x;
      for (x = i; x <= last; x++) 
      {
        //
       // cout << input[x] << endl;
        tmp[x] = input[x];
      }
      i = last;
      inFix[j] = 'A' + valueIdx;
      int num = atoi(tmp);
      valueTbl[valueIdx] = num;
      ++valueIdx;
    } 
    else 
      inFix[j] = input[i]; 
    i++;
    j++;
    // copying over the ( or )
  }
  inFix[j] = '\0';
  delete[] input;
  
}

void Calc::DisplayInFix()
{ 
  cout << "The Infix expression is: " << inFix << endl;
  //cout << "ValueTbl: " << valueTbl[0] << endl;
}

