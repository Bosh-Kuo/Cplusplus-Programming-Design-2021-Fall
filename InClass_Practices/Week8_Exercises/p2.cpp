#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char sentence[1001];
    bool space = true;
    cin.getline(sentence, 1001);

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (space && isalpha(sentence[i]) && islower(sentence[i]))
            sentence[i] = toupper(sentence[i]);
        else if (!space && isalpha(sentence[i]) && isupper(sentence[i]))
            sentence[i] = tolower(sentence[i]);

        if (sentence[i] == ' ')
            space = true;
        else
            space = false;
    }
    cout << sentence;
}
