#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void strToLower(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]) && isupper(str[i]))
            str[i] = tolower(str[i]);
    }
}

int main()
{
    int n, count = 0;
    char x[51];
    cin >> n;
    cin >> x;
    strToLower(x);

    // 輸入
    char **D = new char *[n];
    for (int i = 0; i < n; i++)
    {
        D[i] = new char[51];
        cin >> D[i];
        strToLower(D[i]);
        if (strcmp(D[i], x) == 0)
            count++;
    }
    cout << (count > 0 ? 1 : 0);
}