#include <iostream>
using namespace std;

void bubbleSort(const int unsorted[], int sorted[], int len, int ans[])
{
    for (int i = 0; i < len; i++)
        sorted[i] = unsorted[i];
    for (int i = len - 1; i > 0; i--) // here
    {
        int temp = ans[0];
        ans[1] = ans[1] + 1;
        for (int j = 0; j < i; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
                ans[0] = ans[0] + 1;
            }
        }
        if (ans[0] == temp)
            break;
    }
}

int main()
{
    int ans[2] = {0};  // ans[0]: 算總共做了幾次交換, ans[1]:在第幾圈外迴圈結束後可以判定排序完成
    const int MAX_N = 1000;
    int n, unsorted[MAX_N] = {0}, sorted[MAX_N] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> unsorted[i];
    }

    bubbleSort(unsorted, sorted, n, ans);
    cout << ans[0] << "," << ans[1];
}