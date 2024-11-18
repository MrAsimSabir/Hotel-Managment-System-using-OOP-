#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<conio.h>
#include"Employee.h"
#include"RESERVATION_MANAGEMENT.h"
#include"Room.h"
#include"Reservation.h"
#include"Food_Item.h"
using namespace std;

class FILE_MANAGER
{
protected:
	string EmployeeFilePath = "employee.txt";
	string RoomsFIlepath = "rooms.txt";
	string ReservationFilePath = "reservations.txt";
	string FoodMenuFilePath = "foodmenu.txt";
public:

	FILE_MANAGER() = default;
	~FILE_MANAGER(){}
	short ReadEmployeeFromFIle(Employee EmployeesListFromFile[]);
	void WriteEmployeesToFile(Employee EmployeesListToWrite[], short loopcount);
	short ReadRoomsFromFIle(Room roomslist[]);
	void WriteRoomsToFile(Room roomslist[], short loopcount);
	short ReadReservationsFromfile(Reservation GuestList[]);
	void WriteReservationsToFile(Reservation GuestListTowrite[], short loopcount);
	void ReadFoodMenuFromFile(Food_Items fooditemList[]);
};

