#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(nullptr)); // good
    int rn = 0;
    for (int i = 0; i < 10; i++)
    {
        rn = rand();
        cout << rn << " ";
    }
    return 0;
}
