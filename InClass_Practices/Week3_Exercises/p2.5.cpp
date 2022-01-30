#include <iostream>
#include <cmath>
#include <iomanip> // for setprecision()
using namespace std;

int main()
{
    float a = 0.1, b = 0.2;
    cout << a + b << endl;
    cout << ((a == b) ? "true" : "false") << endl;
    cout << setprecision(10) << a + b;
}