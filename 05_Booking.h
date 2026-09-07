#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>
#include "03_Show.h"
#include "04_Customer.h"

using namespace std;

class Booking {
    int bookingId;
    Show* show;
    Customer* customer;
    vector<string> selectedSeats;
    double totalAmount;
    string status;

public:
    Booking(int id, Show* s, Customer* c)
        : bookingId(id),
          show(s),
          customer(c),
          totalAmount(0),
          status("PENDING") {}

    void addSeat(string seat) {
        selectedSeats.push_back(seat);
    }

    void calculateTotal() {
        totalAmount =
            show->calculateTotal(selectedSeats);
    }

    double getAmount() const {
        return totalAmount;
    }

    int getId() const {
        return bookingId;
    }

    string getStatus() const {
        return status;
    }

    void confirmBooking() {
        status = "CONFIRMED";
    }

    void markBookingAsFailed() {
        status = "FAILED";
    }

    Show* getShow() const {
        return show;
    }
};

#endif