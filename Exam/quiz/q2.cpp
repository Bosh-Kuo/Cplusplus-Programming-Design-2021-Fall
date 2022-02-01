#include <iostream>
using namespace std;

int main()
{
    int n, q;
    int const MAX_N = 100;
    int p[MAX_N], x[MAX_N];
    cin >> n >> q;

    // 輸入
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (x[i] == 0)
        {
            if (p[i] <= q / 2)
            {
                q -= p[i];
            }
        }
        else if (x[i] == 1)
        {
            if (p[i] <= q)
            {
                q -= p[i];
            }
        }
        cout << (i == 0 ? "" : ",") << q;
    }
}