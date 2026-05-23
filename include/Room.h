#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

class Room {
protected:
    int roomNumber;
    bool isBooked;
    double pricePerNight;

public:
    Room(int num, double price);

    virtual string getRoomType();

    int getRoomNumber();

    bool getStatus();

    double getPricePerNight();

    void bookRoom();

    void cancelBooking();

    virtual void showFeatures();
};

#endif