#include <iostream>

#include "../include/HotelManager.h"
#include "../include/Guest.h"
#include "../include/Reservation.h"
using namespace std;

void showAllRoomFeatures() {
    SingleRoom single(101);
    DoubleRoom doubleRoom(201);
    DeluxeRoom deluxe(301);

    cout << "\n========== Room Types & Features ==========" << endl;

    cout << "\n[1] Single Room" << endl;
    single.showFeatures();

    cout << "\n[2] Double Room" << endl;
    doubleRoom.showFeatures();

    cout << "\n[3] Deluxe Room" << endl;
    deluxe.showFeatures();

    cout << "\n===========================================" << endl;
}

int main() {

    HotelManager hotel;

    int choice;
    int roomNumber;

    cout << "===================================" << endl;
    cout << "       Welcome to MPS Hotel" << endl;
    cout << "===================================" << endl;

    cout << "\nBefore booking, please check our room types and features." << endl;

    showAllRoomFeatures();

    cout << "\nNow, Which room would you like to book." << endl;

    cout << "\n1. Single Room" << endl;
    cout << "2. Double Room" << endl;
    cout << "3. Deluxe Room" << endl;

    cout << "\nChoose your room type: ";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "\nInvalid choice." << endl;
        return 0;
    }

    hotel.showRoomsByType(choice);

    cout << "\nWhich room number do you want to book? ";
    cin >> roomNumber;

    Room* selectedRoom = hotel.findRoom(roomNumber);

    if (selectedRoom == nullptr) {
        cout << "\nRoom not found." << endl;
        return 0;
    }

    if (selectedRoom->getStatus()) {
        cout << "\nSorry, this room is already booked." << endl;
        return 0;
    }

    cout << "\nRoom " << roomNumber << " is available." << endl;
    cout << "Please enter guest information." << endl;

    int guestId;
    string name;
    string phone;

    cout << "\nEnter Guest ID: ";
    cin >> guestId;

    cin.ignore();

    cout << "Enter Guest Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    Guest guest1(guestId, name, phone);

   string checkInDate;
string checkOutDate;
int nights;

cout << "\nEnter Check-in Date: ";
getline(cin, checkInDate);

cout << "Enter Check-out Date: ";
getline(cin, checkOutDate);

cout << "Enter Number of Nights: ";
cin >> nights;

double totalPrice =
    selectedRoom->getPricePerNight() * nights;

Reservation reservation1(
    1001,
    guest1,
    selectedRoom->getRoomNumber(),
    selectedRoom->getRoomType(),
    checkInDate,
    checkOutDate,
    nights,
    totalPrice
);

selectedRoom->bookRoom();

reservation1.showConfirmation();

return 0;
}