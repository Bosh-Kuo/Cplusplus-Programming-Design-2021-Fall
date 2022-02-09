// ============================================
// Self-defined data types (p. 14)
#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};
int main()
{
    Point a[10];
    cout << sizeof(Point) << " " << sizeof(a) << "\n";
    cout << &a << "\n";
    for (int i = 0; i < 10; i++)
        cout << &a[i] << " " << &a[i].x << " " << &a[i].y << "\n";
    Point *b = new Point[20];
    cout << sizeof(b) << "\n";
    delete[] b;
    b = NULL;
    return 0;
}