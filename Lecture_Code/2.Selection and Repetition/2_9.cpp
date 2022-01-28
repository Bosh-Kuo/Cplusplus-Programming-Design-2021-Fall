// ============================================
// Control Statements (p. 58)

#include <iostream>
using namespace std;

int main()
{
    for (int a = 1; a <= 100; a++)
    {
        if (a % 10 == 0)
            continue;
        cout << a << " ";
    }
    return 0;
}
