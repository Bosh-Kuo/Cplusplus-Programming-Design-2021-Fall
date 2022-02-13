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

void findInDict(string target, istream &file)
{
    bool find = false;
    string word;
    turnLowercase(target);
    while (!file.eof())
    {
        getline(file, word);
        turnLowercase(word);
        if(target == word)
        {
            find = true;
            break;
        }
    }
    cout << (find ? 1 : 0);
}

int main()
{
    string target, fileName;
    cin >> target;  //停在
    cin.ignore(); 
    getline(cin, fileName);

    ifstream file;
    file.open(fileName);
    if (file)
    {
        findInDict(target, file);
        file.close();
    }
    else
    {
        cout << "no file";
    }

    return 0;
}