// ============================================
// Self-defined data types (p. 32)
#include <iostream>
using namespace std;

struct Point
{
  int x;
  int y;	
  void reflect();
  void print();
};
void Point::reflect()
{
  int temp = x;
  x = y;
  y = temp;
}
void Point::print()
{
  cout << x << " " << y << "\n";
}
int main()
{
  Point a = {10, 20};
  Point b = {5, 2};
  a.print();
  b.print();
  a.reflect();
  a.print();
  b.print();
  return 0;
}