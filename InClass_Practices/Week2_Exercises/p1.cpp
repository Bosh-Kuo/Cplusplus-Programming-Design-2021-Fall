#include <iostream>
using namespace std;

int main()
{
    int gender, age;
    cin >> gender >> age;
    if (gender == 1)
    {
        if (age >= 18)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
    }
    else
    {
        if (age >= 16)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
    }
}