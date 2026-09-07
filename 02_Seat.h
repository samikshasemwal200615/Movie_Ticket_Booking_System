#ifndef SEAT_H
#define SEAT_H
#include <string>
using namespace std;
class Seat {
    int seatId;
    string seatNumber, seatType;
    double price;
    bool available;
public:
    Seat(int id, string number, string type, double p)
        : seatId(id),
          seatNumber(number),
          seatType(type),
          price(p),
          available(true) {}

    string getNumber() const {
        return seatNumber;
    }
    string getType() const {
        return seatType;
    }
    double getPrice() const {
        return price;
    }
    bool isAvailable() const {
        return available;
    }
    void book() {
        available = false;
    }
    void release() {
        available = true;
    }
};
#endif