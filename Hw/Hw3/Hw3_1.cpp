#include <iostream>
using namespace std;

int main()
{
    int n, t;

    // 輸入n, t
    cin >> n >> t;
    int *x = new int[n];
    int max = 0, sum = 0, base = 0;

    // 輸入x[i]
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    // 找出最大值並且算平均數
    for (int i = 0; i < n; i++)
    {
        if (x[i] > max)
        {
            max = x[i];
        }

        if (x[i] >= t)
        {
            sum += x[i];
            base++;
        }
    }

    cout << max << "," << (base > 0 ? sum / base : -1);
}