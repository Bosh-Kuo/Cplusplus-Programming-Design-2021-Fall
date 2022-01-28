#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3;                            // 學號
    int d1, d2, d3;                            // 科系
    int a1, a2;                                // 保留科系
    int check;                                 // 輸出人數
    int ans1 = 9999, ans2 = 9999, ans3 = 9999; //依序輸出的學號

    cin >> n1 >> n2 >> n3;
    cin >> d1 >> d2 >> d3;
    cin >> a1 >> a2;

    if (d1 == a1 || d1 == a2)
    {
        check += 1;
        ans1 = n1;
    }
    if (d2 == a1 || d2 == a2)
    {
        check += 1;
        ans2 = n2;
    }
    if (d3 == a1 || d3 == a2)
    {
        check += 1;
        ans3 = n3;
    }

    // sort
    if (ans1 > ans2)
    {
        int temp = ans1;
        ans1 = ans2;
        ans2 = temp;
    }

    if (ans2 > ans3)
    {
        int temp = ans2;
        ans2 = ans3;
        ans3 = temp;
    }

    if (ans1 > ans2)
    {
        int temp = ans1;
        ans1 = ans2;
        ans2 = temp;
    }

    if (ans1 > 1000)
    {
        cout << -1;
    }
    else
    {
        cout << ans1;
        if (ans2 <= 1000)
        {
            cout << "," << ans2 ;
        }
        if (ans3 <= 1000)
        {
            cout << "," << ans3 ;
        }
    }
}