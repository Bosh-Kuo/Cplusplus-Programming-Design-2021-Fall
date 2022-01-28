#include <iostream>
using namespace std;

int main()
{
    int input;
    cin >> input;

    do
    {
        if (input % 2 == 0)
        {
            input = input / 2;
        }
        else
        {
            input = input * 3 + 1;
        }
        cout << input << " ";
    } while (input != 1);
    // cout << input;
}