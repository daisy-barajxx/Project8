/* 
  Daisy Barajas and Liya Tekie 
  CPSC 122 
  February 27, 2024
  Description: The Substitution Cipher. The idea of this cipher
  is that the cryptographer chooses to shift amount between 
  1 - 25.
*/

#include <ctime> 
#include <fstream>
#include <cstdlib> 
#include <iostream>
using namespace std;

void keyGen(string keyFile);
char encrypt(char ch, int key);
char decrypt(char ch, int key);
void control(int mode, string keyFile, string input, string output);

int main(int argc, char* argv[])
{
 int mode;
 string keyFile, input, output;
  // check the number of command line arguments 
 if (argc != 3 && argc != 5) 
  {
    cout << "Incorrect number of command line arguments" << endl;
    exit(1);
  }

 mode = atoi(argv[1]);
 keyFile = argv[2];

  // if only 3 arguments are provided, generate a key and exit
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

// funciton to generate and write a key to a specified file
void keyGen(string keyFile)
{
    // generate a random key and display it
    unsigned seed = time(NULL);
    srand(seed);
    int key = rand() % 26;
    // open the file
    ofstream keyOut(keyFile);

    // write the key to the file
    cout << "Generated key: " << key << endl;
    keyOut << key << endl; 
    keyOut.close();
}

// function to control the encryption/decryption process
void control(int mode, string keyFile, string input, string output)
{
  // open the input, output and key files 
  ifstream fin(input);
  ofstream fout(output);
  ifstream fkey(keyFile);
  
  char ch;
  int key;
  fkey >> key; // read the key from the key file (fkey)
  
  // process each character of the input file
  while (fin.get(ch)) 
  {
    if (isalpha(ch)) 
    {
      if (mode == 1)
        ch = encrypt(toupper(ch), key);
      if (mode == 2)
        ch = decrypt(ch, key);
    }
    fout << ch;
  }
  
  // close the functions
  fin.close();
  fout.close();
  fkey.close();

  cout << "Done" << endl;
}

//encrypt ch and return encrypted version
char encrypt(char ch, int key)
{
  int pass = ch - 'A';
  pass = (pass + key) % 26;
  ch = pass + 'A';
 return ch;
}

//decrypt ch and return plaintext version
char decrypt(char ch, int key)
{
  ch = encrypt(ch, key);
  int pass = ch - 'A';
  // ensure positive result after subtraction
  pass = (pass - key + 26) % 26; 
  ch = pass + 'A'; 
 return ch;
}
