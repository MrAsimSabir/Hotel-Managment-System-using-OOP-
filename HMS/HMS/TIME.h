#pragma once
class TIME
{
protected:
	short Second;
	short Minute;
	short Hour;
public:

	TIME() = default;

	TIME(short Second, short Minute, short Hour)
		: Second(Second), Minute(Minute), Hour(Hour)
	{
	}
	const short& getSecond() { return Second; }
	const short& getMinute() { return Minute; }
	const short& getHour() { return Hour; }

	void setSecond(const short& second) { Second = second; }
	void getMinute(const short& minute) { Minute = minute; }
	void getYear(const short& hour) { Hour = hour; }

};

