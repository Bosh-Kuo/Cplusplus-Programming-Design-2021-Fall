// ============================================
// Variables and Arrays (p. 35)

#include <iostream>
using namespace std;

int main()
{
  int score[5];
  for (int i = 0; i < 5; i++)
    cin >> score[i];
  for (int i = 0; i < 5; i++)
    cout << score[i] << " ";

  return 0;
}
