#include <iostream>
#include <vector>

#include "01_Movie.h"
#include "02_Seat.h"
#include "03_Show.h"
#include "04_Customer.h"
#include "07_UPIPayment.h"
#include "08_CardPayment.h"
#include "12_BookingService.h"

using namespace std;

int main() {

    Movie movie(
        101,
        "Avengers: Endgame",
        "English",
        181
    );

    movie.displayDetails();

    Show show(501, movie);

    show.addSeat(Seat(1, "A1", "SILVER", 150));
    show.addSeat(Seat(2, "A2", "SILVER", 150));
    show.addSeat(Seat(3, "B1", "GOLD", 250));
    show.addSeat(Seat(4, "B2", "GOLD", 250));

    Customer customer(
        1,
        "Samiksha",
        "9873XXXXXX",
        "samiksha@email.com"
    );

    customer.registerCustomer();

    show.displaySeats();

    BookingService bookingService;

    UPIPayment payment;

    vector<string> selectedSeats = {
        "A1",
        "B1"
    };

    bookingService.bookTicket(
        customer,
        show,
        selectedSeats,
        payment
    );

    return 0;
}