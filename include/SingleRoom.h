#ifndef SINGLEROOM_H
#define SINGLEROOM_H

#include "Room.h"

class SingleRoom : public Room {
public:
    SingleRoom(int num);

    string getRoomType() override;

    void showFeatures() override;
};

#endif