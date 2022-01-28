#include <iostream>
using namespace std;

int main() 
{
    int m, n, TA, Prof, count = 0;
    cin >> n >> m;
    TA = n / m;
    Prof = n % m;

    // 無TA狀況
    if (TA <= 0)
    {
        cout << -1;
    }
    
    // 有TA狀況
    if (TA > 0)
    {
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
    }    
}