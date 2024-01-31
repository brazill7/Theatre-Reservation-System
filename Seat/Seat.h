#pragma once
#include <iostream>

class Seat{
    private:
        int row;
        char seatNumber, seatNumberBackup;
    public:
        Seat(int row = 0, char seatNumber = 'A', char seatNumberBackup = 'A');

        int getRow();
        char getSeatNumber();
        void bookSeat();
        void cancelReservation();
        std::string getSeatString();
        bool getIsBooked();
};