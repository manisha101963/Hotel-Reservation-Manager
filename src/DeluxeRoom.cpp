#include "../include/DeluxeRoom.h"

DeluxeRoom::DeluxeRoom(int num)
    : Room(num) {
}

string DeluxeRoom::getRoomType() {
    return "Deluxe Room";
}