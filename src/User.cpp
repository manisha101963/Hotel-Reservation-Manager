#include "../include/User.h"

#include <iostream>

using namespace std;

User::User() {
    username = "";
    password = "";
    email = "";
}

User::User(string user,
           string pass,
           string mail) {

    username = user;
    password = pass;
    email = mail;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

string User::getEmail() {
    return email;
}

void User::registerUser() {

    cout << "\n===== User Registration ====="
         << endl;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    cout << "Enter Email: ";
    cin >> email;

    cout << "\nRegistration Successful!"
         << endl;
}

bool User::login() {

    string inputUser;
    string inputPass;

    cout << "\n===== Login ====="
         << endl;

    cout << "Enter Username: ";
    cin >> inputUser;

    cout << "Enter Password: ";
    cin >> inputPass;

    if (inputUser == username &&
        inputPass == password) {

        cout << "\nLogin Successful!"
             << endl;

        return true;
    }

    cout << "\nInvalid Username or Password."
         << endl;

    return false;
}