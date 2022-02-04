// ref: https://openhome.cc/zh-tw/algorithm/numbers/bigint/
#include <iostream>
using namespace std;

const int MAX_N = 101;

// 找出輸入char陣列的長度
int strlen(char str[])
{
    int i = 0;
    for (; str[i] != '\0'; i++)
        ;
    return i;
}

// 字元轉整數
int charToDigit(char a)
{
    return a - '0';
}

// 轉為補數陣列
void toComp(int *num, const int SPACE)
{
    int carry = 0;
    for (int i = SPACE - 1; i >= 0; i--)
    {
        if (i == SPACE - 1)
            num[i] = 9 - num[i] + 1;
        else
            num[i] = 9 - num[i] + carry;

        if (num[i] >= 10)
        {
            num[i] = num[i] - 10;
            carry = 1;
        }
        else
            carry = 0;
    }
}

// 將char陣列轉為int陣列做運算
void toIntArray(char str[], int *num, int strLen, const int SPACE)
{
    int charIdx = strLen - 1;

    // 不論正或負先轉成int陣列
    for (int i = SPACE - 1; i >= 0; i--)
    {
        if (charIdx >= 0 && str[charIdx] != '-')
        {
            num[i] = charToDigit(str[charIdx]);
        }
        else
        {
            num[i] = 0;
        }
        charIdx--;
    }

    // 若為負數，轉成補數陣列
    if (str[0] == '-')
    {
        toComp(num, SPACE);
    }
}

void bigMoneyAdd(int *num1, int *num2, int *sum, const int SPACE)
{
    int carry = 0;
    for (int i = SPACE - 1; i >= 0; i--)
    {
        sum[i] = num1[i] + num2[i] + carry;
        if (sum[i] < 10)
        {
            carry = 0;
        }
        else
        {
            sum[i] = sum[i] - 10;
            carry = 1;
        }
    }
}

void bigMoneySub(int *num1, int *num2, int *diff, const int SPACE)
{
    int borrow = 0;
    for (int i = SPACE - 1; i >= 0; i--)
    {
        diff[i] = num1[i] - num2[i] - borrow;
        if (diff[i] >= 0)
        {
            borrow = 0;
        }
        else
        {
            borrow = 1;
            diff[i] = diff[i] + 10;
        }
    }
}

void print(int *num, const int SPACE)
{
    cout << "$";
    if (num[0] == 9)
    {
        cout << "-";
        toComp(num, SPACE);
    }

    bool start = false;
    for (int i = 0; i < SPACE; i++)
    {
        if (num[i] != 0)
            start = true;
        if (start)
        {
            int digit = SPACE - i;
            cout << num[i] << ((digit % 3 == 1 && digit > 3) ? "," : "");
        }
    }

    // 0
    if (!start)
        cout << num[SPACE - 1];
}

int main()
{
    int n;
    char m1[MAX_N], m2[MAX_N];
    cin >> n >> m1 >> m2;
    const int SPACE = n + 1; // int array 大小(第一格表示位數)
    int *num1 = new int[SPACE], *num2 = new int[SPACE], *sum = new int[SPACE], *diff = new int[SPACE];

    // 轉為 int 陣列
    toIntArray(m1, num1, strlen(m1), SPACE);
    toIntArray(m2, num2, strlen(m2), SPACE);

    // 大數加減
    bigMoneyAdd(num1, num2, sum, SPACE);
    bigMoneySub(num1, num2, diff, SPACE);

    // 印出答案
    print(sum, SPACE);
    cout << '\n';
    print(diff, SPACE);
}