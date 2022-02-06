#include <iostream>
using namespace std;

const int NODE_CNT_MAX = 100;
int inputGraphInfo(int *neighbors[], int degrees[]);
void printGraph(int *neighbors[], const int degrees[], int nodeCnt);
void releaseMemory(int *neighbors[], int nodeCnt);
int main()
{
    int *neighbors[NODE_CNT_MAX] = {0};
    int degrees[NODE_CNT_MAX] = {0};
    int nodeCnt = inputGraphInfo(neighbors, degrees);
    printGraph(neighbors, degrees, nodeCnt);
    releaseMemory(neighbors, nodeCnt);
    return 0;
}

int inputGraphInfo(int *neighbors[], int degrees[])
{
    int nodeCnt = 0;
    cin >> nodeCnt;
    for (int i = 0; i < nodeCnt; i++)
    {
        //cout<<"Node"<<i
        // << "\'s degree is: ";
        cin >> degrees[i];
        neighbors[i] = new int[degrees[i]]; //cout<<"Node"<<i
        // << "\'s neighbors: ";
        for (int j = 0; j < degrees[i]; j++)
            cin >> neighbors[i][j];
    }
    return nodeCnt;
}

void printGraph(int *neighbors[], const int degrees[],
                int nodeCnt)
{
    int **outGraph = new int *[nodeCnt]; //動態2d array
    for (int i = 0; i < nodeCnt; i++)
    {
        outGraph[i] = new int[nodeCnt];

        for (int j = 0; j < degrees[i]; j++)
        {
            int neighborsIdx = neighbors[i][j];
            outGraph[i][neighborsIdx] = 1;
        }
        for (int j = 0; j < nodeCnt; j++)
        {
            if (outGraph[i][j] != 1)
                outGraph[i][j] = 0;
            cout << outGraph[i][j] << ((j == nodeCnt - 1) ? "" : " ");
        }
        cout << "\n";
    }
}

void releaseMemory(int *neighbors[],
                   int nodeCnt)
{
    for (int i = 0; i < nodeCnt; i++)
        delete[] neighbors[i];
}