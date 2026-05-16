#include "../include/DoubleRoom.h"

DoubleRoom::DoubleRoom(int num)
    : Room(num) {
}

string DoubleRoom::getRoomType() {
    return "Double Room";
}