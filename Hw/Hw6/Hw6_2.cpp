#include <iostream>
using namespace std;

int COUNT = 0;

void swap(int array[], int i, int j)
{
    int temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

void Permutation(int start, int end, int number[], int numCombination[])
{
    //得到全排列的一種情況，輸出結果
    if (start == end)
    {
        numCombination[COUNT] = number[0] * 100 + number[1] * 10 + number[2];
        // cout << numCombination[COUNT] << endl;
        COUNT++;
        return;
    }
    for (int i = start; i < end; i++)
    {
        swap(number, start, i);                              //交換
        Permutation(start + 1, end, number, numCombination); //分解為子問題a[start+1,...,end-1]的全排列
        swap(number, i, start);                              //回溯
    }
}

void sortNum(int number[])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (number[j] < number[j + 1])
                swap(number, j, (j + 1));
        }
    }
}

int main()
{
    int input, k, number[3], numCombination[6];
    cin >> input >> k;
    number[0] = input / 100;
    number[1] = (input % 100) / 10;
    number[2] = (input % 10);
    Permutation(0, 3, number, numCombination);
    sortNum(numCombination);
    cout << numCombination[k-1];
}