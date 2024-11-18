#include "Food_Item.h"
void Food_Items::setfood(const string& foodname) { Foodname = foodname; }
void Food_Items::setprice(const string& price) { Foodprice = price; }

const string& Food_Items::getfood()const { return Foodname; }
const string& Food_Items::getprice()const { return Foodprice; }

ostream& operator<<(ostream& stream, const Food_Items& other)
{
	stream << other.Foodname << "," << other.Foodprice << endl;
	return stream;
}
