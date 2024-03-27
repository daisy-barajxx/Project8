/*
Team Members: Daisy Barajas and Liya Tekie
Course: CPSC 122
Date Submitted: 02/27/24
Assignment Name: Project 4 
Description Program reads an unsorted file of strings. Sorts it. Writes it out 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countLines(string input);
void control(string input, string output, int numLines);

int main(int argc, char* argv[])
{
  if (argc != 3) 
  {
    cout << "Incorrect number of command line arguments" << endl;
    exit(1);
  }

  string input = argv[1]; // poemSort.in
  string output = argv[2]; // array.out

  int numLines = countLines(input);
  cout << numLines << endl; // number of lines in input file
  control(input, output, numLines); 
  // calls function to sort and write to output file
  return 0;
}

int countLines(string input)
{
  ifstream fin;
  fin.open(input);
  int ct = 0; // counter 
  string line;        
  while (fin.peek() != EOF)
  {
    getline(fin,line,'\n'); // reads in line
    ct++; // increments counter
  }
  fin.close(); 
  return ct;
}

void control(string input, string output, int numLines)
{
  string* arr = new string[numLines]; //initualize array to hold strings 
  string tmp;
  string line;

  ifstream fin;
  ofstream fout; 
  fin.open(input); // open input file 

  int idx = 0; // index for array
  while (fin.peek() != EOF)
    {
      getline(fin,line,'\n');
      arr[idx] = line; // reads in line
      idx++; // increments index
    }
  fin.close(); // closes input file

  for (int ct = 0; ct < numLines; ct++) // sorts array
    {
      for (int ct2 = ct + 1; ct2 < numLines; ct2++) // compares to next index
        {
          if (arr[ct].compare(arr[ct2]) > 0) // using (compare) for strings -- if first is greater than second
          {
            tmp = arr[ct]; // swaps
            arr[ct] = arr[ct2];
            arr[ct2] = tmp;
          }
        }
    }

  fout.open(output); // opens output file
  for (int ct = 0; ct < numLines; ct++) 
    {
      fout << arr[ct] << endl; // writes sorted array to output file
    }
  fout.close(); // closes output file
}

