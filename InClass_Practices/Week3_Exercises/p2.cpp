#include <iostream>
using namespace std;

int main()
{
    int y;
    int leap;
    cin >> y;
    if (y%4==0)
    {
        if (y%100==0 && y%400!=0)
        {
            leap = 0;
        }
        else
        {
            leap = 1;
        }
    }
    else
    {
        leap = 0;
    }
    cout << leap;
}