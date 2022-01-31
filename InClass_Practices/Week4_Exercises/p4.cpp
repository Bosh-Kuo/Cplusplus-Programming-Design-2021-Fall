#include <iostream>
using namespace std;

int highGradeCnt(int threshold, int gradeCnt, int grades[])
{
    int count = 0;
    for (int i = 0; i < gradeCnt; i++)
    {
        if (grades[i]>=threshold)
        {
            count+=1;
        }
    }
    return count;
}

int main()
{
    int n, t;
    int const MAX_N = 100;
    int x[MAX_N] = {0};
    cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << highGradeCnt(t, n, x);
}