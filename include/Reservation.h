#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include "Guest.h"

using namespace std;

class Reservation {
private:
    int reservationId;
    Guest guest;
    int roomNumber;
    string roomType;
    string checkInDate;
    string checkOutDate;
    int nights;
    double totalPrice;

public:
    Reservation();

    Reservation(int id,
                Guest guestInfo,
                int roomNum,
                string type,
                string checkIn,
                string checkOut,
                int numberOfNights,
                double total);

    double calculateTotal(double pricePerNight, int numberOfNights);

    void showConfirmation();

    int getReservationId();
    int getRoomNumber();
};

#endif