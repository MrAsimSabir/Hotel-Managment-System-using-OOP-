#include "RoomManagment.h"
#include"Room.h"
#include<Windows.h>
#include"FILE_MANAGER.h"
void RoomManagment::ChangeRoomAvailability(string Roomno,string avail)
{
	FILE_MANAGER* filemanager = new FILE_MANAGER;
	Room listOfRooms[10];
	bool roomfound = false;
	short count = filemanager->ReadRoomsFromFIle(listOfRooms);
	for (int i = 0; i < count; i++)
	{
		if (Roomno == listOfRooms[i].getroomno()) roomfound = true;
	}
	if (roomfound == false)
	{
		cout << "-----Room Not Found-----" << endl;
		Sleep(1500);
		return;
	}
	for (int index = 0; index < count; index++)
	{
		if (Roomno == listOfRooms[index].getroomno())
		{
			listOfRooms[index].setroomavail(avail);
		}
	}
	filemanager->WriteRoomsToFile(listOfRooms, count);
	delete filemanager;
	filemanager = nullptr;
}
void RoomManagment::ChangeRoomCharges()
{
	cin.ignore();
	system("cls");
	cout << "\t\t\t\t\t======CHANGE ROOM CHARGES======" << endl;
	cout << endl;
	FILE_MANAGER* filemanager = new FILE_MANAGER;
	Room listOfRooms[10];
	string inputRoomNumber;
	float inputRoomCharges = 0;
	bool RoomFound = false;
	cout << "Enter Room Number: ";
	getline(cin, inputRoomNumber);
	short count = filemanager->ReadRoomsFromFIle(listOfRooms);
	for (int i = 0; i < count; i++)
	{
		if (inputRoomNumber == listOfRooms[i].getroomno())RoomFound = true;
	}
	if (RoomFound == false)
	{
		cout << "-----Room Not Found-----" << endl;
		Sleep(1500);
		return;
	}
	for (int index = 0; index < count; index++)
	{
		if (inputRoomNumber == listOfRooms[index].getroomno())
		{
			if (listOfRooms[index].getroomavail() == "Booked")
			{
				cout << "You can't Change Room Charges Because Room Is Booked:";
				Sleep(1000);
				return;
			}
			cout << "Enter New Charges : ";
			cin >> inputRoomCharges;
			listOfRooms[index].setroomcharges(inputRoomCharges);
		}
	}
	filemanager->WriteRoomsToFile(listOfRooms, count);
	delete filemanager;
	filemanager = nullptr;
}
void RoomManagment::ViewAvailableRooms()
{
	system("cls");
	cout << "\t\t\t\t\t======AVAILABLE ROOMS LIST======" << endl;
	cout << endl;
	FILE_MANAGER* filemanager=new FILE_MANAGER;
	Room RoomslistFromfile[10];
	short count = filemanager->ReadRoomsFromFIle(RoomslistFromfile);
	for (int index = 0; index < count; index++)
	{
		if (RoomslistFromfile[index].getroomavail() == "Booked"|| RoomslistFromfile[index].getroomavail() == "Not Available")continue;
		cout << RoomslistFromfile[index];
		//cout << RoomslistFromfile[index].getroomno() << "," << RoomslistFromfile[index].getroomcharges() <<","<< RoomslistFromfile[index].getroomavail() << endl;
	}
	cout << "Available" << endl;
	cout << "PRESS ENTER TO CONTINUE";
	_getch();
	delete filemanager;
	filemanager = nullptr;
}
void RoomManagment::ViewAllRooms()
{
	system("cls");
	cout << "\t\t\t\t\t======ALL ROOMS LIST======" << endl;
	cout << endl;
	FILE_MANAGER* filemanager = new FILE_MANAGER;
	Room RoomslistFromfile[10];
	short count = filemanager->ReadRoomsFromFIle(RoomslistFromfile);
	for (int index = 0; index < count; index++)
	{
		cout << RoomslistFromfile[index];
		//cout << RoomslistFromfile[index].getroomno() << "," << RoomslistFromfile[index].getroomcharges() << "," << RoomslistFromfile[index].getroomavail() << endl;
	}
	cout << "PRESS ENTER TO CONTINUE";
	_getch();
	delete filemanager;
	filemanager = nullptr;
}
