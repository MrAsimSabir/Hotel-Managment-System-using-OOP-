#include "Person.h"
void Person::setname(const string& name) { Name = name; };
void Person::setphone(const string& phone) { PhoneNO = phone; }
void Person::setadd(const string& add) { Address = add; }
void Person::setgender(const char& gender) { Gender = gender; }
void Person::setage(const short& age) { Age = age; }

const string& Person::getname()const { return Name; }
const string& Person::getphone()const { return PhoneNO; }
const string& Person::getadd()const { return Address; }
const char& Person::getgender()const { return Gender; }
const short& Person::getage()const { return Age; }