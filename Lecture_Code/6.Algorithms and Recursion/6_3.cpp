// ============================================
// Algorithms (p. 18)

#include <iostream>
using namespace std;

double max(double array[], int len)
{
    if (len == 1) // stopping condition
        return array[len - 1];
    else
    {
        // recursive call
        double subMax = max(array, len - 1);
        if (array[len - 1] > subMax)
            return array[len - 1];
        else
            return subMax;
    }
}

int main()
{
    double a[5] = {5, 7, 2, 4, 3};
    cout << max(a, 5);
    return 0;
}