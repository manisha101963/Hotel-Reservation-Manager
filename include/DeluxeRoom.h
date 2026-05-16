#ifndef DELUXEROOM_H
#define DELUXEROOM_H

#include "Room.h"

class DeluxeRoom : public Room {
public:
    DeluxeRoom(int num);

    string getRoomType() override;

    void showFeatures() override;
};

#endif