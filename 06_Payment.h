#ifndef PAYMENT_H
#define PAYMENT_H

class Payment {
public:
    virtual bool pay(double amount) = 0;

    virtual ~Payment() {}
};

#endif