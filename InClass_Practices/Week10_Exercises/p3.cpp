#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
    static bool twelveHour;

public:
    Time(int h, int m, int s);
    bool isEarlierThan(Time t);
    void print();
    void printNicely();
    void printTwoDigits(int n);
    static void setTwelveHour(bool twelve);
};

int main()
{
    // 動態object陣列
    Time *t[3];
    int twelve;
    for (int i = 0; i < 3; i++)
    {
        int h, m, s;
        cin >> h >> m >> s;
        t[i] = new Time(h, m, s);
    }
    cin >> twelve;
    if (twelve == 12)
        Time::setTwelveHour(true);


    int latestIdx = 0;
    for (int i = 1; i < 3; i++)
    {
        if (t[latestIdx]->isEarlierThan(*t[i]))
            latestIdx = i;
    }

    t[latestIdx]->printNicely();
}

bool Time::twelveHour = false;
void Time::setTwelveHour(bool twelve)
{
    twelveHour = twelve;
}

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

bool Time::isEarlierThan(Time t)
{
    int mySec = hour * 3600 + minute * 60 + second;
    int itsSec = t.hour * 3600 + t.minute * 60 + t.second;
    if (mySec < itsSec)
        return true;
    else
        return false;
}

void Time::print()
{
    cout << hour << ":"
         << minute << ":" << second;
}
void Time::printNicely()
{
    printTwoDigits(hour);
    cout << ":";
    printTwoDigits(minute);
    cout << ":";
    printTwoDigits(second);
    if (twelveHour)
    {
        if (hour >= 12)
            cout << " PM";
        else
            cout << " AM";
    }
}
void Time::printTwoDigits(int n)
{
    if (twelveHour)
    {
        if (n >= 12)
            n %= 12;
    }

    cout << (n < 10 ? "0" : "") << n;
}