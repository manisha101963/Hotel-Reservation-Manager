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

bool isValidEmail(string email) {
    if (email.empty()) {
        return false;
    }

    if (email.find('@') == string::npos ||
        email.find('.') == string::npos) {
        return false;
    }

    if (email.front() == '@' || email.back() == '@') {
        return false;
    }

    return true;
}

void User::registerUser() {
    cout << "\n===== User Registration =====" << endl;

    do {
        cout << "Create Username: ";
        cin >> username;

        if (username.empty()) {
            cout << "Username cannot be empty." << endl;
        }

    } while (username.empty());

    do {
        cout << "Create Password: ";
        cin >> password;

        if (password.length() < 4) {
            cout << "Password must be at least 4 characters." << endl;
        }

    } while (password.length() < 4);

    do {
        cout << "Enter Email: ";
        cin >> email;

        if (!isValidEmail(email)) {
            cout << "Invalid email format. Please try again." << endl;
        }

    } while (!isValidEmail(email));

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

    cout << "Enter Username: ";
    cin >> inputUsername;

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