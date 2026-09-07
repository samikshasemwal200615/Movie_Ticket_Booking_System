#ifndef CARD_PAYMENT_H
#define CARD_PAYMENT_H

#include <iostream>
#include <iomanip>
#include "06_Payment.h"

using namespace std;

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "\nProcessing Card payment..."
             << "\nAmount: Rs."
             << fixed << setprecision(2)
             << amount << endl;

        return true;
    }
};

#endif