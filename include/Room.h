#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;

class Room {
protected:
    int roomNumber;
    bool isBooked;

public:
    Room(int num);

    virtual string getRoomType();

    int getRoomNumber();
    bool getStatus();

    void bookRoom();
    void cancelBooking();

    virtual void showFeatures();
};

#endif