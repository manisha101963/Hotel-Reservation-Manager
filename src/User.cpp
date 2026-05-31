#include "../include/User.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

User::User() {
    username = "";
    password = "";
    email = "";
}

string User::getUsername() {
    return username;
}

string User::getEmail() {
    return email;
}

void User::registerUser() {
    cout << "\n===== User Registration =====" << endl;

    cout << "Create Username: ";
    cin >> username;

    cout << "Create Password: ";
    cin >> password;

    cout << "Enter Email: ";
    cin >> email;

    ofstream outFile("data/users.txt", ios::app);

    if (outFile.is_open()) {
        outFile << username << "|"
                << password << "|"
                << email << endl;

        outFile.close();

        cout << "\nRegistration successful!" << endl;
        cout << "Please login to continue booking." << endl;
    }
    else {
        cout << "\nError: Could not save user data." << endl;
    }
}

bool User::login() {
    string inputUsername;
    string inputPassword;

    cout << "\n===== User Login =====" << endl;

   do {
    cout << "Enter Email: ";
    cin >> email;

    bool validEmail = true;

    if (email.find('@') == string::npos ||
        email.find('.') == string::npos) {

        validEmail = false;
    }

    if (!validEmail) {
        cout << "Invalid email format. Please try again." << endl;
    }
    else {
        break;
    }

} while (true);

    cout << "Enter Password: ";
    cin >> inputPassword;

    ifstream inFile("data/users.txt");

    if (!inFile.is_open()) {
        cout << "\nNo registered users found. Please register first." << endl;
        return false;
    }

    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);

        string savedUsername;
        string savedPassword;
        string savedEmail;

        getline(ss, savedUsername, '|');
        getline(ss, savedPassword, '|');
        getline(ss, savedEmail, '|');

        if (inputUsername == savedUsername &&
            inputPassword == savedPassword) {

            username = savedUsername;
            password = savedPassword;
            email = savedEmail;

            inFile.close();

            cout << "\nLogin successful!" << endl;
            cout << "Welcome, " << username << "!" << endl;

            return true;
        }
    }

    inFile.close();

    cout << "\nInvalid username or password." << endl;
    return false;
}