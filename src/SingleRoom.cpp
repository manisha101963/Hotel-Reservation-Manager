#include "../include/SingleRoom.h"
#include <iostream>
SingleRoom::SingleRoom(int num)
    : Room(num) {
}

string SingleRoom::getRoomType() {
    return "Single Room";
}
void SingleRoom::showFeatures() {
    cout << "Single Room Features:" << endl;
    cout << "- 1 bed" << endl;
    cout << "- Private bathroom" << endl;
    cout << "- Sauna included" << endl;
    cout << "- Room key" << endl;
    cout << "- Extra charges for additional services" << endl;
}