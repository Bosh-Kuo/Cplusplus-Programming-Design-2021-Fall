#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int *x = new int[m];
    int out;

    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i <= m - n; i++)
    {
        out = 0;
        for (int j = 0; j < n; j++)
        {
            out += x[i + j];
        }
        cout << out / n;
        if (i != m - n)
        {
            cout << ",";
        }
    }
}