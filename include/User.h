#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
private:
    string username;
    string password;
    string email;

public:
    User();

    User(string user,
         string pass,
         string mail);

    string getUsername();
    string getPassword();
    string getEmail();

    void registerUser();

    bool login();
};

#endif