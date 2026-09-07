#ifndef UPI_PAYMENT_H
#define UPI_PAYMENT_H

#include <iostream>
#include <iomanip>
#include "06_Payment.h"

using namespace std;

class UPIPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "\nProcessing UPI payment..."
             << "\nAmount: Rs."
             << fixed << setprecision(2)
             << amount << endl;

        return true;
    }
};

#endif