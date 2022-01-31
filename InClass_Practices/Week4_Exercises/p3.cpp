#include <iostream>
using namespace std;

int min(int a, int b, int c)
{
    return (a <= b ? (a <= c ? a : c) : (b <= c ? b : c));
}

int gcd(int a, int b, int c)
{
    int GCD = 1;
    int minOne = min(a, b, c);
    for (int i = 1; i <= minOne; i++)
    {
        if (a % i == 0 && b % i == 0 && c % i == 0)
        {
            GCD = i;
        }
    }
    return GCD;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << gcd(a, b, c);
}