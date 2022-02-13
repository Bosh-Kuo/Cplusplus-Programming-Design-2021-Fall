#include <iostream>
#include <string>
using namespace std;

int countPunc(string input, string punc)
{
    int count = 0;
    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < punc.length(); j++)
        {
            if (input[i] == punc[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}
int main()
{
    string input;
    getline(cin, input);
    cout << countPunc(input, ",.:;!?");
    return 0;
}