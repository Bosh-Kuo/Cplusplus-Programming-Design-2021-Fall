#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomAlgorithm(int *r, int n)
{
    for (int i = 0; i < n; i++)
    {
        r[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        int changeIdx = rand() % n;
        int temp = r[i];
        r[i] = r[changeIdx];
        r[changeIdx] = temp;
    }
}
int main()
{
    srand(time(nullptr));
    int n;
    cin >> n;

    int *r = new int[n];
    randomAlgorithm(r, n);
    for (int i = 0; i < n; i++)
    {
        cout << r[i];
    }
    delete[] r;
}