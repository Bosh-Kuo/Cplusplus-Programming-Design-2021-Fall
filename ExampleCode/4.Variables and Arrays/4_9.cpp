// ============================================
// Variables and Arrays (p. 38)

#include <iostream>
using namespace std;

int main()
{
  int array[100];

  for (int i = 0; i < 100; i++)
  {
    cout << array[i] << " ";
    if (i % 10 == 9)
      cout << "\n";
  }

  return 0;
}
