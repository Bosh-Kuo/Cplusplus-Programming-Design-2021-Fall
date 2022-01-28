// ============================================
// Variables and Arrays (p. 47)

#include <iostream>
using namespace std;

int main()
{
  float value[10] = {0};
  for (int i = 0; i < 10; i++)
    cin >> value[i];

  float max = value[0];
  for (int i = 1; i < 10; i++)
  {
    if (value[i] > max)
      max = value[i];
  }
  cout << max;

  return 0;
}