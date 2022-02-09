#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAX_LEN 5001

// 定義 struct
typedef struct DistributionCenter
{
    int x;
    int y;
} DC;

typedef struct RetailStore
{
    int x;
    int y;
    int demand;
    int replenishment;
} RS;

// 清除字串中的廢數字或,的符號
void clearAphla(char *str_source, char *str_dest)
{
    int idx = 0;
    for (int i = 0; i < strlen(str_source); i++)
    {
        if (isdigit(str_source[i]) || str_source[i] == ',' || str_source[i] == '\0')
        {
            str_dest[idx] = str_source[i];
            idx++;
        }
    }
}

int findShortestDist(DC *centers, RS &store, int n)
{
    int distance = 400, min_x = 400, min_y = 400;
    for (int i = 0; i < n; i++)
    {
        if (abs(store.x - centers[i].x) + abs(store.y - centers[i].y) < distance)
        {
            distance = abs(store.x - centers[i].x) + abs(store.y - centers[i].y);
            store.replenishment = i + 1;
            min_x = centers[i].x;
            min_y = centers[i].y;
        }
        else if (abs(store.x - centers[i].x) + abs(store.y - centers[i].y) == distance)
        {
            if (centers[i].x < min_x)
            {
                distance = abs(store.x - centers[i].x) + abs(store.y - centers[i].y);
                store.replenishment = i + 1;
                min_x = centers[i].x;
                min_y = centers[i].y;
            }
            else if (centers[i].x == min_x && centers[i].y < min_y)
            {
                distance = abs(store.x - centers[i].x) + abs(store.y - centers[i].y);
                store.replenishment = i + 1;
                min_x = centers[i].x;
                min_y = centers[i].y;
            }
        }
    }
    return distance;
}

int main()
{
    int n, m, p, c; // 物流中心數,零售店數,售價,單位補貨成本
    int count = 0;
    char *digit;

    // 輸入第一行
    char *line1 = new char[MAX_LEN];
    char *line1_digit = new char[MAX_LEN];
    cin.getline(line1, MAX_LEN);
    clearAphla(line1, line1_digit);
    delete[] line1;

    digit = strtok(line1_digit, ",");
    while (digit != NULL)
    {
        if (count == 0)
        {
            n = atoi(digit);
        }
        else if (count == 1)
        {
            m = atoi(digit);
        }
        else if (count == 2)
        {
            p = atoi(digit);
        }
        else
        {
            c = atoi(digit);
        }
        digit = strtok(NULL, ",");
        count++;
    }

    DC *centers = new DC[n];
    RS *stores = new RS[m];

    // 輸入第二行
    char *line2 = new char[MAX_LEN];
    char *line2_digit = new char[MAX_LEN];
    cin.getline(line2, MAX_LEN);
    clearAphla(line2, line2_digit);
    delete[] line2;

    digit = strtok(line2_digit, ",");
    count = 0;
    int temp_x, temp_y;
    while (digit != NULL)
    {
        if (count % 2 == 0)
            temp_x = atoi(digit);
        else
        {
            temp_y = atoi(digit);
            int idx = count / 2;
            centers[idx].x = temp_x;
            centers[idx].y = temp_y;
        }
        digit = strtok(NULL, ",");
        count++;
    }

    // 輸入第三行
    char *line3 = new char[MAX_LEN];
    char *line3_digit = new char[MAX_LEN];
    cin.getline(line3, MAX_LEN);
    clearAphla(line3, line3_digit);
    delete[] line3;

    digit = strtok(line3_digit, ",");
    count = 0;
    while (digit != NULL)
    {
        if (count % 2 == 0)
            temp_x = atoi(digit);
        else
        {
            temp_y = atoi(digit);
            int idx = count / 2;
            stores[idx].x = temp_x;
            stores[idx].y = temp_y;
        }
        digit = strtok(NULL, ",");
        count++;
    }

    // 輸入第四行
    char *line4 = new char[MAX_LEN];
    char *line4_digit = new char[MAX_LEN];
    cin.getline(line4, MAX_LEN);
    clearAphla(line4, line4_digit);
    delete[] line4;

    digit = strtok(line4_digit, ",");
    count = 0;
    while (digit != NULL)
    {
        stores[count].demand = atoi(digit);
        digit = strtok(NULL, ",");
        count++;
    }

    // 1. 找出最近的物流中心
    for (int i = 0; i < m; i++)
    {
        int distance = findShortestDist(centers, stores[i], n);
        // 2. 檢查售價是否超過成本
        if (p - c * distance < 0)
            stores[i].replenishment = 0;
        cout << (i == 0 ? "" : ",") << stores[i].replenishment;
    }

    // 檢查輸入
    // cout << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     cout << stores[i].x << "," <<stores[i].y << " ";
    // }

    // cout << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     cout << stores[i].demand << " ";
    // }
}