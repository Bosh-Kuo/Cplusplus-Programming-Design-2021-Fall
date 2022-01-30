#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int S, best_s = 0, c_o, c_u, I, n; //訂貨目標, 貨量臨界, 單一存貨成本, 單一缺貨成本, 存貨量, n天
    cin >> S >> c_o >> c_u >> I;
    cin >> n;
    int *x = new int[n]; //單日需求量
    int inv, totalCost = 0, best_totalCost = INT_MAX;

    //輸入x
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    // 計算每個s
    for (int s = 0; s < S; s++)
    {
        totalCost = 0;
        inv = I;
        //計算每日成本
        for (int i = 0; i < n; i++)
        {
            inv -= x[i];
            if (inv >= 0)
            {
                totalCost += inv * c_o;
            }
            else
            {
                totalCost += abs(inv) * c_u;
            }

            if (inv <= s)
                inv = S;
        }
        if (totalCost < best_totalCost) {
            best_totalCost = totalCost;
            best_s = s;
        }
    }

    cout << best_s << "," << best_totalCost;
}