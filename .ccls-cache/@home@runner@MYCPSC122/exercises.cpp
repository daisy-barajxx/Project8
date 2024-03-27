#include <iostream> 
using namespace std; 
int encrypt(char ch, int key);
int main()
{
  char ch = 'A';
  int encryptionKey = 3;
  char encryptedChar = encrypt(ch, encryptionKey);
  cout << "Original Character: " << ch << endl;
  cout << "Encrypted Character: " << encryptedChar << endl;
  return 0;
}
int encrypt(char ch, int key)
{
  int pos = ch - 'A';
  pos = (pos + key) % 26;
  ch = pos + 'A';
  return ch;
}