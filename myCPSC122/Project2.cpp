/* 
  Daisy Barajas 
  CPSC 122 
  February 02, 2024
  Description: Transforms a digit string stored as a c-string to an int. 
  Input: c-string containing digits 
  Output: returns integer value of the digit string
*/

#include <iostream>
#include <fstream> 
#include <cstring>
#include <math.h> 
using namespace std;

int atoiMy(char str[]);
int toInt(char num);  


int main(int argc, char* argv[]) 
{
  int num1 = atoiMy(argv[1]);
  int num2 = atoiMy(argv[2]);
  int prod = num1 * num2;

  ofstream outputFile(argv[3]);
  outputFile << prod;
  outputFile.close();

  cout << "The product of the two digits is in file ";
  cout << argv[3] << endl;

  
  return 0;
}




int atoiMy(char str[]) 
{
  int num = 0;
  int len = strlen(str);
  int sum = 0;
  for (int i = 0; i < len; i++)
    {
      int exp = len - i - 1;
      num = num + toInt(str[i]) * pow(10, exp);
      sum = num;
      exp--;
    }
  num = toInt(str[0]); 
  num = sum;
  return sum;
}




int toInt(char num) 
{
  
  return num - '0';

}