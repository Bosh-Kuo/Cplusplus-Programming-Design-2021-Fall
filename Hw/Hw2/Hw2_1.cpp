#include <iostream>
using namespace std;

int main()
{
    int x, p1, p2, p3, y;
    int first = 0, second = 0, third = 0, remain;
    cin >> x >> p1 >> p2 >> p3 >> y;
    remain = x;

    // 買p1元的蔥抓餅
    if (remain >= p1)
    {
        first += 1;
        remain -= p1;
    }

    // 買p2元的葡萄柚綠茶
    if (remain >= p2)
    {
        second += 1;
        remain -= p2;
    }

    // 買p3元的水煎包
    if (remain >= p3 * y)
    {
        third += y;
        remain -= p3 * y;
    }
    else
    {
        third += remain / p3;
        remain -= third * p3;
    }
    cout << first << "," << second << "," << third << "," << remain;
}