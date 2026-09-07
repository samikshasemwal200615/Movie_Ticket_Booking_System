#ifndef TICKET_SERVICE_H
#define TICKET_SERVICE_H

#include <iostream>
#include <iomanip>
#include "05_Booking.h"

using namespace std;

class TicketService {
public:
    void generateTicket(Booking* booking) {
        cout << "\nTICKET\n";

        cout << "Booking ID : "
             << booking->getId() << endl;

        cout << "Movie      : "
             << booking->getShow()->getMovieTitle()
             << endl;

        cout << "Amount     : Rs."
             << fixed << setprecision(2)
             << booking->getAmount()
             << endl;

        cout << "Status     : "
             << booking->getStatus()
             << endl;
    }
};

#endif