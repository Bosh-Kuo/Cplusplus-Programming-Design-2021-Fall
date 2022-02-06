// ============================================
// C Strings (p. 4)
#include <iostream>
using namespace std;

int main()
{
  char c = '0';
  cout << static_cast<int>(c) << " ";
  c = 'A';
  cout << static_cast<int>(c) << " ";
  c = '\n';
  cout << static_cast<int>(c) << " ";
  return 0;
}

