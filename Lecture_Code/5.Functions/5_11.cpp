// ============================================
// Functions (p. 46)

#include <iostream>
using namespace std;

int aaa[1000];
int test();

int main()
{
  for(int i = 0; i < 1000; i++)
    cout << aaa[i] << " ";
  for(int a = 0; a < 10; a++)
    cout << test() << " "; 
  return 0; 
} 
int test()
{
  static int a;
  a++;
  return a;
}