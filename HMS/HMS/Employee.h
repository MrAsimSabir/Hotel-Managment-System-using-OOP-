#pragma once
#include<iostream>
#include"Person.h"
using namespace std;
class Employee :public Person
{
protected:
    string EmployeeType;
	string EmployeeId;
	string Username;
	string Password;
public:

	Employee() = default;
	Employee(const string& EmployeeId,const string& empType, const string& Username, const string& Password,const string& n,const string& phone,const string& add,const char& gen,const short& a)
		: Person(n,phone,add,gen,a),EmployeeId(EmployeeId), Username(Username), Password(Password),EmployeeType(empType)
	{
	}
	Employee(Employee& other);
	~Employee(){}
    const string& getEmployeeType()const ;
    void setEmployeeType(const string& emptype) ;
    const string& getEmployeeId() const;
    const string& getUsername() const;
    const string& getPassword() const;
    void setEmployeeId(const string& employeeId);
    void setUsername(const string& username);
	void setPassword(const string& password);
	
};

