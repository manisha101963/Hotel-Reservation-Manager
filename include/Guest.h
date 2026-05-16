#ifndef GUEST_H
#define GUEST_H

#include <string>
using namespace std;

class Guest {
private:
    int guestId;
    string name;
    string phone;

public:
    Guest();
    Guest(int id, string guestName, string guestPhone);

    int getGuestId();
    string getName();
    string getPhone();
};

#endif