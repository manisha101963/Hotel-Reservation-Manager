#include "../include/Reservation.h"

#include <iostream>

using namespace std;

Reservation::Reservation() {
    reservationId = 0;
    roomNumber = 0;
    roomType = "";
    checkInDate = "";
    checkOutDate = "";
    nights = 0;
    totalPrice = 0;
}

Reservation::Reservation(int id,
                         Guest guestInfo,
                         int roomNum,
                         string type,
                         string checkIn,
                         string checkOut,
                         int numberOfNights,
                         double total,
                         Payment paymentInfo
                        ) {
    reservationId = id;
    guest = guestInfo;
    roomNumber = roomNum;
    roomType = type;
    checkInDate = checkIn;
    checkOutDate = checkOut;
    nights = numberOfNights;
    totalPrice = total;
    payment = paymentInfo;
}

double Reservation::calculateTotal(double pricePerNight, int numberOfNights) {
    return pricePerNight * numberOfNights;
}

void Reservation::showConfirmation() {
    cout << "\n===================================" << endl;
    cout << "      Reservation Confirmed" << endl;
    cout << "===================================" << endl;

    cout << "Reservation ID: " << reservationId << endl;
    cout << "Room Number: " << roomNumber << endl;
    cout << "Room Type: " << roomType << endl;

    cout << "\nGuest Information" << endl;
    cout << "Guest ID: " << guest.getGuestId() << endl;
    cout << "Name: " << guest.getName() << endl;
    cout << "Phone: " << guest.getPhone() << endl;

    cout << "\nCheck-in Date: " << checkInDate << endl;
    cout << "Check-out Date: " << checkOutDate << endl;
    cout << "Number of Nights: " << nights << endl;
    cout << "Total Price: " << totalPrice << " KRW" << endl;
    cout << "\nPayment Information" << endl;
cout << "Payment Method: "
     << payment.getPaymentMethod() << endl;

cout << "Card Number: "
     << payment.getMaskedCardNumber() << endl;

    cout << "\nThank you for choosing MPS Hotel!" << endl;
}

int Reservation::getReservationId() {
    return reservationId;
}

int Reservation::getRoomNumber() {
    return roomNumber;
}