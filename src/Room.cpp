#include "../include/Room.h"

Room::Room(int num, double price) {

    roomNumber = num;
    pricePerNight = price;
    isBooked = false;
}

string Room::getRoomType() {
    return "Room";
}

int Room::getRoomNumber() {
    return roomNumber;
}

bool Room::getStatus() {
    return isBooked;
}

double Room::getPricePerNight() {
    return pricePerNight;
}

void Room::bookRoom() {
    isBooked = true;
}

void Room::cancelBooking() {
    isBooked = false;
}

void Room::showFeatures() {

}