#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int S, s, c_o, c_u, I, n; //訂貨目標, 貨量臨界, 單一存貨成本, 單一缺貨成本, 存貨量, n天
    cin >> S >> s >> c_o >> c_u >> I;
    cin >> n;
    int *x = new int[n]; //單日需求量
    int days = 0, totalCost = 0;

    //輸入x
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    //計算每日成本
    for (int i = 0; i < n; i++)
    {
        I -= x[i];
        if (I >= 0)
        {
            totalCost += I * c_o;
        }
        else
        {
            totalCost += abs(I) * c_u;
            days++;
        }

        if (I <= s)
            I = S;
    }
    cout << days << "," << totalCost;
}