#ifndef BOOKING_SERVICE_H
#define BOOKING_SERVICE_H

#include <iostream>
#include <vector>
#include <string>

#include "03_Show.h"
#include "04_Customer.h"
#include "05_Booking.h"
#include "06_Payment.h"
#include "09_PaymentService.h"
#include "10_BookingDatabase.h"
#include "11_TicketService.h"

using namespace std;

class BookingService {
    PaymentService paymentService;
    BookingDatabase database;
    TicketService ticketService;

public:
    void bookTicket(
        Customer& customer,
        Show& show,
        const vector<string>& selectedSeats,
        Payment& payment
    ) {
        cout << "\nBOOKING\n";

        for (const string& seat : selectedSeats) {
            if (!show.bookSeat(seat)) {
                cout << "Seat "
                     << seat
                     << " is unavailable.\n";
                return;
            }
        }

        Booking booking(1001, &show, &customer);

        for (const string& seat : selectedSeats) {
            booking.addSeat(seat);
        }

        booking.calculateTotal();

        cout << "\nTotal Amount: Rs."
             << fixed << setprecision(2)
             << booking.getAmount()
             << endl;

        bool success =
            paymentService.processPayment(
                booking.getAmount(),
                payment
            );

        if (success) {
            cout << "\nPayment Successful\n";

            booking.confirmBooking();

            database.saveBooking(&booking);

            ticketService.generateTicket(&booking);
        }
        else {
            cout << "\nPayment Failed\n";

            for (const string& seat : selectedSeats) {
                show.releaseSeat(seat);
            }

            booking.markBookingAsFailed();

            cout << "Seats released.\n";
            cout << "Booking marked as FAILED.\n";
            cout << "Customer notified.\n";
        }
    }
};

#endif