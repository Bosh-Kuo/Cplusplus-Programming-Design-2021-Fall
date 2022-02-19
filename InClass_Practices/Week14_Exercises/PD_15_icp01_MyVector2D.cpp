#include <iostream>
using namespace std;

class MyVector2D
{
private:
  int x;
  int y;
public:
  MyVector2D() : x(0), y(0) {}
  MyVector2D(int x, int y) : x(x), y(y) {} 
  void print() const;   
  bool operator==(const MyVector2D& v) const;
};

void MyVector2D::print() const 
{
  cout << "(" << this->x << ", " << this->y << ")\n";
}
bool MyVector2D::operator==(const MyVector2D& v) const
{
  if(this->x == v.x && this->y == v.y)
    return true;
  else
    return false;
}







int main()
{
  MyVector2D u(1.2, 2.3);
  MyVector2D v(1.4, 2.6);
  u.print();
  v.print();
  
  if(u == v)
    cout << "Equal!\n";
  else
    cout << "Unequal!\n";
  
  return 0;
}






