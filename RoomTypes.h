#ifndef ROOMTYPES_H
#define ROOMTYPES_H

#include "Room.h"

class SingleRoom : public Room {
public:
    SingleRoom(int num) : Room(num) {}

    string getRoomType() override {
        return "Single Room";
    }
};

class DoubleRoom : public Room {
public:
    DoubleRoom(int num) : Room(num) {}

    string getRoomType() override {
        return "Double Room";
    }
};

class SuiteRoom : public Room {
public:
    SuiteRoom(int num) : Room(num) {}

    string getRoomType() override {
        return "Suite Room";
    }
};

#endif