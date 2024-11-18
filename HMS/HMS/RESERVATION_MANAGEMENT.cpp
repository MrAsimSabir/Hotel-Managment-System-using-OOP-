#define NOMINMAX
#include "RESERVATION_MANAGEMENT.h"
#include"FILE_MANAGER.h"
#include<Windows.h>
#include "RoomManagment.h"
void RESERVATION_MANAGEMENT::Reserve_Room()
{
	cin.ignore();
	system("cls");
	cout << "\t\t\t\t\t======MAKE RESERVATION======" << endl;
	cout << endl;
	string inputname, inputph, inputadd, inputroomno,charges, inputresS, inputresE;
	int Resid = 0;
	short age = 0;
	char genderr = '0';
	bool roomfound = false;
	bool roomavail = false;
	FILE_MANAGER *filemanager=new FILE_MANAGER;
	Reservation ListOfGuest[10]{};
	Room listofRooms[10]{};
	short roomscount = filemanager->ReadRoomsFromFIle(listofRooms);
	short count = filemanager->ReadReservationsFromfile(ListOfGuest);
	cout << "Enter Room Number: ";
	getline(cin, inputroomno);
	for (int i = 0; i < roomscount; i++)
	{
		if (inputroomno == listofRooms[i].getroomno())
		{
			roomfound = true;
			if (listofRooms[i].getroomavail() == "Available")
			{
				roomavail = true;
				stringstream stream(to_string(listofRooms[i].getroomcharges()));
				getline(stream, charges, '.');
				break;
			}
		}
	}
	if (roomfound == false)
	{
		cout << "-----Room Not Found-----" << endl;
		Sleep(1500);
		return;
	}
	if (roomavail == false)
	{
		cout << "-----Room Is Not Available-----" << endl;
		Sleep(1500);
		return;
	}
	cout << "Enter Guest Name: ";
	getline(cin, inputname);
	cout << "Enter Guest age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter Guest Gender: ";
	cin >> genderr;
	cin.ignore();
	cout << "Enter Guest Phone no: ";
	getline(cin, inputph);
	cout << "Enter Guest Address: ";
	getline(cin, inputadd);
	cout << "Enter Reservation Start Date(DD/MM/YYYY): ";
	getline(cin, inputresS);
	cout << "Enter Reservation End Date(DD/MM/YYYY): ";
	getline(cin, inputresE);
	srand(time(0));
	Resid = (rand() % numeric_limits<int>::max()) + 1;
	RoomManagment ChangeroomAvailabilty;
	ChangeroomAvailabilty.ChangeRoomAvailability(inputroomno,"Booked");
	ListOfGuest[count] = Reservation(to_string(Resid), inputname, inputph, inputadd, genderr, age, inputroomno,charges, inputresS, inputresE);
	//ListOfGuest[count].setname(inputname); ListOfGuest[count].setage(age); ListOfGuest[count].setgender(genderr);
	//ListOfGuest[count].setphone(inputph); ListOfGuest[count].setadd(inputadd); ListOfGuest[count].setReserId(to_string(Resid));
	//ListOfGuest[count].setroomNo(inputroomno); ListOfGuest[count].setresstart(inputresS);
	//ListOfGuest[count].setresend(inputresE); 

	filemanager->WriteReservationsToFile(ListOfGuest, count + 1);
	delete filemanager;
	filemanager = nullptr;
}

void RESERVATION_MANAGEMENT::Cancel_reservation()
{
	cin.ignore();
	system("cls");
	cout << "\t\t\t\t\t======CANCEL RESERVATION======" << endl;
	cout << endl;
	cout << "Enter Reservation Id Of Customer Your want To remove: ";
	string inputname, inputph, inputadd, inputroomno, inputresS, inputresE;
	int Resid = 0;
	cin >> Resid;
	short age = 0;
	bool reservationfound = false;
	char genderr = '0';
	FILE_MANAGER* filemanager = new FILE_MANAGER;
	Reservation ListOfGuest[10]{};
	Reservation UpdatedListOfGuest[10]{};
	short count = filemanager->ReadReservationsFromfile(ListOfGuest);
	for (int j = 0; j < count; j++)
	{
		if (to_string(Resid) == ListOfGuest[j].getReserId())reservationfound = true;
	}
	if (reservationfound == false)
	{
		cout << "-----Reservation ID Not Found-----" << endl;
		Sleep(1500);
		return;
	}
	int i = 0;
	for (int index = 0; index < count; index++)
	{
		if (to_string(Resid) == ListOfGuest[index].getReserId())
		{
			RoomManagment ChangeroomAvailabilty;
			ChangeroomAvailabilty.ChangeRoomAvailability(ListOfGuest[index].getroomno(), "Available");
			continue;
		}
		else {
			UpdatedListOfGuest[i].setname(ListOfGuest[index].getname()); UpdatedListOfGuest[i].setReserId(ListOfGuest[index].getReserId());
			UpdatedListOfGuest[i].setage(ListOfGuest[index].getage()); UpdatedListOfGuest[i].setgender(ListOfGuest[index].getgender());
			UpdatedListOfGuest[i].setphone(ListOfGuest[index].getphone()); UpdatedListOfGuest[i].setadd(ListOfGuest[index].getadd());
			UpdatedListOfGuest[i].setroomNo(ListOfGuest[index].getroomno()); UpdatedListOfGuest[i].setresstart(ListOfGuest[index].getresstart());
			UpdatedListOfGuest[i].setRoomcharges(ListOfGuest[index].getRoomcharges());
			UpdatedListOfGuest[i].setresend(ListOfGuest[index].getresend()); UpdatedListOfGuest[i].setcheckin(ListOfGuest[index].getcheckin());
			UpdatedListOfGuest[i].setcheckout(ListOfGuest[index].getcheckout());
			i++;
		}
	}
	filemanager->WriteReservationsToFile(UpdatedListOfGuest,count-1);
	delete filemanager;
	filemanager = nullptr;
}

