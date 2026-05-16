#include "../include/SingleRoom.h"

SingleRoom::SingleRoom(int num)
    : Room(num) {
}

string SingleRoom::getRoomType() {
    return "Single Room";
}