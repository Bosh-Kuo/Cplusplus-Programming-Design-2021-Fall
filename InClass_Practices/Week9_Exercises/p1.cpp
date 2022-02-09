#include <iostream>
using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
    void setTime(int h, int m, int s);
    void print();
    bool isEarlierThan(Time t);
};

int main()
{
    Time t1, t2, t3;
    int h1, m1, s1, h2, m2, s2, h3, m3, s3;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2 >> h3 >> m3 >> s3;
    t1.setTime(h1,m1,s1);
    t2.setTime(h2,m2,s2);
    t3.setTime(h3,m3,s3);

    if (!t1.isEarlierThan(t2) && !t1.isEarlierThan(t3))
        cout << "1";
    else if (!t2.isEarlierThan(t1) && !t2.isEarlierThan(t3))
        cout << "2";
    else if (!t3.isEarlierThan(t1) && !t3.isEarlierThan(t2))
        cout << "3";
    return 0;
}

void Time::setTime(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}
void Time::print()
{
    cout << hour << ":" << minute << ":"
         << second;
}

bool Time::isEarlierThan(Time t)
{
    if (hour < t.hour)
        return true;
    else if (hour > t.hour)
        return false;
    else
    {
        if (minute < t.minute)
            return true;
        else if (minute > t.minute)
            return false;
        else
        {
            if (second < t.second)
                return true;
            else
                return false;
        }
    }
}