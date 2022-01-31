#include <iostream>
#include <cmath>
using namespace std;

void bodyTemp(int n, int t[], int s[], double body_t[])
{
    for (int i = 0; i < n; i++)
    {
        body_t[i] = t[i] - 2 * sqrt(s[i]);
    }
}

int findMinOne(int n, double body_t[])
{
    double minBody_t = 1000, minIndex = 1;

    for (int i = 0; i < n; i++)
    {
        if (body_t[i] < minBody_t)
        {
            minBody_t = body_t[i];
            minIndex = i + 1;
        }
    }
    return minIndex;
}

int main()
{
    int n;
    int const MAX_N = 100;
    int t[MAX_N], s[MAX_N];
    double body_t[MAX_N] = {1000};

    // 輸入
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> s[i];
    }

    // 體感溫度
    bodyTemp(n, t, s, body_t);

    // 找出體感溫度最小時刻編號
    cout << findMinOne(n, body_t);
}