#include "FILE_MANAGER.h"
short FILE_MANAGER::ReadEmployeeFromFIle(Employee EmployeesListFromFile[])
{
	short index = 0;
	ifstream file;
	file.open(EmployeeFilePath);
	if (file.is_open())
	{
		string EmployeeDataReadFromFIle, CurrentAttribute;
		while (getline(file, EmployeeDataReadFromFIle))
		{
			string n, id, add, ph, pass, user, type;
			char gender = '0';
			short age = 0;
			stringstream stream(EmployeeDataReadFromFIle);
			while (getline(stream, CurrentAttribute, ','))
			{
				if (n.empty()) {
					n = CurrentAttribute;
				}
				else if (type.empty())
				{
					type = CurrentAttribute;
				}
				else if (id.empty())
				{
					id = CurrentAttribute;
				}
				else if (age == 0) {
					age = stoi(CurrentAttribute);
				}
				else if (gender == '0') {

					gender = CurrentAttribute[0];
				}
				else if (ph.empty()) {
					ph = CurrentAttribute;
				}
				else if (add.empty()) {
					add = CurrentAttribute;
				}
				else if (user.empty()) {
					user = CurrentAttribute;
				}
				else if (pass.empty())
				{
					pass = CurrentAttribute;
				}
			}
			EmployeesListFromFile[index].setname(n); EmployeesListFromFile[index].setEmployeeId(id);
			EmployeesListFromFile[index].setage(age); EmployeesListFromFile[index].setgender(gender);
			EmployeesListFromFile[index].setphone(ph); EmployeesListFromFile[index].setadd(add);
			EmployeesListFromFile[index].setUsername(user); EmployeesListFromFile[index].setPassword(pass);
			EmployeesListFromFile[index].setEmployeeType(type);
			index++;
		}
		file.close();
	}
	//index -= 1;
	return index;
}

void FILE_MANAGER::WriteEmployeesToFile(Employee EmployeesListToWrite[], short loopcount)
{
	ofstream outfile;
	outfile.open(EmployeeFilePath);
	if (outfile.is_open())
	{
		for (short index = 0; index < loopcount; index++)
		{
			outfile << EmployeesListToWrite[index].getname() << "," << EmployeesListToWrite[index].getEmployeeType() << "," << EmployeesListToWrite[index].getEmployeeId() << "," << EmployeesListToWrite[index].getage() << ","
				<< EmployeesListToWrite[index].getgender() << "," << EmployeesListToWrite[index].getphone() << "," << EmployeesListToWrite[index].getadd() << ","
				<< EmployeesListToWrite[index].getUsername() << "," << EmployeesListToWrite[index].getPassword() << endl;
		}
		outfile.close();
	}
}

short FILE_MANAGER::ReadRoomsFromFIle(Room roomslist[])
{
	short index = 0;
	ifstream file;
	file.open(RoomsFIlepath);
	if (file.is_open())
	{
		string roomDataFromFIle, CurrentAttribute;
		while (getline(file, roomDataFromFIle))
		{
			stringstream stream(roomDataFromFIle);
			string savedRoomno, savedRoomAvail;
			float savedRoomCharges = 0;
			while (getline(stream, CurrentAttribute, ','))
			{
				if (savedRoomno.empty())
				{
					savedRoomno = CurrentAttribute;
				}
				else if (savedRoomCharges == 0)
				{
					savedRoomCharges = stoi(CurrentAttribute);
				}
				else if (savedRoomAvail.empty())
				{
					savedRoomAvail = CurrentAttribute;
				}
			}
			roomslist[index].setroomNo(savedRoomno);
			roomslist[index].setroomcharges(savedRoomCharges);
			roomslist[index].setroomavail(savedRoomAvail);
			index++;
		}
		file.close();
	}
	return index;
}

void FILE_MANAGER::WriteRoomsToFile(Room roomslist[], short loopcount)
{
	ofstream outfile;
	outfile.open(RoomsFIlepath);
	if (outfile.is_open())
	{
		for (short index = 0; index < loopcount; index++)
		{
			outfile << roomslist[index].getroomno() << "," << roomslist[index].getroomcharges() << "," << roomslist[index].getroomavail() << endl;
		}
	}
}

