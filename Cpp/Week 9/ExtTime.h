#ifndef ExtTime_H
#define ExtTime_H
#include "Time.h"
enum  ZoneType {EST, CST, MST, PST, EDT, CDT, MDT, PDT };

class ExtTime: public Time	// Time is the base class
{
    public:
        ExtTime (int initHrs, int initMins, int initSecs, ZoneType initZone);      // constructor
        ExtTime (); 			             // default constructor
        void Set (int hours, int minutes, int seconds, ZoneType timeZone);	
        void Write() const;
        
    private:				
	    ZoneType zone; 	//  added data member
};

ExtTime::ExtTime(): Time()
{
    zone = EST;
}

ExtTime::ExtTime(int initHrs, int initMins, int initSecs, ZoneType initZone): Time(initHrs, initMins, initSecs)
{
    zone = initZone;
}

void ExtTime::Set(int hours, int minutes, int seconds, ZoneType timeZone)
{
    Time::Set(hours, minutes, seconds);
    zone = timeZone;
}

void ExtTime::Write() const
{
    Time::Write();
    switch(zone)
    {
        case 0: cout << " EST"; break;
        case 1: cout << " CST"; break;
        case 2: cout << " MST"; break;
        case 3: cout << " PST"; break;
        case 4: cout << " EDT"; break;
        case 5: cout << " CDT"; break;
        case 6: cout << " MDT"; break;
        case 7: cout << " PDT"; break;
    }
}


#endif
