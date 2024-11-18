#include "Room.h"
void Room::setroomNo(const string& roomno) { RoomNo = roomno; }
void Room::setroomavail(const string& avail) { RoomAvail = avail; }
void Room::setroomcharges(const float& charges) { RoomCharges = charges; };

const string& Room::getroomno()const { return RoomNo; }
const string& Room::getroomavail()const { return RoomAvail; }
const float&  Room::getroomcharges()const { return RoomCharges; }

ostream& operator<<(ostream& stream, const Room& other)
{
    stream << other.RoomNo << "," << other.RoomCharges << "," << other.RoomAvail << endl;
    return stream;
}
