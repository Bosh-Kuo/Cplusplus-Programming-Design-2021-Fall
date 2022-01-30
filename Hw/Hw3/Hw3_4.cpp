#include <iostream>
using namespace std;

int main()
{
    int n, b = 0;
    bool first = true;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        b = 0;
        while (n % i == 0)
        {
            b += 1;
            n /= i;
        }

        if (b > 0)
        {
            if (!first)
            {
                if (b > 1)
                {
                    cout  << " * " << i << " ^ " << b;
                }
                else
                {
                    cout  << " * " << i;
                }
            }
            else
            {
                if (b > 1)
                {
                    cout << i << " ^ " << b;
                }
                else
                {
                    cout << i;
                }
                first = false;
            }
        }
    }
}