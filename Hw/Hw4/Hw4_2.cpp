#include <iostream>
#include <cmath>
using namespace std;

void sum(int n, int m, int t, int x[][1000], int scores[])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (x[i][j] >= t)
            {
                scores[i] += x[i][j];
            }
        }
    }
}

int countLarger(int m, int s, int scores[])
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (scores[i] >= s)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n, m, t, s;
    cin >> n >> m >> t >> s;
    int const MAX_N = 1000, MAX_M = 1000;
    int x[MAX_M][MAX_N];
    int scores[MAX_M] = {0};

    // 輸入
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x[i][j];
        }
    }

    // 每每份作業分數總和
    sum(n, m, t, x, scores);

    cout << countLarger(m, s, scores);
}