
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
 ifstream fin;
 ofstream fout;
 int num, inp[50];

 fin.open(argv[1]);
 fout.open(argv[2]);

 num = 0;
 int* Arr = new int[inp[num]];
 while(fin >> num) 
  Arr = Arr + num;

 fout << Arr << endl;

 fin.close();
 fout.close(); 

 return 0;
}