#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char sentence_A [1001], sentence_B [1001];
    cin.getline(sentence_A, 1000);
    cin.getline(sentence_B, 1000);
    for (int i = 0; i < strlen(sentence_A); i++)
    {
        if (isalpha(sentence_A[i]) && isupper(sentence_A[i]))
        {
            sentence_A[i] = tolower(sentence_A[i]);
        }
    }
    for (int i = 0; i < strlen(sentence_B); i++)
    {
        if (isalpha(sentence_B[i]) && isupper(sentence_B[i]))
        {
            sentence_B[i] = tolower(sentence_B[i]);
        }
    }

    char* p = strstr(sentence_A, sentence_B);
    if (p!=nullptr)
        cout << 1;
    else
        cout << 0;
}   