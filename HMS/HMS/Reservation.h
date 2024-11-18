#pragma once
#include<iostream>
#include"Date.h"
#include"Customer.h"
#include"Room.h"
using namespace std;
class Reservation
{
protected:
	string reservation_id;
	string Name;
	string PhoneNO;
	string Address;
	char Gender;
	short Age;
	string RoomNo;
	string RoomCharges;
	string CheckinDate;
	string CheckOutDate;
	string resstartDate;
	string resendDate;
public:
	
	Reservation() = default;
	~Reservation(){}
	void setRoomcharges(const string& charges) ;
	void setname(const string& name) ;
	void setReserId(const string& id) ;
	void setphone(const string& phone) ;
	void setadd(const string& add) ;
	void setgender(const char& gender) ;
	void setage(const short& age) ;
	void setroomNo(const string& roomno) ;
	void setcheckin(const string& checkin) ;
	void setcheckout(const string& checkout) ;
	void setresstart(const string& resS) ;
	void setresend(const string& resE) ;

	const string& getReserId()const ;
	const string& getRoomcharges()const ;
	const string& getname()const ;
	const string& getphone()const ;
	const string& getadd()const ;
	const char& getgender()const ;
	const short& getage()const ;
	const string& getcheckin()const ;
	const string& getcheckout()const ;
	const string& getresstart() const ;
	const string& getresend()const ;
	const string& getroomno()const;



	Reservation(const string& reservation_id, const string& Name, const string& PhoneNO, const string& Address, char Gender, short Age, const string& RoomNo, const string& CheckinDate, const string& CheckOutDate, const string& resstartDate, const string& resendDate)
		: reservation_id(reservation_id), Name(Name), PhoneNO(PhoneNO), Address(Address), Gender(Gender), Age(Age), RoomNo(RoomNo), CheckinDate(CheckinDate), CheckOutDate(CheckOutDate), resstartDate(resstartDate), resendDate(resendDate)
	{
	}

	Reservation(const string& reservation_id, const string& Name, const string& PhoneNO, const string& Address, char Gender, short Age, const string& RoomNo,const string& charges,  const string& resstartDate, const string& resendDate)
		: reservation_id(reservation_id), Name(Name), PhoneNO(PhoneNO), Address(Address), Gender(Gender), Age(Age), RoomNo(RoomNo),RoomCharges(charges), resstartDate(resstartDate), resendDate(resendDate)
	{
	}
	friend ostream& operator<<(ostream& os, const Reservation& ToPrint)
	{
		os << ToPrint.Name << "," << ToPrint.reservation_id << "," << ToPrint.Age << "," << ToPrint.Gender << "," << ToPrint.PhoneNO << "," << ToPrint.Address << "," << ToPrint.RoomNo << "," <<ToPrint.RoomCharges<<","<<
			ToPrint.resstartDate << "," << ToPrint.resendDate << "," << ToPrint.CheckinDate << "," << ToPrint.CheckOutDate << endl;
		return os;
	}
};

