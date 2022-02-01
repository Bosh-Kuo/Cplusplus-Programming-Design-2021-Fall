// ============================================
// Algorithms (p. 29)

#include <iostream>
using namespace std;

void hanoi(char from, char via, char to, int disc);
int main()
{
    int disc = 0; // number of discs
    cin >> disc;
    char a = 'A', b = 'B', c = 'C';

    hanoi(a, b, c, disc);

    return 0;
}

void hanoi(char from, char via, char to, int disc)
{
    if (disc == 1)
        cout << "From " << from << " to " << to << "\n";
    else
    {
        hanoi(from, to, via, disc - 1);
        cout << "From " << from << " to " << to << "\n";
        hanoi(via, from, to, disc - 1);
    }
}