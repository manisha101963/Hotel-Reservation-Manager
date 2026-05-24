#include "../include/Payment.h"
#include <iostream>

using namespace std;

Payment::Payment() {
    paymentMethod = "";
    cardHolderName = "";
    cardNumber = "";
}

Payment::Payment(string method, string holder, string card) {
    paymentMethod = method;
    cardHolderName = holder;
    cardNumber = card;
}

string Payment::getPaymentMethod() {
    return paymentMethod;
}

string Payment::getMaskedCardNumber() {
    if (cardNumber.length() >= 4) {
        return "****" + cardNumber.substr(cardNumber.length() - 4);
    }

    return "Invalid Card";
}

bool Payment::processPayment() {
    cout << "\nProcessing payment..." << endl;
    cout << "Payment successful!" << endl;
    return true;
}