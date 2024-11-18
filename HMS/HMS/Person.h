#pragma once
#include<iostream>
using namespace std;
class Person
{
protected:
	string Name;
	string PhoneNO;
	string Address;
	char Gender;
	short Age;
public:

	Person() = default;
	~Person(){}
	void setname(const string& name) ;
	void setphone(const string& phone) ;
	void setadd(const string& add) ;
	void setgender(const char& gender) ;
	void setage(const short& age) ;

	const string& getname()const ;
	const string& getphone()const ;
	const string& getadd()const ;
	const char& getgender()const ;
	const short& getage()const;

	Person(const string& Name, const string& PhoneNO, const string& Address,const char& Gender,const short& Age)
		: Name(Name), PhoneNO(PhoneNO), Address(Address), Gender(Gender), Age(Age)
	{
	}


};

