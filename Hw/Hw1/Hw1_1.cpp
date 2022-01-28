#include <iostream>
using namespace std;

int main() 
{
    int m, n, TA, Prof;
    cin >> n >> m;
    TA = n/m;
    Prof = n%m;
    cout << TA << "," << Prof;
}