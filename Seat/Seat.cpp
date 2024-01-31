#include "Seat.h"

using std::to_string;

Seat::Seat(int row, char seatNumber, char seatNumberBackup) : row(row), seatNumber(seatNumber), seatNumberBackup(seatNumber) {}

int Seat::getRow() {
    return row;
}

char Seat::getSeatNumber() {
    return seatNumber;
}

void Seat::bookSeat() {
    seatNumber = 'X';
}

void Seat::cancelReservation(){
    seatNumber = seatNumberBackup;
}

bool Seat::getIsBooked(){
    return (seatNumber == 'X');
}

std::string Seat::getSeatString(){
    return to_string(row) + seatNumber;
}
