// ============================================
// Control Statements (p. 37)

#include <iostream>
using namespace std;

int main()
{
    int exit = 0;
    // do something
    cout << "Press 1 to exit: ";
    cin >> exit;

    while (exit != 1)
    {
        // do something
        cout << "Press 1 to exit: ";
        cin >> exit;
    }
    return 0;
}
