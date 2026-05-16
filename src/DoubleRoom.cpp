#include "../include/DoubleRoom.h"
#include <iostream>
DoubleRoom::DoubleRoom(int num)
    : Room(num) {
}

string DoubleRoom::getRoomType() {
    return "Double Room";
}
void DoubleRoom::showFeatures() {
    cout << "Double Room Features:" << endl;
    cout << "- 2 beds" << endl;
    cout << "- Private bathroom" << endl;
    cout << "- Sauna included" << endl;
    cout << "- TV" << endl;
    cout << "- Room key" << endl;
    cout << "- Extra charges for additional services" << endl;
}