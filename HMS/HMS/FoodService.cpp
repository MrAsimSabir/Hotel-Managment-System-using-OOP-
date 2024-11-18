#include "FoodService.h"
#include"Food_Item.h"
#include<Windows.h>
#include"FILE_MANAGER.h"
void FoodService::ViewFoodMenu()
{
	system("cls");
	cout << "\t\t\t\t\t=====FOOD MENU=====" << endl;
	cout << endl;
	Food_Items foodlist[10];
	FILE_MANAGER* filemanager = new FILE_MANAGER;
	filemanager->ReadFoodMenuFromFile(foodlist);
	for (short i = 0; i < 10; i++)
	{
		cout << foodlist[i];
		//cout << foodlist[i].getfood() << "," << foodlist[i].getprice() << endl;
	}
	cout << "PRESS ENTER TO CONTINUE";
	_getch();
	delete filemanager;
	filemanager = nullptr;
}

void FoodService::PlaceOrder()
{
	cin.ignore();
	system("cls");
	cout << "\t\t\t\t\t=====ORDER FOOD=====" << endl;
	string inputRID, inputFoodName;
	cout << "Enter Reservation ID: ";
	getline(cin, inputRID);
	cout << "Enter Food Name: ";
	getline(cin, inputFoodName);
	Reservation listofresrvations[10]{};
	Food_Items listoffoods[10]{};
	FILE_MANAGER* filemanager = new FILE_MANAGER;
	short count = filemanager->ReadReservationsFromfile(listofresrvations);
	filemanager->ReadFoodMenuFromFile(listoffoods);
	for (int i = 0; i < count; i++)
	{
		if (inputRID == listofresrvations[i].getReserId())
		{
			for (int j = 0; j < 10; j++)
			{
				if (inputFoodName == listoffoods[j].getfood())
				{
					int totalprice = stoi(listoffoods[j].getprice()) + stoi(listofresrvations[i].getRoomcharges());
					//totalprice += stoi(listofresrvations[i].getRoomcharges());
					listofresrvations[i].setRoomcharges(to_string(totalprice));
					cout << "YOUR Total Bill is = " << totalprice << endl;
					cout << "=====Enjoy Your Meal=====" << endl;
					Sleep(2000);
				}
			}
		}
	}
	filemanager->WriteReservationsToFile(listofresrvations,count);
	delete filemanager;
	filemanager = nullptr;
}
