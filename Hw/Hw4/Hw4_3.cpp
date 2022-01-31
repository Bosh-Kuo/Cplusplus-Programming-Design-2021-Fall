#include <iostream>
using namespace std;

// 若有完整空座位就回傳座位index，否則回傳-1
int checkCompleteEmptySeat(int n, int start, int end, int sellChart[][15])
{
    int emptySeat = -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = start; j < end; j++)
        {
            if (sellChart[i][j] == 0)
            {
                count++;
            }
            else
            {
                break;
            }
        }

        // 若此座位在區間內都沒有人訂就回傳該座位index
        if (count == (end - start))
        {
            emptySeat = i;
            return emptySeat;
        }
    }
    return emptySeat;
}

// 若有零碎的座位可以提供該乘客就回傳true
bool checkeEmptySeat(int n, int start, int end, int sellChart[][15])
{
    bool empty = false;
    int count = 0;

    //檢查每一站是否還有空位
    for (int j = start; j < end; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (sellChart[i][j] == 0)
            {
                count++;
                break;
            }
        }
    }
    if (count == end - start)
    {
        empty = true;
    }
    return empty;
}

void fillSellChart(int n, int m, int k, int s[], int t[], int sellChart[][15])
{
    int completeSeat;
    bool emptySeat = false;
    for (int passenger = 0; passenger < k; passenger++)
    {
        // 1. 從第一個乘客開始，檢查是否有完整座位
        completeSeat = checkCompleteEmptySeat(n, s[passenger], t[passenger], sellChart);
        if (completeSeat != -1)
        {
            // 填入sellChart
            for (int j = s[passenger]; j < t[passenger]; j++)
            {
                sellChart[completeSeat][j] = passenger + 1;
            }
        }
        else
        {
            // 2. 若無完整座位，檢查是否有零碎座位
            emptySeat = checkeEmptySeat(n, s[passenger], t[passenger], sellChart);

            if (emptySeat)
            {
                for (int j = s[passenger]; j < t[passenger]; j++)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (sellChart[i][j] == 0)
                        {
                            sellChart[i][j] = passenger + 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m, k; // 座位、車站、乘客數
    int const MAX_N = 15, MAX_M = 15, MAX_K = 40;
    int s[MAX_K], t[MAX_K], sellChart[MAX_N][MAX_M] = {0};
    cin >> n >> m >> k;

    // 輸入s[], t[]
    for (int i = 0; i < k; i++)
    {
        cin >> s[i] >> t[i];
    }

    fillSellChart(n, m, k, s, t, sellChart);

    // 印出 sellChart
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << (j != 0 ? "," : "") << sellChart[i][j] << (j == m - 1 ? "\n" : "");
        }
    }
}