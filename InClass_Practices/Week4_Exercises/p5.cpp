#include <iostream>
using namespace std;

int mostHighGrades(int threshold, int assignmentCnt, int gradeCnt, int grades[][50]);

int main()
{
    int m, n, t;
    int const MAX_M = 10, MAX_N = 50;
    int x[MAX_M][MAX_N];

    cin >> m >> n >> t;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x[i][j];
        }
    }
    cout << mostHighGrades(t, m, n, x);
}

int mostHighGrades(int threshold, int assignmentCnt, int gradeCnt, int grades[][50])
{
    int assignmentID = 1;
    int count = 0, maxCount = 0;

    for (int i = 0; i < assignmentCnt; i++)
    {
        count = 0;
        for (int j = 0; j < gradeCnt; j++)
        {
            if (grades[i][j] >= threshold)
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            assignmentID = i + 1;
        }
    }
    return assignmentID;
}