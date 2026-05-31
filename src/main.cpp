#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <sstream>

#include "../include/HotelManager.h"
#include "../include/Guest.h"
#include "../include/Reservation.h"
#include "../include/Payment.h"
#include "../include/User.h"


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
    bool empty = true;

    cout << "\n========== Saved Reservations ==========" << endl;

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

bool isRoomAvailableForDates(int roomNumber, string newCheckIn, string newCheckOut) {
    ifstream inFile("data/reservations.txt");

    if (!inFile.is_open()) {
        return true;
    }

    string line;

    while (getline(inFile, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string reservationId;
        string guestId;
        string guestName;
        string phone;
        string roomNumberText;
        string roomType;
        string oldCheckIn;
        string oldCheckOut;

        getline(ss, reservationId, '|');
        getline(ss, guestId, '|');
        getline(ss, guestName, '|');
        getline(ss, phone, '|');
        getline(ss, roomNumberText, '|');
        getline(ss, roomType, '|');
        getline(ss, oldCheckIn, '|');
        getline(ss, oldCheckOut, '|');

        int oldRoomNumber;

        try {
            oldRoomNumber = stoi(roomNumberText);
        }
        catch (...) {
            continue;
        }

        if (oldRoomNumber == roomNumber) {
            if (newCheckIn < oldCheckOut && newCheckOut > oldCheckIn) {
                inFile.close();
                return false;
            }
        }
    }

    inFile.close();
    return true;
}

int main() {

    HotelManager hotel;
    //hotel.loadBookedRoomsFromFile();

    while (true) {

        int mainChoice;

        cout << "\n1. Book Room" << endl;
        cout << "2. View Reservations" << endl;
        cout << "3. Cancel Reservation" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> mainChoice;

        if (mainChoice == 2) {
            viewReservations();
            continue;
        }

        if (mainChoice == 3) {
            cancelReservation();
            continue;
        }

        if (mainChoice == 4) {
            cout << "\nThank you for visiting MPS Hotel." << endl;
            break;
        }

        if (mainChoice != 1) {
            cout << "\nInvalid choice." << endl;
            continue;
        }

        int choice;
        int roomNumber;

        cout << "\n===================================" << endl;
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
            continue;
        }

        bool validRoomChoice = false;

        do {
            cout << "\nPlease choose your preferred room type: ";
            cin >> choice;

            if (choice < 1 || choice > 3) {
                cout << "\nSorry, we do not have that room type." << endl;
                cout << "Please choose again." << endl;
            }

            else if (guestCount == 2 && choice == 1) {
                cout << "\nSingle Room is not suitable for 2 guests." << endl;
                cout << "Please choose Double Room or Deluxe Room." << endl;
            }

            else if (guestCount >= 3 && choice != 3) {
                cout << "\nFor 3 or 4 guests, only Deluxe Room is available." << endl;
                cout << "Please choose Deluxe Room." << endl;
            }

            else {
                validRoomChoice = true;
            }

        } while (!validRoomChoice);

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

           else if (!isRoomAvailableForDates(roomNumber, checkInDate, checkOutDate)) {
                cout << "\nSorry, this room is already booked for those dates." << endl;
                cout << "Please choose another room number." << endl;
                selectedRoom = nullptr;

            }

        } while (selectedRoom == nullptr);

        cout << "\nRoom " << roomNumber << " is available." << endl;
        cout << "Please enter guest information." << endl;

        User currentUser;
        int userChoice;
        bool loggedIn = false;

cout << "\nTo continue booking, you must login or register." << endl;

do {
    cout << "\n1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter choice: ";
    cin >> userChoice;

    if (userChoice == 1) {
        currentUser.registerUser();
        loggedIn = currentUser.login();
    }
    else if (userChoice == 2) {
        loggedIn = currentUser.login();
    }
    else {
        cout << "Invalid choice. Please try again." << endl;
    }

} while (!loggedIn);

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

        double totalPrice = selectedRoom->getPricePerNight() * nights;

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
    }

    return 0;
}