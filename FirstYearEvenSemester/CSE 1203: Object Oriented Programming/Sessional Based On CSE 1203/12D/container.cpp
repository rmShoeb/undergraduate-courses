#include<cstring>
class Room;
class House
{
public:
    House(const string);
    void addRoom(const Room&);
private:
    Room *m_room;
    string m_name;
};
