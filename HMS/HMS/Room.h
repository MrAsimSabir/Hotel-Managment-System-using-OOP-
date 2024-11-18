#pragma once
#include<iostream>
using namespace std;
class Room
{
protected:
	string RoomNo;
	string RoomAvail;
	float RoomCharges;

public:
	Room() = default;
	Room(const string& RoomNo, const string& RoomAvail, const float& RoomCharges)
		: RoomNo(RoomNo), RoomAvail(RoomAvail), RoomCharges(RoomCharges)
	{
	}
	~Room(){}
	void setroomNo(const string& roomno) ;
	void setroomavail(const string& avail) ;
	void setroomcharges(const float& charges) ;

	const string& getroomno()const ;
	const string& getroomavail()const ;
	const float& getroomcharges()const;

	friend ostream& operator<<(ostream& stream, const Room& other);
};

