#ifndef PAYMENT_SERVICE_H
#define PAYMENT_SERVICE_H

#include "06_Payment.h"

class PaymentService {
public:
    bool processPayment(double amount, Payment& payment) {
        return payment.pay(amount);
    }
};

#endif