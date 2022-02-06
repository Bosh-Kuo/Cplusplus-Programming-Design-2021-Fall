#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char sentence[1001], temp[1001];
    cin.getline(sentence, 1001);

    // 搜尋文字出現的起始位址指標
    char *location = strstr(sentence, "0");
    while (location != nullptr)
    {
        if (*(location - 1) == ' ' && (*(location + 1) == ' ' || ispunct(*(location + 1))))
        {
            strcpy(temp, location + 1);
            strcpy(location, "zero");
            strcpy(location + strlen("zero"), temp);
        }
        location = strstr(location + 1, "0");
    }
    cout << sentence;
}