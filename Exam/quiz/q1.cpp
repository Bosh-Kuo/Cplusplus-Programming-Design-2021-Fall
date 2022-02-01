#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b && a > 0)
    {
        cout << a + b;
    }
    else if (a == b && a <= 0)
    {
        cout << a * b;
    }
    else
    {
        cout << a - b;
    }
}