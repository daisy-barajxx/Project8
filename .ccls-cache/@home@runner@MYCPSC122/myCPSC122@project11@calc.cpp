/*
  Team Name: Daisy Barajas and Liya Tekie
  Course: CPSC122
  Assignment: Project 11, Part 2
*/
#include "calc.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

// Write functions in this order.  Constructor and destructor will be built as
// the functions it invokes are written
Calc::Calc(const char *argvIn) {
  stk = new Stack();      // dynamically allocate a stack
  valueTbl = new int[26]; // allocating dynamic array
  valueIdx = 0;
  int len = strlen(argvIn);
  inFix = new char[len];
  strcpy(inFix, argvIn);
  postFix = new char[len];
  postFix[0] = '\0';

  if (!CheckTokens()) {
    cout << "CheckTokens test failed and is not balanced." << endl;
    exit(EXIT_FAILURE);
  }
  else
  cout << "CheckTokens is balanced." << endl;

  if (!CheckParens()) {
    cout << "CheckParens test failed and the number of parens are not balanced." << endl; exit(EXIT_FAILURE);
  }
  else
    cout << "CheckParens is balanced." << endl;

  Parse();
  InFixToPostFix();
  
}

// releasing dynamicaly allocated memory
Calc::~Calc() {
  delete stk;
  delete[] valueTbl;
  delete[] inFix;
  delete[] postFix;
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
  for (int i = 0; i < 26; i++)
    valueTbl[i] = 0;
}

int Calc::FindLast(int cur) {

  int last = cur;
  while (isdigit(inFix[last])) {
    last++;
  }
  return last - 1; // return last digit
}

void Calc::Parse() 
{
  cout << "Parse Invoked" << endl;

  char *input = new char[strlen(inFix)];
  strcpy(input, inFix);
  MakeValueTbl();
  int len = strlen(input);
  int i = 0; // initialize loop idx
  int j = 0;
  while (i < len) {
    if (isdigit(input[i])) {
      int last = FindLast(i);
      char *tmp = new char[last - i + 1];
      // cout << "i = " << i << "\t Last " << last-i + 1 << endl;
      int x;
      for (x = i; x <= last; x++) {
        //
        // cout << input[x] << endl;
        tmp[x-i] = input[x];
      }
      i = last;
      inFix[j] = 'A' + valueIdx;
      int num = atoi(tmp);
      valueTbl[valueIdx] = num;
      ++valueIdx;
    } else
      inFix[j] = input[i];
    i++;
    j++;
    // copying over the ( or )
  }
  inFix[j] = '\0';
  delete[] input;
}

void Calc::DisplayInFix() {
  cout << "InFix: " << inFix << endl;
}

void Calc::InFixToPostFix() 
{
  char ch;
  int i = 0;
  for (int j = 0; inFix[j] != '\0'; j++) 
  {
    ch = inFix[j];
    if (isdigit(ch) || isalpha(ch)) {
      postFix[i++] = ch;
    } else if (ch == '(') {
      stk->Push(ch);
    } else if (ch == '+' || ch == '-' || ch == '*') {
      stk->Push(ch);
    } else if (ch == ')') {
      while (!stk->IsEmpty() && stk->Peek() != '(') 
      {
        postFix[i++] = stk->Peek();
        stk->Pop();
      }
      stk->Pop();
    }
  }
  postFix[i] = '\0';
}

void Calc::DisplayPostFix() { 
  cout << "PostFix: " << postFix << endl; 
}

int Calc::Evaluate() 
{
  InFixToPostFix(); // Convert infix expression to postfix
  char ch;
  int op1, op2;
  for (int i = 0; postFix[i] != '\0'; i++) 
  { // Loop through the postfix expression
    ch = postFix[i];
    if (isalpha(ch)) 
    {
      stk->Push(valueTbl[ch - 'A']); // Push the value of the variable onto the stack
    } else if (isdigit(ch)) {
      stk->Push(ch - '0'); // Push the digit onto the stack
    } else if (ch == '+' || ch == '-' || ch == '*') {
      op2 = stk->Pop();
      op1 = stk->Pop();
      switch (ch) { // for the different cases 
      case '+':
        stk->Push(op1 + op2);
        break;
      case '-':
        stk->Push(op1 - op2);
        break;
      case '*':
        stk->Push(op1 * op2);
        break;
      }
    }
  }
  int result = stk->Pop();
  return result; // Return the final result
}