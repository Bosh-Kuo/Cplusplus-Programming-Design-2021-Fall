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

bool mustSelect(int ssIndex, const bool subset[], const bool element[],
                const int costs[], const bool cover[][MAX_M], int ssCnt, int eleCnt)
{
    if (subset[ssIndex])
        return false;

    for (int ele = 0; ele < eleCnt; ele++)
    {
        if (cover[ssIndex][ele])
        {
            int count = 0;
            for (int i = 0; i < ssCnt; i++)
            {
                if (cover[i][ele])
                    count++;
            }
            if (count == 1)
                return true;
        }
    }
    return false;
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

void sort(char mustSelectSet[], int must_Cnt)
{
    if (must_Cnt < 2)
        return;
    for (int i = 0; i < must_Cnt; i++)
    {
        for (int j = 0; j < must_Cnt - i - 1; j++)
        {
            if (mustSelectSet[j] > mustSelectSet[j + 1])
            {
                char temp = mustSelectSet[j];
                mustSelectSet[j] = mustSelectSet[j + 1];
                mustSelectSet[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, m, ssLength, ele, must_Cnt = 0; // 子集合的個數, 元素的個數, 該子集合長度, 元素代號
    bool cover[MAX_N][MAX_M] = {false};    // 記錄一個子集合是否包含一個元素
    int costs[MAX_N] = {0};                // 每個子集合的成本
    char set[MAX_N];                       // 子集合代號(大寫英文字母)
    char mustSelectSet[MAX_N];
    bool subset[MAX_N] = {false};  // 記錄哪些子集合已經被選擇了
    bool element[MAX_M] = {false}; // 記錄哪些元素已經被選擇了
    bool first = true;
    bool must = true;

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

        // 先選必要子集合
        while (must)
        {
            for (int i = 0; i < n; i++)
            {
                if (mustSelect(i, subset, element, costs, cover, n, m))
                {
                    // cout << (first ? "" : ",") << set[i];
                    mustSelectSet[must_Cnt] = set[i];
                    update(i, cover, subset, element, m);
                    // first = false;
                    must_Cnt++;
                }
            }
            // 排序英文字母
            if (must_Cnt >= 2)
                sort(mustSelectSet, must_Cnt);
            
            // 印出字母
            for (int i= 0 ; i<must_Cnt;i++)
            {
                cout << (first ? "" : ",") << mustSelectSet[i];
                first = false;
            }
            must = false;
        }

        // 再選非必要子集合
        for (int i = 0; i < n; i++)
        {
            float revenue = score(i, subset, element, costs, cover, n, m);
            if (revenue < bestScore)
            {
                selectedIndx = i;
                bestScore = revenue;
            }
        }
        if (bestScore < 1000)
        {
            cout << (first ? "" : ",") << set[selectedIndx];
            update(selectedIndx, cover, subset, element, m);
            first = false;
        }

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