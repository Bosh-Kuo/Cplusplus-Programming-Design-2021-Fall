#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    for (int x = 0; x < 6; x++)
    {
        for (int y = 0; y < 6; y++)
        {
            if (x == x1 || y == y1 || x == x2 || y == y2 || x == x3 || y == y3 || (abs(x - x1) == abs(y - y1)) ||
                (abs(x - x2) == abs(y - y2)) || (abs(x - x3) == abs(y - y3)))
                ;
            else
            {
                cout << x << " " << y << endl;
            }
        }
    }
}