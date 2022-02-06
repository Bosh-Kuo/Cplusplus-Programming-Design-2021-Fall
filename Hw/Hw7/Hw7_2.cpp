#include <iostream>
using namespace std;

int scan(int size, int **A, int n)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n - size + 1; i++)
    {
        for (int j = 0; j < n - size + 1; j++)
        {
            sum = 0;
            for (int k = i; k < i + size; k++)
            {
                for (int l = j; l < j + size; l++)
                {
                    sum += A[k][l];
                }
            }
            if (sum == 0)
                count++;
        }
    }
    return count;
}

int main()
{
    int n, count = 0, sum = 0; // ans[0]:和為零的方形子矩陣個數, ans[1]:矩陣和
    cin >> n;
    int **A = new int *[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            sum += A[i][j];
        }
    }

    // 1x1 ~nxn
    for (int i = 1; i <= n; i++)
    {
        count += scan(i, A, n);
    }
    cout << count << "," << sum;
}