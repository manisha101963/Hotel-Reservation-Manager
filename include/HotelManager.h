#ifndef HOTELMANAGER_H
#define HOTELMANAGER_H

#include "Room.h"
#include "SingleRoom.h"
#include "DoubleRoom.h"
#include "DeluxeRoom.h"

class HotelManager {
private:
    Room* rooms[30];
    int roomCount;

public:
    HotelManager();

    void showRoomsByType(int choice);

    Room* findRoom(int roomNumber);
    void loadBookedRoomsFromFile();
};

#endif