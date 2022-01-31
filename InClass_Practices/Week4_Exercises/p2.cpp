#include <iostream>
using namespace std;

int min(int a, int b)
{
    return (a <= b ? a : b);
}

int gcd(int a, int b)
{
    int GCD = 1;
    int minOne = min(a, b);
    for (int i = 1; i <= minOne; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            GCD = i;
        }
    }
    return GCD;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}