#pragma once
#include<iostream>
using namespace std;
class Date
{
protected:
	short Day;
    short Month;
    short Year;
public:
    const short& getDay() const{return Day;}
    const short& getMonth() const{ return Month;}
    const short& getYear() const{ return Year;}

    void setDay(const short& day) { Day = day; }
    void setMonth(const short& month) { Month = month; }
    void setYear(const short& year){ Year = year;}

    Date() = default;
    Date(const short& Day, const short& Month, const short& Year)
        : Day(Day), Month(Month), Year(Year)
    {
    }
};

