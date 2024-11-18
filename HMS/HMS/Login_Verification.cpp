#include "Login_Verification.h"
#include"Admin.h"
#include"FILE_MANAGER.h"
string Login_Management::getPassword() {
	string password;
	char ch;
	while ((ch = _getch()) != '\r') {
		if (ch == '\b') {
			if (!password.empty()) {
				password.pop_back();
				cout << "\b \b";
			}
		}
		else {
			password.push_back(ch);
			cout << "*";
		}
	}
	cout << endl;
	return password;
}
string Login_Management::Check_Login(const string& userType)
{
	string input_username, input_password, saved_username, saved_password;
	ifstream file;
	cin.ignore();
	system("cls");
	cout << "\t\t\t\t\t======LOGIN======" << endl;
	cout << "Enter Username : ";
	getline(cin, input_username);
	cout << "Enter Password : ";
	input_password = getPassword();
	if (userType == "admin")
	{
		Admin* adminData = new Admin;
		file.open(adminFilePath);
		if (file.is_open())
		{
			string str;
			getline(file, str);
			stringstream stream(str);
			stream >> saved_username >> saved_password;
			adminData->setUsername(saved_username);
			adminData->setPassword(saved_password);
			file.close();
		}
		if (adminData->getUsername() == input_username && adminData->getPassword() == input_password)
		{
			delete adminData;
			adminData = nullptr;
			return "success,admin";
		}
		else
		{
			delete adminData;
			return "failure,admin";
		}

	}
	else if (userType == "employee")
	{		
		FILE_MANAGER filemanager;
		Employee EmployeesList[10];
		short count = filemanager.ReadEmployeeFromFIle(EmployeesList);
		for (int index = 0; index < count; index++)
		{
			if (input_username == EmployeesList[index].getUsername() && input_password == EmployeesList[index].getPassword())
			{
				if (EmployeesList[index].getEmployeeType() == "Manager")
				{
					return "success,Manager";
				}
				else if (EmployeesList[index].getEmployeeType() == "Receptionist")
				{
					return "success,Receptionist";
				}
			}
		}
		return "failure";
	}
	
}


