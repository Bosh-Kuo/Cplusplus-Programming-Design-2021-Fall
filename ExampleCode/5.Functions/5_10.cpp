// ============================================
// Functions (p. 44)

#include <iostream>
using namespace std;

int test();
int main()
{
  for(int a = 0; a < 10; a++)
    cout << test() << " "; 
  return 0; // ?
} 
int test()
{
  static int a = 0;
  a++;
  return a;
}