#include <iostream>
using namespace std;

int main()
{
    int m, k;   // m 個學生, k 個科系(2)
    int n, d;   // 學號, 科系編號
    int a1, a2; // 保留的科系編號
    int select = 0;

    // 第一行輸入
    cin >> m >> k;

    // 第二行輸入
    for (int i = 0; i < m; i++)
    {
        cin >> n;
    }

    // 第三行輸入
    cin >> a1 >> a2;

    // 第四行輸入
    for (int i = 0; i < m; i++)
    {
        cin >> d;
        if (d == a1 || d == a2)
            select++;
    }

    cout << select;
}