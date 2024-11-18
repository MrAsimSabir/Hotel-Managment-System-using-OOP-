#include <iostream>
#include<Windows.h>
#include"Person.h"
#include"FoodService.h"
#include"FILE_MANAGER.h"
#include"Login_Verification.h"
#include"RoomManagment.h"
#include"EMPLOYEE_MANAGEMENT.h"
using namespace std;
enum UserEnum
{
	ADMIN=1,
	EMPLOYEE,
	GUEST,
	BACK
};
void UserMenu()
{
	cout << "1: Admin" << endl
		<< "2: Employee" << endl
		<< "3: Guest" << endl
		<< "4: Exit" << endl
		<< "Enter Your Choice: ";
}
void Admin_Menu()
{
	cout << "1:Create Employee " << endl
		<< "2:Delete  Employee " << endl
		<< "3:View Employees " << endl
		<< "4: Back " << endl
		<< "Enter Your Choice: ";
}
void ManagerMenu()
{
	cout << "1:View All Rooms " << endl
		<< "2:View Available Rooms" << endl
		<< "3:Change Room Charges" << endl
		<< "4:Change Room Availabilty" << endl
		<< "5:Reserve Room" << endl
		<< "6:Cancel Reservaion" << endl
		<< "7:View All Reservations" << endl
		<< "8:Reset Password" << endl
		<< "9:Back" << endl
		<< "Enter Your Choice: ";
}
void ReceptionistMenu()
{
	cout << "1:View All Rooms " << endl
		<< "2:View Available Rooms" << endl
		<< "3:Reserve Room" << endl
		<< "4:Cancel Reservaion" << endl
		<< "5:View All Reservations" << endl
		<< "6:Reset Password" << endl
		<< "7:Check IN" << endl
		<< "8:Check OUT" << endl
		<< "9:Back" << endl
		<< "Enter Your Choice: ";
}
void CustomerMenu()
{
	cout << "1:View Food Menu" << endl
		<< "2:Order Food" << endl
		<< "3:Back" << endl
		<< "Enter Your Choice: " << endl;
}
void loadingScreen()
{
	int loop = 1;
	for (int i = 10; i <= 100; i += 10)
	{
		std::cout << "\033[" << 10 << ";" << 50 << "H";
		cout << "Loading..." << "   ";
		cout << i << "%[";
		for (int j = 0; j < loop; j++)
		{
			cout << "*";
		}
		cout << "]";
		loop++;
		Sleep(500);
		system("cls");

	}
	cout << "\033[" << 10 << ";" << 40 << "H"
		<< "===========LOADING COMPLETE===========";
	Sleep(1000);
	system("cls");
	cout << "\033[" << 10 << ";" << 35 << "H"
		<< "===========Welcome to Burj Hotel===========" << endl
		<< "\033[" << 11 << ";" << 45 << "H"
		<< "Press enter to continue";
	char* result = new char;
	*result = _getch();;
	delete result;
}

