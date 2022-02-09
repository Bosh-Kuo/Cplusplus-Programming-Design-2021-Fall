// ============================================
// Self-defined data types (p. 22)

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  clock_t sTime = clock();
  for(int i = 0; i < 1000000000; i++)
    ;
  clock_t eTime = clock();
  
  cout << sTime << " " << eTime << "\n";
  return 0;
}