// ============================================
// Self-defined data types (p. 12)
#include <iostream>
using namespace std;

struct Point
{
  int x;
  int y;	
};
void reflect(Point& a)
{
  int temp = a.x;
  a.x = a.y;
  a.y = temp;
}
int main()
{
  Point a = {10, 20};
  cout << a.x << " " 
       << a.y << "\n";
  reflect(a);
  cout << a.x << " " 
       << a.y << "\n";
  return 0;
}