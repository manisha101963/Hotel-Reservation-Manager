#include <iostream>

#include "../include/HotelManager.h"
#include "../include/Guest.h"

using namespace std;

int main() {

    HotelManager hotel;

    int choice;
    int roomNumber;

    cout << "===================================" << endl;
    cout << "       Welcome to MPS Hotel" << endl;
    cout << "===================================" << endl;

    cout << "\nHow can we help you?" << endl;

    cout << "\n1. Single Room" << endl;
    cout << "2. Double Room" << endl;
    cout << "3. Deluxe Room" << endl;

    cout << "\nChoose your room type: ";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "\nInvalid choice." << endl;
        return 0;
    }

    if (choice == 1) {
        SingleRoom tempRoom(101);
        cout << "\n";
        tempRoom.showFeatures();
    }
    else if (choice == 2) {
        DoubleRoom tempRoom(201);
        cout << "\n";
        tempRoom.showFeatures();
    }
    else if (choice == 3) {
        DeluxeRoom tempRoom(301);
        cout << "\n";
        tempRoom.showFeatures();
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

    selectedRoom->bookRoom();

    cout << "\nRoom booked successfully!" << endl;
    cout << "Booked Room Number: " << selectedRoom->getRoomNumber() << endl;
    cout << "Room Type: " << selectedRoom->getRoomType() << endl;

    cout << "\nGuest Information" << endl;
    cout << "Guest ID: " << guest1.getGuestId() << endl;
    cout << "Name: " << guest1.getName() << endl;
    cout << "Phone: " << guest1.getPhone() << endl;

    return 0;
}