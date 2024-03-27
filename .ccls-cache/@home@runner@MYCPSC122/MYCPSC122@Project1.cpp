/*
  Daisy Barajas
  Date: 01/25/24
  Description: Determines whether input integer is prime
  Input: Integer whose primarily is to be judged 
  Returns: true if num is prime, false otherwise
  Output: 100 prime numbers in 5 columns
*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int);
void display(int, int);  //function prototype must be declared
                         //before use.  prototype includes
       //return type, function name, parameters type(s)



int main(int argc, char*argv[])
{
  int totalPrimes = atoi(argv[1]);
  int col = atoi(argv[2]);

  display(totalPrimes, col);
  
  return 0;
}

bool isPrime(int num) 
{
  int div = 2;
  while (div < num) {
    if (num % div == 0)
      return false; 
    else if (num % div != 0)
        div++;
  }
  return true; 
  //all odd numbers are primes
}

void display(int totalPrimes, int cols)
{
  int ct = 2;
  int rowCt = 0;
  int sum = 0;

   while (sum < totalPrimes)
    {
      if (isPrime(ct))
      {
        cout << ct << "\t";
        sum++;
        if (sum % cols == 0)
          cout << endl;
        rowCt++;
      }
      ct++;
    }
}