#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

void turnLowercase(string &str)
{
    for (int i = 0; i < str.length(); i++)
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
    string target, fileName;
    cin >> n;
    cin >> target;
    cin >> fileName;

    string *dict = new string[n];
    ifstream file;
    file.open(fileName);
    if (file)
    {
        int i = 0;
        while (!file.eof())
        {
            getline(file, dict[i]);
        }
        findInDict(target, dict, n);
        file.close();
    }
    else
    {
        cout << "no file";
    }
    
    
    return 0;
}