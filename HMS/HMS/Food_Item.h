#pragma once
#include<iostream>
using namespace std;
class Food_Items
{
protected:
	string Foodname;
	string Foodprice;
public:
	

	Food_Items() = default;
	Food_Items(const string& food, const string& price)
		: Foodname(food), Foodprice(price)
	{
	}
	~Food_Items(){}
	void setfood(const string& foodname);
	void setprice(const string& price);
										 
	const string& getfood()const;
	const string& getprice()const;

	friend ostream& operator<<(ostream& stream, const Food_Items& other);
};

