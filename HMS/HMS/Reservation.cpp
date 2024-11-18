#include "Reservation.h"
void Reservation::setRoomcharges(const string& charges) { RoomCharges = charges; }
void Reservation::setname(const string& name) { Name = name; }
void Reservation::setReserId(const string& id) { reservation_id = id; }
void Reservation::setphone(const string& phone) { PhoneNO = phone; }
void Reservation::setadd(const string& add) { Address = add; }
void Reservation::setgender(const char& gender) { Gender = gender; }
void Reservation::setage(const short& age) { Age = age; }
void Reservation::setroomNo(const string& roomno) { RoomNo = roomno; }
void Reservation::setcheckin(const string& checkin) { CheckinDate = checkin; };
void Reservation::setcheckout(const string& checkout) { CheckOutDate = checkout; }
void Reservation::setresstart(const string& resS) { resstartDate = resS; }
void Reservation::setresend(const string& resE) { resendDate = resE; }

const string& Reservation::getReserId()const { return reservation_id; }
const string& Reservation::getRoomcharges()const { return RoomCharges; };
const string& Reservation::getname()const { return Name; }
const string& Reservation::getphone()const { return PhoneNO; }
const string& Reservation::getadd()const { return Address; }
const char&   Reservation::getgender()const { return Gender; }
const short&  Reservation::getage()const { return Age; }
const string& Reservation::getcheckin()const { return  CheckinDate; }
const string& Reservation::getcheckout()const { return  CheckOutDate; }
const string& Reservation::getresstart() const { return  resstartDate; }
const string& Reservation::getresend()const { return  resendDate; }
const string& Reservation::getroomno()const { return RoomNo; }