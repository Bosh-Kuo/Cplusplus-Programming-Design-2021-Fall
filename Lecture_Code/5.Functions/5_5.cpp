// ============================================
// Functions (p. 24)

#include <iostream>
using namespace std;

int test (int);

int main()
{
  cout << test(-1); 
  return 0;
}	

int test (int a)
{
  if (a > 0)
    return 5;
}