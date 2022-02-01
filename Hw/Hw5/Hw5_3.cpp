#include <iostream>
using namespace std;

const int MAX_N = 25, MAX_M = 100;

float score(int ssIndex, const bool subset[], const bool element[],
            const int costs[], const bool cover[][MAX_M], int ssCnt, int eleCnt)
{
    // ssIndex: 我們想計算其成本效益的子集合的index
    // ssCnt: 記錄共有幾個子集合
    // eleCnt: 記錄共有幾個元素

    if (subset[ssIndex])
        return 1000;

    // 找出該子集合還能包含過個為被包含的元素n
    int n = 0;
    for (int i = 0; i < eleCnt; i++)
    {
        if (cover[ssIndex][i] && !element[i])
            n++;
    }
    if (n == 0)
    {
        return 1000;
    }
    else
    {
        return static_cast<float>(costs[ssIndex]) / static_cast<float>(n);
    }
}

void update(int selectedIndx, const bool cover[][MAX_M], bool subset[], bool element[], int eleCnt)
{
    // 更新subset
    subset[selectedIndx] = true;

    // 更新element
    for (int i = 0; i < eleCnt; i++)
    {
        if (cover[selectedIndx][i] == true && !element[i])
            element[i] = true;
    }
}

int main()
{
    int n, m, ssLength, ele;            // 子集合的個數, 元素的個數, 該子集合長度, 元素代號
    bool cover[MAX_N][MAX_M] = {false}; // 記錄一個子集合是否包含一個元素
    int costs[MAX_N] = {0};             // 每個子集合的成本
    char set[MAX_N];                    // 子集合代號(大寫英文字母)
    bool subset[MAX_N] = {false};       // 記錄哪些子集合已經被選擇了
    bool element[MAX_M] = {false};      // 記錄哪些元素已經被選擇了
    bool first = true;

    // 輸入
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ssLength;
        for (int j = 0; j < ssLength; j++)
        {
            cin >> ele;
            cover[i][ele - 1] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i];
    }

    // 選子集合
    while (true)
    {
        int selectedIndx = 0;
        float bestScore = 1000;

        for (int i = 0; i < n; i++)
        {
            float revenue = score(i, subset, element, costs, cover, n, m);
            if (revenue < bestScore)
            {
                selectedIndx = i;
                bestScore = revenue;
            }
        }
        cout << (first ? "" : ",") << set[selectedIndx];
        update(selectedIndx, cover, subset, element, m);
        first = false;

        // 檢查是否結束
        int select_Cnt = 0;
        for (int i = 0; i < m; i++)
        {
            if (element[i])
                select_Cnt++;
        }
        if (select_Cnt == m)
            break;
    }
}