#ifndef Time_H
#define Time_H
#include <iostream>
using namespace std;

class Time
{
public:
      void Set(int hours, int minutes, int seconds);
      void Increment();
      void Write() const;
      Time(int initHrs, int initMins, int initSecs); // constructor
      Time();                                        //  default constructor

private:
      int hrs;
      int mins;
      int secs;
};

Time::Time(int initHrs, int initMins, int initSecs)
{
    hrs = initHrs;
    mins = initMins;
    secs = initSecs;
}

Time::Time()
{
    hrs = 0;
    mins = 0;
    secs = 0;
}

void Time::Set(int hours, int minutes, int seconds)
{
    hrs = hours;
    mins = minutes;
    secs = seconds;
}

void Time::Increment()
{
    if(secs != 59)
        secs++;
    else if(secs == 59)
    {
        secs = 0;
        if(mins != 59)
            mins ++;
        else if(mins == 59)
        {
            mins = 0;
            if(hrs != 23)
                hrs++;
            else if(hrs == 23)
                hrs = 0;
        }
    }
}

void Time::Write() const
{
    if(hrs >= 0 && hrs <= 9)
        cout << "0" << hrs << ":";
    else 
        cout << hrs << ":";

    if(mins >= 0 && mins <= 9)
        cout << "0" << mins << ":";
    else 
        cout << mins << ":";

    if(secs >= 0 && secs <= 9)
        cout << "0" << secs;
    else 
        cout << secs;
}



#endif
