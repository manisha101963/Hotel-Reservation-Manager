#include "../include/Guest.h"

Guest::Guest() {
    guestId = 0;
    name = "";
    phone = "";
}

Guest::Guest(int id, string guestName, string guestPhone) {
    guestId = id;
    name = guestName;
    phone = guestPhone;
}

int Guest::getGuestId() {
    return guestId;
}

string Guest::getName() {
    return name;
}

string Guest::getPhone() {
    return phone;
}