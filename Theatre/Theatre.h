#pragma once
#include "../Seat/Seat.cpp"
#include <vector>

using namespace std;


class Theatre{
    private:
        const int MAX_ROWS = 50;
        const int MAX_SEATSPERROW = 26;
        int rows;
        int seatsPerRow;
        vector<vector<Seat> > seatChart;

    public:
        Theatre(int rows, int seatsPerRow);

        void writeSeatChartToFile(const string &fileName);
        void readSeatChart(const string &fileName);
        void displayMenu();
        int getUserChoice();
        void displaySeatChart();
        void reserveSeat();
        void initializeSeatChart();
        void cancelSeat();
        void displayStatistics();
        void displayHelp();

};