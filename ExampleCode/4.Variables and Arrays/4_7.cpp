// ============================================
// Variables and Arrays (p. 18)

#include<iostream>
#include<cmath>
#include<iomanip> // for setprecision()
using namespace std;

int main()
{
  for(int i = 0; i < 100; i++)
  {
    float f = sqrt(i);
    cout << f << " " << setprecision(10) << f * f << " ";
    cout << "\n";
  }
  return 0;
}
