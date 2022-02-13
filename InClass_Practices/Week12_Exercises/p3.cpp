#include <iostream>
#include <string>
using namespace std;

string toDollarNumber(int dollar)
{
    string strDollar = to_string(dollar);
    string output = "$";
    int remain = strDollar.length();
    for (int i = 0; i < strDollar.length(); i++)
    {
        output += strDollar[i];
        if (remain % 3 == 1 && i != strDollar.length() - 1)
        {
            output += ",";
        }
        remain--;
    }
    return output;
}

int main()
{
    int dollar;
    string strDollar = "";
    cin >> dollar;
    strDollar = toDollarNumber(dollar);
    cout << strDollar;
}