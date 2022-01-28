// ============================================
// Functions (p. 41)

#include <iostream>
using namespace std;

int i = 5;

int main()
{
  for(; i < 20; i++)
    cout << i << " "; // ?
  cout << endl;
  int i = 2;
  cout << i << "\n";// ?
  cout << ::i << "\n"; // ?
  return 0;
} 