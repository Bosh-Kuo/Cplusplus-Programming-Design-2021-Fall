// ============================================
// Functions (p. 21)

#include <iostream>
using namespace std;

int add(int num1, int num2)
{
  return num1 + num2;
}
int main()
{
  double q1 = 10.5;
  double q2 = 20.7;
  double c = add(q1, q2 - 3); 
  cout << c << "\n";
  return 0;
}
