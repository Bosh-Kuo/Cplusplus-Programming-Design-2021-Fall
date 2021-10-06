// ============================================
// Control Statements (p. 59)

#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0;
    while(a <= 10)
    {
        while(b <= 10)
        {
            if(b == 5)
                break;
            cout << a * b << "\n";
            b++;
        }
        a++;
    }
    cout << a << "\n"; // ?
    return 0;
}
