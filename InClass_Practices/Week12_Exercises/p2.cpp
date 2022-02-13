#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void turnLowercase(string& str)
{
    for(int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
}

void findInDict(string target, string *dict, int n)
{
    bool find = false;
    for (int i = 0; i < n; i++)
    {
        turnLowercase(target);
        if (target == dict[i])
        {
            find = true;
            break;
        }
    }
    cout << (find ? 1 : 0);
}


int main()
{
    int n;
    string target;
    cin >> n;
    cin >> target;

    string *dict = new string[n];
    for (int i=0; i<n;i++)
    {
        cin >> dict[i];
    }

    findInDict(target, dict, n);
    return 0;
}