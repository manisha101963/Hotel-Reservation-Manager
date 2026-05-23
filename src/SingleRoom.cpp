#include "../include/SingleRoom.h"
#include <iostream>
SingleRoom::SingleRoom(int num)
    : Room(num,70000) {
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
     cout << "- Price per night: "
         << getPricePerNight()
         << " KRW" << endl;
}
