#ifndef ROOM_H
#define ROOM_H

#include <iostream>
using namespace std;

class Room {
protected:
    int roomNumber;
    bool isBooked;

public:
    Room(int num) {
        roomNumber = num;
        isBooked = false;
    }

    virtual string getRoomType() {
        return "General Room";
    }

    int getRoomNumber() {
        return roomNumber;
    }

    bool getStatus() {
        return isBooked;
    }

    void bookRoom() {
        isBooked = true;
    }

    void cancelBooking() {
        isBooked = false;
    }
};

#endif