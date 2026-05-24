#include <iostream>
#include <fstream>
#include <cctype>
#include <limits>

#include "../include/HotelManager.h"
#include "../include/Guest.h"
#include "../include/Reservation.h"
#include "../include/Payment.h"

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
bool isValidDate(string date) {
    if (date.length() != 10) {
        return false;
    }

    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    for (int i = 0; i < date.length(); i++) {
        if (i == 4 || i == 7) {
            continue;
        }

        if (!isdigit(date[i])) {
            return false;
        }
    }

    return true;
}

int main() {

    HotelManager hotel;
    hotel.loadBookedRoomsFromFile();

    int choice;
    int roomNumber;

    cout << "===================================" << endl;
    cout << "       Welcome to MPS Hotel" << endl;
    cout << "===================================" << endl;

    cout << "\nBefore booking, please check our room types and features." << endl;

    showAllRoomFeatures();

do {
    cout << "\nPlease choose your preferred room type:";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "\nSorry, we do not have that room type." << endl;
        cout << "Please choose again." << endl;
    }

} while (choice < 1 || choice > 3);
if (choice == 1) {
    cout << "\nExcellent choice!" << endl;
    cout << "Our Single Rooms are perfect for solo travelers." << endl;
    cout << "Let's continue with your booking." << endl;
}

else if (choice == 2) {
    cout << "\nPerfect choice!" << endl;
    cout << "Our Double Rooms are great for couples and friends." << endl;
    cout << "Let's continue with your booking." << endl;
}

else if (choice == 3) {
    cout << "\nWonderful choice!" << endl;
    cout << "Our Deluxe Rooms offer premium luxury and comfort." << endl;
    cout << "Let's continue with your booking." << endl;
}
    hotel.showRoomsByType(choice);

   Room* selectedRoom = nullptr;

do {
    cout << "\nWhich room number do you want to book? ";
    cin >> roomNumber;

    selectedRoom = hotel.findRoom(roomNumber);

    if (selectedRoom == nullptr) {
        cout << "\nSorry, that room does not exist." << endl;
        cout << "Please choose an available room number." << endl;
    }

} while (selectedRoom == nullptr);

    cout << "\nRoom " << roomNumber << " is available." << endl;
    cout << "Please enter guest information." << endl;

    int guestId;
    string name;
    string phone;

while (true) {
    cout << "\nEnter Guest ID: ";
    cin >> guestId;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Guest ID. Please enter numbers only." << endl;
    }
    else {
        cin.ignore(1000, '\n');
        break;
    }
}

do {
    cout << "Enter Guest Name: ";
    getline(cin, name);

    bool validName = true;

    if (name.empty()) {
        validName = false;
    }

    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            validName = false;
            break;
        }
    }

    if (!validName) {
        cout << "Invalid name. Please enter letters only." << endl;
    }
    else {
        break;
    }

} while (true);

do {
    cout << "Enter Phone Number: ";
    getline(cin, phone);

    bool validPhone = true;

    if (phone.empty()) {
        validPhone = false;
    }

    for (char c : phone) {
        if (!isdigit(c)) {
            validPhone = false;
            break;
        }
    }

    if (!validPhone) {
        cout << "Invalid phone number. Please enter digits only." << endl;
    }
    else {
        break;
    }

} while (true);

Guest guest1(guestId, name, phone);

   string checkInDate;
string checkOutDate;
int nights;

do {
    cout << "\nEnter Check-in Date (YYYY-MM-DD): ";
    getline(cin, checkInDate);

    if (!isValidDate(checkInDate)) {
        cout << "Invalid date format. Please use YYYY-MM-DD." << endl;
    }

} while (!isValidDate(checkInDate));

do {
    cout << "Enter Check-out Date (YYYY-MM-DD): ";
    getline(cin, checkOutDate);

    if (!isValidDate(checkOutDate)) {
        cout << "Invalid date format. Please use YYYY-MM-DD." << endl;
    }

} while (!isValidDate(checkOutDate));

do {
    cout << "Enter Number of Nights: ";
    cin >> nights;

    if (nights <= 0) {
        cout << "Number of nights must be greater than 0." << endl;
    }

} while (nights <= 0);

double totalPrice =
    selectedRoom->getPricePerNight() * nights;
    string paymentMethod;
string cardHolderName;
string cardNumber;

cin.ignore();

int paymentChoice;

do {
    cout << "\nSelect Payment Method" << endl;
    cout << "1. Credit Card" << endl;
    cout << "2. Debit Card" << endl;

    cout << "Enter choice: ";
    cin >> paymentChoice;

    if (paymentChoice == 1) {
        paymentMethod = "Credit Card";
    }
    else if (paymentChoice == 2) {
        paymentMethod = "Debit Card";
    }
    else {
        cout << "Invalid payment option. Please try again." << endl;
    }

} while (paymentChoice != 1 && paymentChoice != 2);

cin.ignore();

do {
    cout << "Enter Card Holder Name: ";
    getline(cin, cardHolderName);

    if (cardHolderName.empty()) {
        cout << "Card holder name cannot be empty." << endl;
    }

} while (cardHolderName.empty());

do {
    cout << "Enter Card Number: ";
    getline(cin, cardNumber);

    if (cardNumber.empty()) {
        cout << "Card number cannot be empty." << endl;
    }

} while (cardNumber.empty());

Payment payment1(
    paymentMethod,
    cardHolderName,
    cardNumber
);

payment1.processPayment();
static int nextReservationId = 1001;
Reservation reservation1(
  nextReservationId++,
    guest1,
    selectedRoom->getRoomNumber(),
    selectedRoom->getRoomType(),
    checkInDate,
    checkOutDate,
    nights,
    totalPrice,
    payment1
);

selectedRoom->bookRoom();

reservation1.showConfirmation();
ofstream outFile("data/reservations.txt", ios::app);

if (outFile.is_open()) {
    outFile << reservation1.getReservationId() << "|"
            << guest1.getGuestId() << "|"
            << guest1.getName() << "|"
            << guest1.getPhone() << "|"
            << selectedRoom->getRoomNumber() << "|"
            << selectedRoom->getRoomType() << "|"
            << checkInDate << "|"
            << checkOutDate << "|"
            << nights << "|"
            << totalPrice << endl;

    outFile.close();

    cout << "\nReservation saved to file successfully." << endl;
}
else {
    cout << "\nError: Could not open reservations file." << endl;
}

return 0;
}