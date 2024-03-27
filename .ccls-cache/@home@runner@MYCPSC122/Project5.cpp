/*
Team Member 1: Daisy Barajas and Jaixin Bai
Course: CPSC 122
Date Submitted: 2/19/2024
Assignment Name: Project 5 
Description Program implements the Affine Cipher
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function prototypes
void keyGen(string keyFile);
char encrypt(char ch, int alpha, int beta);
char decrypt(char ch, int alpha, int beta, int MI[]);
void control(int mode, string keyFile, string input, string output);


int main(int argc, char* argv[])
{
 int mode;
 string keyFile, input, output;

  // check if the correct number of command line arguments is provided 
 if (argc != 3 && argc != 5) 
 {
    cout << "Incorrect number of command line arguments" << endl;
    exit(1);
 }

 mode = atoi(argv[1]);
 keyFile = argv[2];

  // if only 3 arguments are provide, generate a key and exit
 if (argc == 3)
  {
   keyGen(keyFile);
   return 0; 
  }
  // if 5 arguments are provided, read the input and output files and control the encryption/decryption 
 if (argc == 5)
  {
   input = argv[3];
   output = argv[4];
   control(mode, keyFile, input, output); 
  }

 return 0;
}

/*
Description: Generates and stores an integer key in the range [1..25]
Input: Name of output file
Output: none. Generated key is stored in the output file 
*/
void keyGen(string keyFile)
{
  const int LIMIT = 25;
  unsigned seed = time(NULL);
  srand(seed);
  int alpha, beta;
  ofstream keyOut(keyFile);

  bool more = true;
  while(more) 
    {
      beta = rand() % LIMIT;
      alpha = rand() % LIMIT + 1;
      if (alpha == 1 && beta == 0) 
        continue;
      if (alpha % 2 == 0 || alpha == 13)
        continue;
      keyOut << alpha << endl;
      keyOut << beta << endl;
      more = false;
    } 
  keyOut.close();
}

/*
Description; 
1 Opens keyfile and reads key 
2 Opens plaintext and ciphertext files 
3 Reads each character of the plaintext file 
4 If mode is 1 and the character is alphabetic, transforms it to upper case, encrypts it and writes it
  to the output file 
5 If mode is 2 and the character is alphabetic, decrypts it and writes it to output file
6 If the character is not alphabetic, writes it to the output file
7 Closes all three files
Input: Encrypt/decrypt mode, namkes of key file, input, and output files
Output: Writes encrypted/decrypted text to output file
*/
void control(int mode, string keyFile, string input, string output)
{
 //this is the array of multiplicative indices mod 26
 int MI[26] = {0,1,0,9,0,21,0,15,0,0,0,19,0,0,0,7,0,23,0,11,0,5,0,17,0};
  ifstream keyOut(keyFile);
  char ch; 
  int alpha, beta;

  // open and read key file
  keyOut.is_open();
  keyOut >> alpha;
  keyOut >> beta;
  keyOut.close();

  ifstream fin;
  ofstream fout;
  fin.open(input);
  fout.open(output);

  // process each character of the input file
  while (fin.get(ch))
    {
      if (isalpha(ch))
      {
        if (mode == 1)
          ch = encrypt(toupper(ch), alpha, beta);
        if (mode == 2)
          ch = decrypt(ch, alpha, beta, MI);
      }
      fout << ch;
    }
  fin.close();
  fout.close();
}


/*
Description: Encrypts a single character with key according to the rules for affine cipher
             encryption
Input: character to be encrypted with key
Output: returns encrypted character 
*/
char encrypt(char ch, int alpha, int beta)
{
  int pos = ch - 'A';
  pos = (pos * alpha + beta) % 26;
  ch = pos + 'A';
  return ch;
}

/*
Description: Decrypts a single character with key according to the rules for affine cipher
             decryption
Input: character to be decrypted with key
Output: returns decrypted character 
*/
char decrypt(char ch, int alpha, int beta, int MI[])
{
  alpha = MI[alpha]; // find multiplicative inverse
  int pos = ch - 'A';
  pos = (alpha * (pos - beta) + 26) % 26;
  ch = pos + 'A';
  return ch;
}


