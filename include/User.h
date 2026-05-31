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

    string getUsername();
    string getEmail();

    void registerUser();
    bool login();
};

#endif