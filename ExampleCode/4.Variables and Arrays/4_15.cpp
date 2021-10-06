// ============================================
// Variables and Arrays (p. 58)

#include <iostream>
using namespace std;

int main()
{
  int a[2][3];
  cout << a << " " << a[0] << " " << &a[1] << " " << &a[1][0] << endl;

  return 0;
}