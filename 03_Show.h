#ifndef SHOW_H
#define SHOW_H

#include <iostream>
#include <vector>
#include <string>
#include "01_Movie.h"
#include "02_Seat.h"

using namespace std;

class Show {
    int showId;
    Movie movie;
    vector<Seat> seats;

public:
    Show(int id, Movie m)
        : showId(id), movie(m) {}

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }

    void displaySeats() const {
        cout << "\nSEAT LAYOUT\n";

        for (const Seat& seat : seats) {
            cout << seat.getNumber()
                 << " [" << seat.getType() << "] Rs."
                 << seat.getPrice()
                 << " - "
                 << (seat.isAvailable() ? "AVAILABLE" : "BOOKED")
                 << endl;
        }
    }

    bool bookSeat(const string& number) {
        for (Seat& seat : seats) {
            if (seat.getNumber() == number &&
                seat.isAvailable()) {
                seat.book();
                return true;
            }
        }

        return false;
    }

    void releaseSeat(const string& number) {
        for (Seat& seat : seats) {
            if (seat.getNumber() == number) {
                seat.release();
            }
        }
    }

    double calculateTotal(
        const vector<string>& selectedSeats
    ) const {
        double total = 0;

        for (const string& number : selectedSeats) {
            for (const Seat& seat : seats) {
                if (seat.getNumber() == number) {
                    total += seat.getPrice();
                }
            }
        }

        return total;
    }

    string getMovieTitle() const {
        return movie.getTitle();
    }
};

#endif