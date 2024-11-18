#pragma once
#include<iostream>
using namespace std;
class RoomManagment
{
public:
	void ChangeRoomAvailability(string,string);
	void ChangeRoomCharges();
	void ViewAvailableRooms();
	void ViewAllRooms();
	~RoomManagment(){}
	RoomManagment() = default;
};

