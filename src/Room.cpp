#include "../include/Room.h"

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