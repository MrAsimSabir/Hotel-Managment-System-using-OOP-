
#include "EMPLOYEE_MANAGEMENT.h"
#include"Employee.h"
#include"FILE_MANAGER.h"
#include<sstream>
#include<fstream>
#include<string>
#include<Windows.h>
void EMPLOYEE_MANAGEMENT::Create_Employee()
{
	cin.ignore();
	system("cls");
	cout << "\t\t\t\t\t======CREATE EMPLOYEE======" << endl;
	string name, phone, add,username,password,emptype;
	int id=0;
	short age = 0;
	char gender;
	cout << "Enter Employee Type(Manager/Receptionist): ";
	getline(cin, emptype);
	cout << "Enter Employee Name: ";
	getline(cin, name);
	cout << "Enter Employee Age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter Employee Gender: ";
	cin >> gender;
	cin.ignore();
	cout << "Enter Employee Phone Number: ";
	getline(cin, phone);
	cout << "Ente Employee Address: ";
	getline(cin, add);
	srand(time(0));
	id = (rand() % numeric_limits<int>::max()) + 1;
	username = to_string(id);
	password = "user123";
	Employee employee(to_string(id),emptype, username, password, name, phone, add, gender, age);
	ofstream file;
	file.open("employee.txt", ios::app);
	if (file.is_open())
	{
		file << employee.getname() << ","<<employee.getEmployeeType()<<"," << employee.getEmployeeId() << "," << employee.getage() << "," << employee.getgender() << "," << employee.getphone()
			<< "," << employee.getadd() << "," << employee.getUsername() << "," << employee.getPassword() << endl;
		file.close();
	}
}

void EMPLOYEE_MANAGEMENT::Delete_Employee()
{
	cin.ignore();
	system("cls");
	cout << "\t\t\t\t\t======DELETE EMPLOYEE======" << endl;
	bool employeeFound = false;
	string inputId;
	cout << "Enter Id Of Employee You want to Delete: "; 
	getline(cin, inputId);
	FILE_MANAGER ReadWriteFromFile;
	Employee listOfEmployees[10];
	Employee UpdatedListOfEmployees[10];
	short count=ReadWriteFromFile.ReadEmployeeFromFIle(listOfEmployees);
	int index = 0;
	for (int i = 0; i < count; i++)
	{
		if (inputId == listOfEmployees[i].getEmployeeId())
		{
			employeeFound = true;
		}
	}
	if (employeeFound == false)
	{
		cout << "-----EMPLOYEE NOT FOUND-----" << endl;
		Sleep(1500);
		return ;
	}
	for (int i = 0; i < count;i++ )
	{
		if (inputId != listOfEmployees[i].getEmployeeId())
		{
			UpdatedListOfEmployees[index] = listOfEmployees[i];
			//UpdatedListOfEmployees[index].setname(listOfEmployees[i].getname());
			//UpdatedListOfEmployees[index].setEmployeeType(listOfEmployees[i].getEmployeeType());
			//UpdatedListOfEmployees[index].setEmployeeId(listOfEmployees[i].getEmployeeId());
			//UpdatedListOfEmployees[index].setage(listOfEmployees[i].getage());
			//UpdatedListOfEmployees[index].setgender(listOfEmployees[i].getgender());
			//UpdatedListOfEmployees[index].setUsername(listOfEmployees[i].getUsername());
			//UpdatedListOfEmployees[index].setPassword(listOfEmployees[i].getPassword());
			//UpdatedListOfEmployees[index].setphone(listOfEmployees[i].getphone());
			//UpdatedListOfEmployees[index].setadd(listOfEmployees[i].getadd());
			index++;
		}
	}
	ReadWriteFromFile.WriteEmployeesToFile(UpdatedListOfEmployees,index);
}

void EMPLOYEE_MANAGEMENT::View_Employee()
{
	system("cls");
	cout << "\t\t\t\t\t======EMPLOYEES LIST======" << endl;
	cout << endl;
	FILE_MANAGER ReadWriteFromFile;
	Employee listOfEmployees[10];
	short count = ReadWriteFromFile.ReadEmployeeFromFIle(listOfEmployees);
	for (int index = 0; index < count; index++)
	{
		cout << listOfEmployees[index].getname() << "," << listOfEmployees[index].getEmployeeType()<<","<< listOfEmployees[index].getEmployeeId() << "," << listOfEmployees[index].getage() << ","
			<< listOfEmployees[index].getgender() << "," << listOfEmployees[index].getphone() << "," << listOfEmployees[index].getadd() << ","
			<< listOfEmployees[index].getUsername() << "," << listOfEmployees[index].getPassword() << endl;
	}
	cout << "PRESS ENTER TO CONTINUE ";
	_getch();
}

void EMPLOYEE_MANAGEMENT::ResetPassword(string employeeid,string newpassword,string oldpassword)
{
	FILE_MANAGER ReadWriteFromFile;
	Employee listOfEmployees[10];
	Employee UpdatedListOfEmployees[10];
	short count = ReadWriteFromFile.ReadEmployeeFromFIle(listOfEmployees);
	for (int i = 0; i < count; i++)
	{
		if (employeeid == listOfEmployees[i].getEmployeeId())
		{
			if(oldpassword==listOfEmployees[i].getPassword())
				listOfEmployees[i].setPassword(newpassword);
			else
			{
				cout << "Please Enter Correct Old Password: ";
				Sleep(1000);
			}
		}
		//UpdatedListOfEmployees[i] = listOfEmployees[i];
		UpdatedListOfEmployees[i].setname(listOfEmployees[i].getname());
		UpdatedListOfEmployees[i].setEmployeeType(listOfEmployees[i].getEmployeeType());
		UpdatedListOfEmployees[i].setEmployeeId(listOfEmployees[i].getEmployeeId());
		UpdatedListOfEmployees[i].setage(listOfEmployees[i].getage());
		UpdatedListOfEmployees[i].setgender(listOfEmployees[i].getgender());
		UpdatedListOfEmployees[i].setUsername(listOfEmployees[i].getUsername());
		UpdatedListOfEmployees[i].setPassword(listOfEmployees[i].getPassword());
		UpdatedListOfEmployees[i].setphone(listOfEmployees[i].getphone());
		UpdatedListOfEmployees[i].setadd(listOfEmployees[i].getadd());
	}
	ReadWriteFromFile.WriteEmployeesToFile(UpdatedListOfEmployees, count);
}
