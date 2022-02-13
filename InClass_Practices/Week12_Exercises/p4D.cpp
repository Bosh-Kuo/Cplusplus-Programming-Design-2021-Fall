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
    string target_copy = target;
    turnLowercase(target);
    while (!file.eof())
    {
        getline(file, word);
        cout << "Comparing " << target_copy << " with " << word;
        turnLowercase(word);
        if(target == word)
        {
            find = true;
            cout << "... Got it!";
            break;
        }
        cout << endl;
    }
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