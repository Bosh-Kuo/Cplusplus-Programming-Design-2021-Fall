// ============================================
// Pointers (p. 38)

#include <iostream>
using namespace std;

int *firstNeg(int a[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            return &a[i];
    } // what if a[i] >= 0 for all i?
}
int main()
{
    int a[5] = {0};
    for (int i = 0; i < 5; i++)
        cin >> a[i];
    int *p = firstNeg(a, 5);
    cout << *p << " " << p << "\n";
    return 0;
}
