#include <iostream>
using namespace std;

int main()
{
    int n, B;
    cin >> n >> B;
    int *w = new int[n];
    int *v = new int[n];
    int *x = new int[n];
    int weight = 0, value = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
        {
            weight += w[i];
            value += v[i];
        }
    }
    if (weight<=B)
    {
        cout << weight << " " << value;
    }
    else
    {
        cout << 0;
    }
}