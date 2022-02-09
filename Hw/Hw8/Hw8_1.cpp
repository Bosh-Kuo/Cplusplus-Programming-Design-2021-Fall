#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CHAR = 20 * 5;

int calculateScore(char *x, char *y)
{
    int score = 0;
    if (strcmp(x, y) == 0) // rule 1
        score = 10000;
    else
    {
        char *first = strstr(x, y);
        if (first != nullptr) // rule 2
        {
            score = 1000;
            while (first != nullptr)
            {
                score += 1;
                first = strstr(first + 1, y);
            }
        }
        else
        {

            for (int i = strlen(y); i >= 1; i--) // sub_y的長度
            {
                for (int j = 0; j <= strlen(y) - i; j++) // y copy 的起點
                {
                    char *sub_y = new char[i + 1];
                    for (int s = 0; s <= i; s++) // sub_y 從第一個位置複製
                    {
                        sub_y[s] = y[j + s];
                    }
                    sub_y[i] = '\0';
                    if (strstr(x, sub_y) != nullptr)
                    {
                        return i * 10;
                    }
                    delete[] sub_y;
                }
            }
        }
    }
    return score;
}

int main()
{
    int N;
    cin >> N;
    cin.get();
    char **str_X = new char *[N];
    char str_Y[MAX_CHAR + 1] = {0};

    // 輸入
    for (int i = 0; i < N; i++)
    {
        str_X[i] = new char[MAX_CHAR + 1];
        cin.getline(str_X[i], MAX_CHAR);
    }
    cin.getline(str_Y, MAX_CHAR + 1);

    for (int i = 0; i < N; i++)
    {
        cout << (i == 0 ? "" : ",") << calculateScore(str_X[i], str_Y);
    }
}
