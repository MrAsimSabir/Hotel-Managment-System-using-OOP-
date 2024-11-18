#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
class Login_Management
{
protected:
	const string adminFilePath = "admin.txt";
	const string employeeFilePath = "employee.txt";
public:
	string getPassword();
	string Check_Login(const string& userType);
		Login_Management() = default;
	~Login_Management(){}
};