int main()
{
	//loadingScreen();
	short choice = 0;
	while (true) 
	{
		system("cls");
		cout << "\t\t\t\t\t======USER======" << endl;
		UserMenu();
		cin >> choice;
		while (cin.fail())
		{

			cout << "-----Numbers Only-----";
			cin.clear();
			cin.ignore(100, '\n');
			Sleep(1000);
			system("cls");
			cout << "\t\t\t\t\t======USER======" << endl;
			UserMenu();
			cin >> choice;
		}
		if (choice == ADMIN)
		{
			Login_Management* adminlogin = new Login_Management;
			string result= adminlogin->Check_Login("admin");
			if (result == "success,admin")
			{
				while (true)
				{
					system("cls");
					cout << "\t\t\t\t\t======ADMIN======" << endl;
					Admin_Menu();
					cin >> choice;
					while (cin.fail())
					{

						cout << "-----Numbers Only-----";
						cin.clear();
						cin.ignore(100, '\n');
						Sleep(1000);
						system("cls");
						cout << "\t\t\t\t\t======ADMIN======" << endl;
						Admin_Menu();
						cin >> choice;
					}
					if (choice == 1)
					{
						EMPLOYEE_MANAGEMENT* create_employee = new EMPLOYEE_MANAGEMENT;
						create_employee->Create_Employee();
						delete create_employee;
						create_employee = nullptr;
					}
					else if (choice == 2)
					{
						EMPLOYEE_MANAGEMENT* delete_employee = new EMPLOYEE_MANAGEMENT;
						delete_employee->Delete_Employee();
						delete delete_employee;
						delete_employee = nullptr;
					}
					else if (choice == 3)
					{
						EMPLOYEE_MANAGEMENT* View_employees = new EMPLOYEE_MANAGEMENT;
						View_employees->View_Employee();
						delete View_employees;
						View_employees = nullptr;
					}
					else if (choice == 4)
					{
						delete adminlogin;
						adminlogin = nullptr;
						break;
					}
					else
					{
						cout << "-----Invalid input-----" << endl;
						Sleep(1000);
					}
				}
			}
			else 
			{
				delete adminlogin;
				cout << "-----------------------" << endl;
				cout << "-----LOGIN FAILED!-----" << endl;
				cout << "-----------------------" << endl;
				Sleep(1000);
			}
		}
		else if (choice == EMPLOYEE)
		{
			Login_Management* employeelogin = new Login_Management;
			string usertype = employeelogin->Check_Login("employee");
			if ( usertype == "success,Manager")
			{
				while (true)
				{
					system("cls");
					cout << "\t\t\t\t\t======MANAGER======" << endl;
					ManagerMenu();
					cin >> choice;
					while (cin.fail())
					{

						cout << "-----Numbers Only-----";
						cin.clear();
						cin.ignore(100, '\n');
						Sleep(1000);
						system("cls");
						cout << "\t\t\t\t\t======MANAGER======" << endl;
						ManagerMenu();
						cin >> choice;
					}
					if (choice == 1)
					{
						RoomManagment* viewAllRoom = new RoomManagment;
						viewAllRoom->ViewAllRooms();
						delete viewAllRoom;
						viewAllRoom = nullptr;
					}
					else if (choice == 2)
					{
						RoomManagment* viewAvailableRoom = new RoomManagment;
						viewAvailableRoom->ViewAvailableRooms();
						delete viewAvailableRoom;
						viewAvailableRoom = nullptr;
					}
					else if (choice == 3)
					{
						RoomManagment* changeRoomCharges = new RoomManagment;
						changeRoomCharges->ChangeRoomCharges();
						delete changeRoomCharges;
						changeRoomCharges = nullptr;
					}
					else if (choice == 4)
					{
						cin.ignore();
						system("cls");
						cout << "\t\t\t\t\t======CHANGE ROOM AVAILABLILITY======" << endl;
						cout << endl;
						string inputRoomAvail;
						string inputRoomNumber;
						cout << "Enter Room Number: ";;
						getline(cin, inputRoomNumber);
						cout << "Enter Availability(Available/Booked/Not Available) : ";
						getline(cin, inputRoomAvail);
						if (inputRoomAvail == "Booked" || inputRoomAvail == "Available"||inputRoomAvail=="Not Available")
						{
							RoomManagment* changeRoomAvailabilty = new RoomManagment;
							changeRoomAvailabilty->ChangeRoomAvailability(inputRoomNumber,inputRoomAvail);
							delete changeRoomAvailabilty;
							changeRoomAvailabilty = nullptr;
						}
						else
						{
							cout << "Please Type Available OR Booked OR Not Available" << endl;
							Sleep(2000);
						}
					}
					else if (choice == 5)
					{
						RESERVATION_MANAGEMENT* ReserveRoom = new RESERVATION_MANAGEMENT;
						ReserveRoom->Reserve_Room();
						delete ReserveRoom;
						ReserveRoom = nullptr;
					}
					else if (choice == 6)
					{
						RESERVATION_MANAGEMENT* CancelReservation = new RESERVATION_MANAGEMENT;
						CancelReservation->Cancel_reservation();
						delete CancelReservation;
						CancelReservation = nullptr;
					}
					else if (choice == 7)
					{
						RESERVATION_MANAGEMENT* viewReservations = new RESERVATION_MANAGEMENT;
						viewReservations->View_Reservations();
						delete viewReservations;
						viewReservations = nullptr;
					}
					else if (choice == 8)
					{
						cin.ignore();
						system("cls");
						cout << "\t\t\t\t\t======PASSWORD RESET======" << endl;
						cout << endl;
						string inputid, inputnewpassword,inputoldpassword;
						cout << "Enter Your Id: ";
						getline(cin, inputid);
						cout << "Enter Old Password: ";
						getline(cin, inputoldpassword);
						cout << "Enter New Password: ";
						getline(cin, inputnewpassword);
						EMPLOYEE_MANAGEMENT* resetpassword = new EMPLOYEE_MANAGEMENT;
						resetpassword->ResetPassword(inputid, inputnewpassword,inputoldpassword);
						delete resetpassword;
						resetpassword = nullptr;
					}
					else if (choice == 9)
					{
						delete employeelogin;
						employeelogin = nullptr;
						break;
					}
					else
					{

						cout << "-----Invalid input-----" << endl;
						Sleep(1000);
					}
				}
			}
			else if (usertype == "success,Receptionist")
			{
				while (true)
				{
					system("cls");
					cout << "\t\t\t\t\t======RECEPTIONIST======" << endl;
					ReceptionistMenu();
					cin >> choice;
					while (cin.fail())
					{

						cout << "-----Numbers Only-----";
						cin.clear();
						cin.ignore(100, '\n');
						Sleep(1000);
						system("cls");
						cout << "\t\t\t\t\t======RECEPTIONIST======" << endl;
						ReceptionistMenu();
						cin >> choice;
					}
					if (choice == 1)
					{
						RoomManagment* ViewALLROOMS = new RoomManagment;
						ViewALLROOMS->ViewAllRooms();
						delete ViewALLROOMS;
						ViewALLROOMS = nullptr;
					}
					else if (choice == 2)
					{
						RoomManagment* ViewAvailableRooms = new RoomManagment;
						ViewAvailableRooms->ViewAvailableRooms();
						delete ViewAvailableRooms;
						ViewAvailableRooms = nullptr;
					}
					else if(choice==3)
					{

						RESERVATION_MANAGEMENT* ReserveRoom = new RESERVATION_MANAGEMENT;
						ReserveRoom->Reserve_Room();
						delete ReserveRoom;
						ReserveRoom = nullptr;
					}
					else if (choice == 4)
					{
						RESERVATION_MANAGEMENT* CancelReservation = new RESERVATION_MANAGEMENT;
						CancelReservation->Cancel_reservation();
						delete CancelReservation;
						CancelReservation = nullptr;
					}
					else if (choice == 5)
					{
						RESERVATION_MANAGEMENT* viewReservations = new RESERVATION_MANAGEMENT;
						viewReservations->View_Reservations();
						delete viewReservations;
						viewReservations = nullptr;
					}
					else if (choice == 6)
					{
						cin.ignore();
						system("cls");
						cout << "\t\t\t\t\t======PASSWORD RESET======" << endl;
						cout << endl;
						string inputid, inputnewpassword, inputoldpassword;
						cout << "Enter Your Id: ";
						getline(cin, inputid);
						cout << "Enter Old Password: ";
						getline(cin, inputoldpassword);
						cout << "Enter New Password: ";
						getline(cin, inputnewpassword);
						EMPLOYEE_MANAGEMENT* resetpassword = new EMPLOYEE_MANAGEMENT;
						resetpassword->ResetPassword(inputid, inputnewpassword, inputoldpassword);
						delete resetpassword;
						resetpassword = nullptr;
					}
					else if (choice == 7)
					{
						cin.ignore();
						system("cls");
						cout << "\t\t\t\t\t======CHECK IN DATE======" << endl;
						cout << endl;
						string checkindate,ReservationID;
						cout << "Enter Reservation ID: ";
						getline(cin, ReservationID);
						cout << "Enter Check In Date(DD/MM/YYYY): ";
						getline(cin, checkindate);
						RESERVATION_MANAGEMENT* Checkin = new RESERVATION_MANAGEMENT;
						Checkin->GuestCheckin(checkindate,ReservationID);
						delete Checkin;
						Checkin = nullptr;
					}
					else if (choice == 8)
					{
						cin.ignore();
						system("cls");
						cout << "\t\t\t\t\t======CHECK OUT DATE======" << endl;
						cout << endl;
						string checkoutdate, ReservationID;
						cout << "Enter Reservation ID: ";
						getline(cin, ReservationID);
						cout << "Enter Check Out Date(DD/MM/YYYY): ";
						getline(cin, checkoutdate);
						RESERVATION_MANAGEMENT* Checkout = new RESERVATION_MANAGEMENT;
						Checkout->GuestCheckout(checkoutdate, ReservationID);
						delete Checkout;
						Checkout = nullptr;
					}
					else if (choice == 9)
					{
						delete employeelogin;
						employeelogin = nullptr;
						break;
					}
					else
					{
						cout << "-----Invalid input-----" << endl;
						Sleep(1000);
					}
				}
			}
			else {
				delete employeelogin;
				cout << "-----------------------" << endl;
				cout << "-----LOGIN FAILED!-----" << endl;
				cout << "-----------------------" << endl;
				Sleep(1000);
			}
			
		}
		else if (choice == GUEST)
		{
			while (true)
			{
				system("cls");
				cout << "\t\t\t\t\t======CUSTOMER======" << endl;
				CustomerMenu();
				cin >> choice;
				while (cin.fail())
				{

					cout << "-----Numbers Only-----";
					cin.clear();
					cin.ignore(100, '\n');
					Sleep(1000);
					system("cls");
					cout << "\t\t\t\t\t======CUSTOMER======" << endl;
					CustomerMenu();
					cin >> choice;
				}
				if (choice == 1)
				{
					FoodService* ViewFoodMenu = new FoodService;
					ViewFoodMenu->ViewFoodMenu();
					delete ViewFoodMenu;
					ViewFoodMenu = nullptr;
				}
				else if (choice == 2)
				{
					FoodService* PlaceOrder = new FoodService;
					PlaceOrder->PlaceOrder();
					delete PlaceOrder;
					PlaceOrder = nullptr;
				}
				else if (choice == 3)
				{
					break;
				}
			}
		}
		else if (choice == BACK)
		{
			cout << "--------------------------" << endl;
			cout << "-----Exiting Program------" << endl;
			cout << "--------------------------" << endl;
			return 0;
		}	
		else
		{

			cout << "-----Invalid input-----" << endl;
			Sleep(1000);
		}
	}

}

