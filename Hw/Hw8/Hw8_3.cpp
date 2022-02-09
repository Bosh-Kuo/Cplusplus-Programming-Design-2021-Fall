#include <iostream>
#include <cmath>
using namespace std;

// 定義 struct
typedef struct DistributionCenter
{
    int x;
    int y;
    int limit;
} DC;

typedef struct RetailStore
{
    int x;
    int y;
    int demand;
    bool satisfied;
    int nearestDC; // 最近的物流中心編號
    int nearestDistance;
} RS;

// false代表已滿足或是沒有物流中心能帶來正毛利
void findNearestDC(RS &store, DC *centers, int n, int c, int p)
{
    int distance = 400, maxVol = 0;
    if (!store.satisfied)
    {
        // 找出n家物流中距離最短的
        for (int i = 0; i < n; i++)
        {
            // 只找還有庫存的
            if (centers[i].limit > 0)
            {
                // 比距離
                if (abs(store.x - centers[i].x) + abs(store.y - centers[i].y) < distance)
                {
                    distance = abs(store.x - centers[i].x) + abs(store.y - centers[i].y);
                    store.nearestDC = i + 1;
                    store.nearestDistance = distance;
                    maxVol = centers[i].limit;
                }
                else if (abs(store.x - centers[i].x) + abs(store.y - centers[i].y) == distance)
                {
                    // 比容量
                    if (centers[i].limit > maxVol)
                    {
                        distance = abs(store.x - centers[i].x) + abs(store.y - centers[i].y);
                        store.nearestDC = i + 1;
                        store.nearestDistance = distance;
                        maxVol = centers[i].limit;
                    }
                }
            }
        }

        // 若毛利 < 0
        if (p - c * store.nearestDistance <= 0)
        {
            store.satisfied = true;
            store.nearestDC = 0;
            store.nearestDistance = 400;
        }
    }
}

int main()
{
    int n, m, p, c; // 物流中心數,零售店數,售價,單位補貨成本
    int profit = 0, need = 0;
    cin >> n >> m >> p >> c;
    DC *centers = new DC[n];
    RS *stores = new RS[m];

    // 輸入
    for (int i = 0; i < n; i++)
    {
        cin >> centers[i].x >> centers[i].y;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> stores[i].x >> stores[i].y;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> stores[i].demand;
        stores[i].satisfied = false;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> centers[i].limit;
    }

    // 當全滿足或物流總剩餘容量為0：演算法結束
    // 1. 找出每間零售店自己最近的物流以及最短距離，若不存在物流編號為0,距離為400，不用找已滿足的零售店
    while (true)
    {
        // check 物流中心還有貨
        int remain = 0;
        for (int i = 0; i < n; i++)
        {
            remain += centers[i].limit;
        }
        if (remain == 0)
            break;

        // check 是否還有未滿足的零售店
        int satisfied = 0;
        for (int i = 0; i < m; i++)
        {
            if (stores[i].satisfied)
                satisfied++;
        }
        if (satisfied == m)
            break;

        // 找出未滿足的零售店中距離他的物流中心最小的那間
        int storeIdx = 0, minDistance = 400, maxDemand = 0;
        for (int i = 0; i < m; i++)
        {
            // 只計算不滿足的零售店
            if (!stores[i].satisfied)
            {
                findNearestDC(stores[i], centers, n, c, p);
                if (stores[i].nearestDistance < minDistance)
                {
                    minDistance = stores[i].nearestDistance;
                    storeIdx = i;
                    maxDemand = stores[i].demand;
                }
                else if (stores[i].nearestDistance == minDistance && stores[i].demand > maxDemand)
                {
                    minDistance = stores[i].nearestDistance;
                    storeIdx = i;
                    maxDemand = stores[i].demand;
                }
            }
        }

        // 該物流中心對該零售店補貨
        if (!stores[storeIdx].satisfied)
        {
            int replenishment = (stores[storeIdx].demand <= centers[stores[storeIdx].nearestDC - 1].limit ? stores[storeIdx].demand : centers[stores[storeIdx].nearestDC - 1].limit);
            profit += (p - c * stores[storeIdx].nearestDistance) * replenishment;
            centers[stores[storeIdx].nearestDC - 1].limit -= replenishment;
            stores[storeIdx].demand -= replenishment;

            // 檢查該零售店補完貨是否滿足
            if (stores[storeIdx].demand == 0)
                stores[storeIdx].satisfied = true;

            // cout << "物流: " << stores[storeIdx].nearestDC << endl;
            // cout << "零售店: " << storeIdx + 1 << endl;
            // cout << "補貨: " << replenishment << endl;
            // cout << endl;
        }
    }

    // 計算未滿足量
    for (int i = 0; i < m; i++)
    {
        need += stores[i].demand;
    }

    cout << profit << "," << need;
    return 0;
}