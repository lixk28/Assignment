#include <iostream>
using namespace std;

class Time{
    int Hour, Minute, Second;
    public:
        Time();
        Time(int totalSeconds);
        int getHour();
        int getMinute();
        int getSecond(); 
    };
Time::Time()
{
    Hour = 0;
    Minute = 0;
    Second = 0;
}

Time::Time(int totalSeconds)
{
    Hour = totalSeconds / 3600;
    Minute = (totalSeconds - Hour * 3600) / 60;
    Second = totalSeconds - Hour * 3600 - Minute * 60; 
}

int Time::getHour()
{
    return Hour;
}

int Time::getMinute()
{
    return Minute;
}

int Time::getSecond()
{
    return Second;
}

int main()
{


    return 0;
}