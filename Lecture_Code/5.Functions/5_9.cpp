// ============================================
// Functions (p. 44)

#include <iostream>
using namespace std;

int test();
int main()
{
  for(int a = 0; a < 10; a++)
    cout << test() << " "; 
  return 0; // 1, 1, ..., 1
} 
int test()
{
  int a = 0;
  a++;
  return a;
}