#ifndef BOOKING_DATABASE_H
#define BOOKING_DATABASE_H

#include <iostream>
#include <vector>
#include "05_Booking.h"

using namespace std;

class BookingDatabase {
    vector<Booking*> bookings;

public:
    void saveBooking(Booking* booking) {
        bookings.push_back(booking);

        cout << "\nBooking #"
             << booking->getId()
             << " saved successfully.\n";
    }
};

#endif