#include <iostream>
using namespace std;

int findMax(int input)
{
    int number[3];
    number[0] = input / 100;
    number[1] = (input % 100) / 10;
    number[2] = (input % 10);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if(number[j]<number[j+1])
            {
                int temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            }
        }
    }
    return (number[0]*100 + number[1]*10 + number[2]);
}

int main()
{
    int input;
    cin >> input;
    cout << findMax(input);
}