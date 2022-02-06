#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char sentence[1001];
    int punc = 0;
    cin.getline(sentence, 1001);

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (ispunct(sentence[i]))
            punc++;
    }
    cout << punc;
}
