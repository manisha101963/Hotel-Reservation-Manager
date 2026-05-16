#include "../include/HotelManager.h"

#include <iostream>

using namespace std;

HotelManager::HotelManager() {

    roomCount = 0;

    for (int i = 101; i <= 110; i++) {
        rooms[roomCount] = new SingleRoom(i);
        roomCount++;
    }

    for (int i = 201; i <= 210; i++) {
        rooms[roomCount] = new DoubleRoom(i);
        roomCount++;
    }

    for (int i = 301; i <= 310; i++) {
        rooms[roomCount] = new DeluxeRoom(i);
        roomCount++;
    }
}

void HotelManager::showRoomsByType(int choice) {

    cout << "\nAvailable Rooms:" << endl;

    for (int i = 0; i < roomCount; i++) {

        if (choice == 1 &&
            rooms[i]->getRoomType() == "Single Room") {

            cout << rooms[i]->getRoomNumber();

            if (rooms[i]->getStatus()) {
                cout << " - Booked";
            }

            else {
                cout << " - Available";
            }

            cout << endl;
        }

        else if (choice == 2 &&
                 rooms[i]->getRoomType() == "Double Room") {

            cout << rooms[i]->getRoomNumber();

            if (rooms[i]->getStatus()) {
                cout << " - Booked";
            }

            else {
                cout << " - Available";
            }

            cout << endl;
        }

        else if (choice == 3 &&
                 rooms[i]->getRoomType() == "Deluxe Room") {

            cout << rooms[i]->getRoomNumber();

            if (rooms[i]->getStatus()) {
                cout << " - Booked";
            }

            else {
                cout << " - Available";
            }

            cout << endl;
        }
    }
}

Room* HotelManager::findRoom(int roomNumber) {

    for (int i = 0; i < roomCount; i++) {

        if (rooms[i]->getRoomNumber() == roomNumber) {
            return rooms[i];
        }
    }

    return nullptr;
}