short FILE_MANAGER::ReadReservationsFromfile(Reservation GuestList[])
{
	short index = 0;
	ifstream file;
	file.open(ReservationFilePath);
	if (file.is_open())
	{
		string customerDataFromFile, CurrentAttribute;
		while (getline(file, customerDataFromFile))
		{
			stringstream stream(customerDataFromFile);
			string SavedName, savedRoomcharges, savedCusId, savedResId, savedph, savedAdd, resstartDate, resendDate, checkinDate, checkoutDate, savedRoomno;
			char savedgender = '0';
			short savedage = 0;
			while (getline(stream, CurrentAttribute, ','))
			{
				if (SavedName.empty())
				{
					SavedName = CurrentAttribute;
				}
				else if (savedResId.empty())
				{
					savedResId = CurrentAttribute;
				}
				else if (savedage == 0)
				{
					savedage = stoi(CurrentAttribute);
				}
				else if (savedgender == '0')
				{
					savedgender = CurrentAttribute[0];
				}
				else if (savedph.empty())
				{
					savedph = CurrentAttribute;
				}
				else if (savedAdd.empty())
				{
					savedAdd = CurrentAttribute;
				}
				else if (savedRoomno.empty())
				{
					savedRoomno = CurrentAttribute;
				}
				else if (savedRoomcharges.empty())
				{
					savedRoomcharges = CurrentAttribute;
				}
				else if (resstartDate.empty())
				{
					resstartDate = CurrentAttribute;
				}
				else if (resendDate.empty())
				{
					resendDate = CurrentAttribute;
				}
				else if (checkinDate.empty())
				{
					checkinDate = CurrentAttribute;
				}
				else if (checkoutDate.empty())
				{
					checkoutDate = CurrentAttribute;
				}
			}
			GuestList[index].setname(SavedName); GuestList[index].setage(savedage); GuestList[index].setgender(savedgender);
			GuestList[index].setphone(savedph); GuestList[index].setadd(savedAdd); GuestList[index].setReserId(savedResId);
			GuestList[index].setroomNo(savedRoomno); GuestList[index].setRoomcharges(savedRoomcharges); GuestList[index].setresstart(resstartDate);
			GuestList[index].setresend(resendDate); GuestList[index].setcheckin(checkinDate); GuestList[index].setcheckout(checkoutDate);
			index++;
		}
		file.close();
	}
	return index;
}

void FILE_MANAGER::WriteReservationsToFile(Reservation GuestListTowrite[], short loopcount)
{
	ofstream outfile;
	outfile.open(ReservationFilePath);
	if (outfile.is_open())
	{
		for (int index = 0; index < loopcount; index++)
		{
			outfile << GuestListTowrite[index].getname() << "," << GuestListTowrite[index].getReserId() << "," << GuestListTowrite[index].getage() << ","
				<< GuestListTowrite[index].getgender() << "," << GuestListTowrite[index].getphone() << "," << GuestListTowrite[index].getadd() << ","
				<< GuestListTowrite[index].getroomno() << "," << GuestListTowrite[index].getRoomcharges() << "," << GuestListTowrite[index].getresstart() << "," << GuestListTowrite[index].getresend() << ",";
			if (GuestListTowrite[index].getcheckin().empty() && GuestListTowrite[index].getcheckout().empty())
			{
				outfile << endl;
				continue;
			}
			else {
				outfile << GuestListTowrite[index].getcheckin() << "," << GuestListTowrite[index].getcheckout() << endl;
			}
		}
		outfile.close();
	}
}

void FILE_MANAGER::ReadFoodMenuFromFile(Food_Items fooditemList[])
{
	short index = 0;
	ifstream file;
	file.open(FoodMenuFilePath);
	if (file.is_open())
	{
		string FoodItem, Currentattribute;
		while (getline(file, FoodItem))
		{
			stringstream stream(FoodItem);
			string foodprice, foodname;
			while (getline(stream, Currentattribute, ','))
			{
				if (foodname.empty())
				{
					foodname = Currentattribute;
				}
				else if (foodprice.empty())
				{
					foodprice = Currentattribute;
				}
			}
			fooditemList[index].setfood(foodname);
			fooditemList[index].setprice(foodprice);
			index++;
		}
		file.close();
	}
}
