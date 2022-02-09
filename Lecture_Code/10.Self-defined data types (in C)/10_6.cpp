#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    srand(0);
    int rn = 0;
    for (int i = 0; i < 10; i++)
    {
        rn = rand();
        cout << rn << " ";
    }
    return 0;
}
