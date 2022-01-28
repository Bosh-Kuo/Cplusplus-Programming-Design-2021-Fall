// ============================================
// Variables and Arrays (p. 17)

#include <cmath>
#include <iostream>
using namespace std;

int main()
{

int bad = 0;
for(int i = 0; i < 100; i++)
{
  float f = sqrt(i);
  cout << f << " " << f * f << " ";
  
  if(f * f != i)
  {
    cout << "!!!";
    bad++;
  }
  cout << "\n";
}
cout << "bad precision: " << bad;
  return 0;
}
