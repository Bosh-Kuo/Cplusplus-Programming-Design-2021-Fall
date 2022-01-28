#include <iostream>
using namespace std;

int main()
{
    int a, b, c, maxProfit=0, optimal_p=0;

    cin >> a >> b >> c;
    for (int p = c; p <= a / b; p++)
    {
        if ((a - b * p) * (p - c) > maxProfit)
        {
            maxProfit = (a - b * p) * (p - c);
            optimal_p = p;
        }
    }
    cout << optimal_p << " " << maxProfit;
}