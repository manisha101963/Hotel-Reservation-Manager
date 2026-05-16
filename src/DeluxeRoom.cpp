#include "../include/DeluxeRoom.h"
#include <iostream>
DeluxeRoom::DeluxeRoom(int num)
    : Room(num) {
}

string DeluxeRoom::getRoomType() {
    return "Deluxe Room";
}
void DeluxeRoom::showFeatures() {
    cout << "Deluxe Room Features:" << endl;
    cout << "- King size bed" << endl;
    cout << "- Private bathroom" << endl;
    cout << "- Sauna included" << endl;
    cout << "- Private bar" << endl;
    cout << "- Private swimming pool" << endl;
    cout << "- TV projector" << endl;
    cout << "- Premium room key" << endl;
}