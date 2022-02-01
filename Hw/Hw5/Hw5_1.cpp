#include <iostream>
using namespace std;

int const MAX_N = 20;
void calDegrees(int n, const int edges[][MAX_N], int degrees[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            degrees[i] += edges[i][j];
        }
    }
}

int main()
{
    int n, odd = 0;
    int degrees[MAX_N] = {0}, x[MAX_N][MAX_N] = {0};

    //輸入
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x[i][j];
        }
    }

    // 計算 degrees
    calDegrees(n, x, degrees);

    // 印出答案
    for (int i = 0; i < n; i++)
    {
        cout << (i == 0 ? "" : ",") << degrees[i];
        if (degrees[i] % 2 != 0)
            odd++;
    }
    cout << ";" <<(odd >= 4 ? 1 : 0);
}