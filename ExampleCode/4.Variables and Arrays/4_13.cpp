// ============================================
// Variables and Arrays (p. 56)

#include <iostream>
using namespace std;

int main()
{
  int a[2][3] = {{1, 2, 3}, {1, 2, 3}};
  int b[2][3] = {{4, 5, 6}, {7, 8, 9}};
  int c[2][3] = {0};

  for (int i = 0; i < 2; i++) // matrix addition
    for (int j = 0; j < 3; j++)
      c[i][j] = a[i][j] + b[i][j];

  for (int i = 0; i < 2; i++) // print out c
  {
    for (int j = 0; j < 4; j++)
      cout << c[i][j] << " ";
    cout << "\n";
  }

  return 0;
}