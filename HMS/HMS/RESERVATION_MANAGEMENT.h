#pragma once
#include<iostream>
using namespace std;
class RESERVATION_MANAGEMENT
{
public:
	RESERVATION_MANAGEMENT() = default;
	~RESERVATION_MANAGEMENT(){}
	void Reserve_Room();
	void Cancel_reservation();
	void View_Reservations();
	void GuestCheckin(string,string);
	void GuestCheckout(string, string);
};

