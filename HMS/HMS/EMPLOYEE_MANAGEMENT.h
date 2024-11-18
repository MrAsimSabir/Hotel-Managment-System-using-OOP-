#pragma once
#include<iostream>
using namespace std;
class EMPLOYEE_MANAGEMENT
{
public:
	void Create_Employee();
	void Delete_Employee();
	void View_Employee();
	void ResetPassword(string,string,string);
	EMPLOYEE_MANAGEMENT() = default;
	~EMPLOYEE_MANAGEMENT(){}
};

