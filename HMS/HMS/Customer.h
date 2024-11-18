#pragma once
#include<iostream>
#include"Person.h"
using namespace std;
class Customer : public Person
{
protected:
	string CustomerID;
public:

	Customer() = default;
	Customer(const string& CustomerID)
		: CustomerID(CustomerID)
	{
	}

	const string& getCustomerid()const { return CustomerID; }
	void setCustomerid(const string& id) { CustomerID = id; };

	
};

