// ============================================
// Functions (p. 48)

#include <iostream>
using namespace std;

void swap (int x, int y);
int main()
{
  int a = 10, b = 20;
  cout << a << " " << b << "\n";
  swap(a, b);
  cout << a << " " << b << "\n"; 
}	
void swap (int x, int y)
{
  int temp = x;
  x = y;
  y = temp;
}