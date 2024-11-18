#pragma once
#include<iostream>
#include<string>
#include"Person.h"
using namespace std;
class Admin:public Person
{
protected:
	string Username;
	string Password;
public:
    Admin(const string& Username, const string& Password)
        : Username(Username), Password(Password){}
    Admin() = default;
    ~Admin(){}
    const string& getUsername() const;
    const string& getPassword() const;
    void setUsername(const string& username);
    void setPassword(const string& password);
};

