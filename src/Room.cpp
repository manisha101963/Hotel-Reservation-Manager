#include "../include/Room.h"
#include <iostream>
Room::Room(int num) {
    roomNumber = num;
    isBooked = false;
}

string Room::getRoomType() {
    return "General Room";
}

int Room::getRoomNumber() {
    return roomNumber;
}

bool Room::getStatus() {
    return isBooked;
}

void Room::bookRoom() {
    isBooked = true;
}

void Room::cancelBooking() {
    isBooked = false;
}

void Room::showFeatures() {
    cout << "General room features." << endl;
}