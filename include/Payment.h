#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
using namespace std;

class Payment {
private:
    string paymentMethod;
    string cardHolderName;
    string cardNumber;

public:
    Payment();

    Payment(string method, string holder, string card);

    string getPaymentMethod();
    string getMaskedCardNumber();

    bool processPayment();
};

#endif