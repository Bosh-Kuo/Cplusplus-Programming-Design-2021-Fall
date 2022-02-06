#include <iostream>
#include <cmath>
using namespace std;

int findShortestDist(int *u, int *v, int x, int y, int n)
{
    int distance = 400;
    for (int i = 0; i < n; i++)
    {
        if (abs(x - u[i]) + abs(y - v[i]) < distance)
        {
            distance = abs(x - u[i]) + abs(y - v[i]);
        }
    }
    return distance;
}

int main()
{
    int n, m, p, c; // 物流中心數,零售店數,售價,單位補貨成本
    int profit = 0, need = 0;
    cin >> n >> m >> p >> c;
    int *u = new int[n], *v = new int[n]; // 物流中心座標
    int *x = new int[m], *y = new int[m]; // 零售店座標
    int *D = new int[m];                  // 每家零售店的需求量

    // 輸入
    for (int i = 0; i < n; i++)
    {
        cin >> u[i] >> v[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> D[i];
    }

    // 1. 找出最近的物流中心
    for (int i = 0; i < m; i++)
    {
        int distance = findShortestDist(u, v, x[i], y[i], n);
        // 2. 檢查售價是否超過成本
        if (p - c * distance >= 0)
        {
            profit += (p - c * distance) * D[i];
        }
        else
        {
            need += D[i];
        }
    }

    cout << profit << "," << need;
}