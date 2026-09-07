#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer {
    int customerId;
    string name, contact, email;

public:
    Customer(int id, string n, string c, string e)
        : customerId(id),
          name(n),
          contact(c),
          email(e) {}

    void registerCustomer() const {
        cout << "\nCustomer registered: "
             << name << endl;
    }
};

#endif