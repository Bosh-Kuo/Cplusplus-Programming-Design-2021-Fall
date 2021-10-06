// ============================================
// Variables and Arrays (p. 39)

#include <iostream>
using namespace std;

int main()
{
  int daysInMonth1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int daysInMonth2[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  cout << sizeof(daysInMonth2);        // 4 * 12 = 48
  int daysInMonth3[12] = {31, 28, 31}; // nine 0s
  // int daysInMonth4[3] = {1, 2, 3, 4};  // error!

  return 0;
}
