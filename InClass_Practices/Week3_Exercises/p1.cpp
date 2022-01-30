#include <iostream>
using namespace std;

int main()
{
    int h, m, s, x;
    int hh, mm, ss;
    int out_h, out_m, out_s;
    cin >> h >> m >> s >> x;

    hh = x / 3600;
    mm = (x % 3600) / 60;
    ss = x % 60;

    if (s + ss >= 60)
    {
        mm += 1;
        out_s = (s + ss) % 60;
    }
    else
    {
        out_s = s + ss;
    }

    if (m + mm >= 60)
    {
        hh += 1;
        out_m = (m + mm) % 60;
    }
    else
    {
        out_m = m + mm;
    }

    out_h = h + hh;

    cout << out_h << ":" << out_m << ":" << out_s;
}