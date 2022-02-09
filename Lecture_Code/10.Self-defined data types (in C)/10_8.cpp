// ============================================
// Self-defined data types (p. 42)

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  srand(time(0)); 
  int rn = 0;
  for(int i = 0; i < 10; i++)
  {
    rn = ((rand() % 10)) + 100;
    cout << rn << " ";
  }
  return 0;
}