void RESERVATION_MANAGEMENT::View_Reservations()
{
	cin.ignore();
	system("cls");
	cout << "\t\t\t\t\t======RESERVATION LIST======" << endl;
	cout << endl;
	FILE_MANAGER* filemanager = new FILE_MANAGER;
	Reservation ListOfGuestToShow[10]{};
	short count = filemanager->ReadReservationsFromfile(ListOfGuestToShow);
	for (int index = 0; index < count; index++)
	{
		cout << ListOfGuestToShow[index];
	}
	cout << "PRESS ENTER TO CONTINUE";
	_getch();
	filemanager->WriteReservationsToFile(ListOfGuestToShow, count);
	delete filemanager;
	filemanager = nullptr;
}

void RESERVATION_MANAGEMENT::GuestCheckin(string checkindate,string ReservationId)
{
	FILE_MANAGER* filemanager = new FILE_MANAGER;
	Reservation ListOfGuest[10];
	Reservation UpdatedListOfGuest[10];
	short count = filemanager->ReadReservationsFromfile(ListOfGuest);
	for (int i = 0; i < count; i++)
	{
		if (ReservationId == ListOfGuest[i].getReserId())
		{
			ListOfGuest[i].setcheckin(checkindate);
		}
		UpdatedListOfGuest[i].setname(ListOfGuest[i].getname()); UpdatedListOfGuest[i].setReserId(ListOfGuest[i].getReserId());
		UpdatedListOfGuest[i].setage(ListOfGuest[i].getage()); UpdatedListOfGuest[i].setgender(ListOfGuest[i].getgender());
		UpdatedListOfGuest[i].setphone(ListOfGuest[i].getphone()); UpdatedListOfGuest[i].setadd(ListOfGuest[i].getadd());
		UpdatedListOfGuest[i].setroomNo(ListOfGuest[i].getroomno()); UpdatedListOfGuest[i].setresstart(ListOfGuest[i].getresstart());
		UpdatedListOfGuest[i].setRoomcharges(ListOfGuest[i].getRoomcharges());
		UpdatedListOfGuest[i].setresend(ListOfGuest[i].getresend()); UpdatedListOfGuest[i].setcheckin(ListOfGuest[i].getcheckin());
		UpdatedListOfGuest[i].setcheckout(ListOfGuest[i].getcheckout());
	}
	filemanager->WriteReservationsToFile(UpdatedListOfGuest, count);
	delete filemanager;
	filemanager = nullptr;
}

void RESERVATION_MANAGEMENT::GuestCheckout(string checkoutdate, string ReservationId)
{
	FILE_MANAGER* filemanager = new FILE_MANAGER;
	Reservation ListOfGuest[10];
	Reservation UpdatedListOfGuest[10];
	short count = filemanager->ReadReservationsFromfile(ListOfGuest);
	for (int i = 0; i < count; i++)
	{
		if (ReservationId == ListOfGuest[i].getReserId())
		{
			ListOfGuest[i].setcheckout(checkoutdate);
		}
		UpdatedListOfGuest[i].setname(ListOfGuest[i].getname()); UpdatedListOfGuest[i].setReserId(ListOfGuest[i].getReserId());
		UpdatedListOfGuest[i].setage(ListOfGuest[i].getage()); UpdatedListOfGuest[i].setgender(ListOfGuest[i].getgender());
		UpdatedListOfGuest[i].setphone(ListOfGuest[i].getphone()); UpdatedListOfGuest[i].setadd(ListOfGuest[i].getadd());
		UpdatedListOfGuest[i].setroomNo(ListOfGuest[i].getroomno()); UpdatedListOfGuest[i].setresstart(ListOfGuest[i].getresstart());
		UpdatedListOfGuest[i].setRoomcharges(ListOfGuest[i].getRoomcharges());
		UpdatedListOfGuest[i].setresend(ListOfGuest[i].getresend()); UpdatedListOfGuest[i].setcheckin(ListOfGuest[i].getcheckin());
		UpdatedListOfGuest[i].setcheckout(ListOfGuest[i].getcheckout());
	}
	filemanager->WriteReservationsToFile(UpdatedListOfGuest, count);
	delete filemanager;
	filemanager = nullptr;
}
