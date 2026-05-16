#include <iostream>
#include "../include/SingleRoom.h"
#include "../include/DoubleRoom.h"
#include "../include/DeluxeRoom.h"

using namespace std;

int main() {

    SingleRoom room1(101);
    DoubleRoom room2(201);
    DeluxeRoom room3(301);

    cout << room1.getRoomType() << endl;
    cout << room2.getRoomType() << endl;
    cout << room3.getRoomType() << endl;

    return 0;
}