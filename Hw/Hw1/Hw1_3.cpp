#include <iostream>
using namespace std;

int main()
{
    int m, n, TA, Prof, count = 0;
    cin >> n >> m;
    TA = n / m;
    Prof = n % m;

    if (TA <= 0) // 無TA狀況
    {
        cout << 1;
    }

    else // 有TA狀況
    {
        // 印出助教負責學生的筆頭編號
        while (count < TA)
        {
            // 第二個印出數字後需要用 ","間隔
            if (count != 0)
            {
                cout << "," << (count * m + 1);
                count++;
            }
            // 第一個印出數字前不需要用 ","間隔
            if (count == 0)
            {
                cout << (count * m + 1);
                count++;
            }
        }

        // 若老師有負責學生
        if (Prof != 0)
        {
            cout << "," << (TA * m + 1);
        }
    }
}