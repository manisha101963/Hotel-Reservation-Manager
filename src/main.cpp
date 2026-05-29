#include <iostream>
#include <fstream>
#include <cctype>
#include <limits>
#include <vector>
#include <sstream>

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
void viewReservations() {
    ifstream inFile("data/reservations.txt");

    if (!inFile.is_open()) {
        cout << "\nNo reservation file found." << endl;
        return;
    }

    string line;

    cout << "\n========== Saved Reservations ==========" << endl;

    bool empty = true;

    while (getline(inFile, line)) {

        if (!line.empty()) {
            empty = false;
            cout << line << endl;
        }
    }

    if (empty) {
        cout << "\nNo reservations found yet." << endl;
    }

    cout << "========================================" << endl;

    inFile.close();
}

void cancelReservation() {

    ifstream inFile("data/reservations.txt");

    if (!inFile.is_open()) {
        cout << "\nReservation file not found." << endl;
        return;
    }

    vector<string> reservations;

    string line;
    int cancelId;

    cout << "\nEnter Reservation ID to cancel: ";
    cin >> cancelId;

    bool found = false;

    while (getline(inFile, line)) {

        stringstream ss(line);

        string reservationIdText;

        getline(ss, reservationIdText, '|');

       if (reservationIdText.empty()) {
    continue;
}

int reservationId;

try {
    reservationId = stoi(reservationIdText);
}
catch (...) {
    continue;
}

        if (reservationId == cancelId) {
            found = true;
            continue;
        }

        reservations.push_back(line);
    }

    inFile.close();

    ofstream outFile("data/reservations.txt");

    for (string reservation : reservations) {
        outFile << reservation << endl;
    }

    outFile.close();

    if (found) {
        cout << "\nReservation cancelled successfully." << endl;
    }
    else {
        cout << "\nReservation ID not found." << endl;
    }
}
int getNextReservationId() {
    ifstream inFile("data/reservations.txt");

    if (!inFile.is_open()) {
        return 1001;
    }

    string line;
    int maxId = 1000;

    while (getline(inFile, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string idText;

        getline(ss, idText, '|');

        try {
            int id = stoi(idText);

            if (id > maxId) {
                maxId = id;
            }
        }
        catch (...) {
            continue;
        }
    }

    inFile.close();

    return maxId + 1;
}
int main() {

    HotelManager hotel;
    hotel.loadBookedRoomsFromFile();
     int mainChoice;

cout << "\n1. Book Room" << endl;
cout << "2. View Reservations" << endl;
cout << "3. Cancel Reservation" << endl;
cout << "4. Exit" << endl;
cout << "Enter choice: ";
cin >> mainChoice;

if (mainChoice == 2) {
    viewReservations();
    return 0;
}

if (mainChoice == 3) {
    cancelReservation();
    return 0;
}

if (mainChoice == 4) {
    cout << "\nThank you for visiting MPS Hotel." << endl;
    return 0;
}

if (mainChoice != 1) {
    cout << "\nInvalid choice." << endl;
    return 0;
}
    int choice;
    int roomNumber;

    cout << "===================================" << endl;
    cout << "       Welcome to MPS Hotel" << endl;
    cout << "===================================" << endl;

    cout << "\nBefore booking, please check our room types and features." << endl;

    showAllRoomFeatures();


string checkInDate;
string checkOutDate;
int guestCount;

cin.ignore();

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
    cout << "Enter Number of Guests: ";
    cin >> guestCount;

    if (guestCount <= 0) {
        cout << "Guest count must be greater than 0." << endl;
    }

} while (guestCount <= 0);
if (guestCount == 1) {

    cout << "\nBased on your guest count, we recommend:" << endl;

    cout << "\n1. Single Room" << endl;
    cout << "   - Perfect for solo travelers" << endl;
    cout << "   - Budget-friendly and comfortable" << endl;

    cout << "\n2. Double Room" << endl;
    cout << "   - Extra space for added comfort" << endl;
    cout << "   - Great for relaxing stays" << endl;

    cout << "\n3. Deluxe Room" << endl;
    cout << "   - Premium luxury experience" << endl;
    cout << "   - Best for maximum comfort" << endl;
}

else if (guestCount == 2) {

    cout << "\nBased on your guest count, we recommend:" << endl;

    cout << "\n1. Double Room" << endl;
    cout << "   - Perfect for couples and friends" << endl;
    cout << "   - Comfortable for 2 guests" << endl;

    cout << "\n2. Deluxe Room" << endl;
    cout << "   - Extra space and luxury experience" << endl;
    cout << "   - Ideal for premium comfort" << endl;
}
else if (guestCount <= 4) {
   cout << "\nBased on your guest count, we recommend:" << endl;
cout << "1. Deluxe Room" << endl;
cout << "   - Best for families and groups" << endl;
cout << "   - Maximum 4 guests" << endl;
}

else {
    cout << "\nSorry, we do not support more than 4 guests per room." << endl;
    return 0;
}
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
ofstream guestFile("data/guests.txt", ios::app);

if (guestFile.is_open()) {
    guestFile << guest1.getGuestId() << "|"
              << guest1.getName() << "|"
              << guest1.getPhone() << endl;

    guestFile.close();
}

   
int nights;

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

    bool validCardHolder = true;

    if (cardHolderName.empty()) {
        validCardHolder = false;
    }

    for (char c : cardHolderName) {
        if (!isalpha(c) && c != ' ') {
            validCardHolder = false;
            break;
        }
    }

    if (!validCardHolder) {
        cout << "Invalid card holder name. Please enter letters only." << endl;
    }
    else {
        break;
    }

} while (true);

do {
    cout << "Enter Card Number: ";
    getline(cin, cardNumber);

    bool validCard = true;

    if (cardNumber.empty()) {
        validCard = false;
    }

    for (char c : cardNumber) {
        if (!isdigit(c)) {
            validCard = false;
            break;
        }
    }

    if (!validCard) {
        cout << "Invalid card number. Please enter digits only." << endl;
    }
    else {
        break;
    }

} while (true);

Payment payment1(
    paymentMethod,
    cardHolderName,
    cardNumber
);

int nextReservationId = getNextReservationId();
payment1.processPayment();
ofstream paymentFile("data/payments.txt", ios::app);

if (paymentFile.is_open()) {

    paymentFile << nextReservationId << "|"
                << paymentMethod << "|"
                << payment1.getMaskedCardNumber()
                << endl;
    paymentFile.close();
}

Reservation reservation1(
    nextReservationId,
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

int nextChoice;

cout << "\n===================================" << endl;
cout << "What would you like to do next?" << endl;
cout << "1. Book Another Room" << endl;
cout << "2. Exit" << endl;
cout << "Enter choice: ";
cin >> nextChoice;

if (nextChoice == 1) {

    cout << "\nRestarting booking system..." << endl;

    main();
}

else {

    cout << "\nThank you for choosing MPS Hotel!" << endl;
}

return 0;
}