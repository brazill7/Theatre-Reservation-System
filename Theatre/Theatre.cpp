#include "Theatre.h"
#include <iostream>
#include <fstream>

Theatre::Theatre(int rows, int seatsPerRow) : rows(rows), seatsPerRow(seatsPerRow){
    //check for dimension
    if (rows <= 0 || rows > MAX_ROWS || seatsPerRow <= 0 || seatsPerRow > MAX_SEATSPERROW) {
        std::cerr << "Invalid theater size. Maximum rows: " << MAX_ROWS << ", Maximum seats per row: " << MAX_SEATSPERROW << std::endl;
        exit(EXIT_FAILURE); //quit the program if invalid dimension
    }

    seatChart.resize(rows, vector<Seat>(seatsPerRow)); // set correct dimensions 
    initializeSeatChart(); // generate seatChart 
};

void Theatre::readSeatChart(const string &filename) {
    ifstream file(filename);

    if (file.is_open()) {
        for (int i = 0; i < rows; ++i) {
            int rowNum;
            file >> rowNum;

            for (int j = 0; j < seatsPerRow; ++j) {
                char seatNumber;
                file >> seatNumber;

                seatChart[i][j] = Seat(rowNum, seatNumber);  //updates seatChart to what we have in the txt file
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file - " << filename << std::endl;
    }
};

void Theatre::displayMenu(){
    cout << "1. Display Seat Chart" << endl;
    cout << "2. Reserve a Seat" << endl;
    cout << "3. Cancel Reservation" << endl;
    cout << "4. Save Seat to File" << endl;
    cout << "5. Statistics" << endl;
    cout << "6. Help" << endl;
    cout << "7. Exit" << endl;
}

int Theatre::getUserChoice(){
    int choice;

    do{
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
    }while (choice < 1 || choice > 7);

    return choice;
}

void Theatre::displaySeatChart(){
    for (auto &row : seatChart){
            cout << row[0].getRow() << " "; //ROW : 0,1,2...
        for (auto &seat : row){
            cout << seat.getSeatNumber() << " "; //NUM : A,B,C X...
        }
        cout << endl;
    }
}

void Theatre::reserveSeat() {
    int row, seatIndex;

    cout << "Enter the row number: ";
    cin >> row;

    if (row < 1 || row > rows) {
        cout << "Invalid row number." << endl;
        return;
    }

    cout << "Enter the seat letter (A, B, C, ...): ";
    char seatLetter;
    cin >> seatLetter;
    seatLetter = toupper(seatLetter); //all seat letters are uppercase

    seatIndex = seatLetter - 'A';

    if (seatIndex < 0 || seatIndex >= seatsPerRow) {
        cout << "Invalid seat letter." << endl;
        return;
    }

    Seat &selectedSeat = seatChart[row - 1][seatIndex]; //get selected seat

    if (selectedSeat.getSeatNumber() == 'X') {
        cout << "Sorry, the seat is already reserved." << endl;
    } else {
        selectedSeat.bookSeat(); //set selected seat number... A B C... to X
        cout << "Seat reserved successfully." << endl;
    }
}

void Theatre::writeSeatChartToFile(const string &filename = "currentSeatChart.txt") {
    ofstream file(filename);

    if (file.is_open()) {
        for (int i = 0; i < rows; ++i) {
            file << i + 1 << " ";
            for (int j = 0; j < seatsPerRow; ++j) {
                file << seatChart[i][j].getSeatNumber() << " "; //display each seat and their number, A B C .... X
            }
            file << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file - " << filename << endl;
    }
}

void Theatre::initializeSeatChart() {
    for (int i = 0; i < rows; ++i) {
        char seatNumber = 'A';
        for (int j = 0; j < seatsPerRow; ++j) {
            seatChart[i][j] = Seat(i + 1, seatNumber, seatNumber);  //update seat chart
            ++seatNumber; // A-> B ... B -> C... C -> D......
        }
    }
}

void Theatre::cancelSeat(){
    int row, seatIndex;

    cout << "Enter the row number: ";
    cin >> row;

    if (row < 1 || row > rows) {
        cout << "Invalid row number." << endl;
        return;
    }

    cout << "Enter the seat letter (A, B, C, ...): ";
    char seatLetter;
    cin >> seatLetter;
    seatLetter = toupper(seatLetter); //all seat letters are uppercase

    seatIndex = seatLetter - 'A';

    if (seatIndex < 0 || seatIndex >= seatsPerRow) {
        cout << "Invalid seat letter." << endl;
        return;
    }

    Seat &selectedSeat = seatChart[row - 1][seatIndex]; //get selected seat

    if (selectedSeat.getSeatNumber() == 'X') {
        selectedSeat.cancelReservation(); //Cancel Seat 
        cout << "Seat cancelled successfully." << endl;
    } else {
        cout << "ERROR: Seat wasn't booked, could not cancel" << endl;
    }
}

void Theatre::displayStatistics(){
    int totalSeats = rows * seatsPerRow;
    int reservedSeats = 0;

    // Count reserved seats
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < seatsPerRow; ++j) {
            if (seatChart[i][j].getIsBooked()) {
                ++reservedSeats;
            }
        }
    }

    int availableSeats = totalSeats - reservedSeats;
    float percentageReserved = static_cast<float>(reservedSeats) / totalSeats * 100.0;

    cout << "Number of available seats: " << availableSeats << endl;
    cout << "Percentage of seats that are reserved: " << fixed << setprecision(2) << percentageReserved << "%" << endl;

    // List aisle and interior seats
    vector<string> aisleSeats;
    vector<string> interiorSeats;

    for (int i = 0; i < rows; ++i) { //aisle seats
        for(int j = 0; j < seatsPerRow; ++j){
            if (j == 0 || j == seatsPerRow - 1){ //IS AISLE SEAT
                string firstSeat = seatChart[i][j].getSeatString();

                if(find(firstSeat.begin(), firstSeat.end(), 'X') == firstSeat.end()){
                    aisleSeats.push_back(firstSeat);
                } //first seat

            }else{ //IS Interior SEAT
                string currentSeat = seatChart[i][j].getSeatString();
                if(find(currentSeat.begin(), currentSeat.end(), 'X') == currentSeat.end()){
                    //isnt booked
                    interiorSeats.push_back(currentSeat);
                }
            }
        }

        
    }

    cout << "List of aisle seats that are available:" << endl;
    for (const auto &aisleSeat : aisleSeats) {
        cout << aisleSeat << " ";
    }
    cout << endl;

    cout << "List of interior seats that are available:" << endl;
    for (const auto &interiorSeat : interiorSeats) {
        cout << interiorSeat << " ";
    }
    cout << endl;
}

void Theatre::displayHelp(){
    cout << endl;
    cout << "1) Display Seat Chart -- this will display a " << rows << " by " << seatsPerRow << " table displaying the Seats, if they are available they will be displayed as a number... A, B, C... and a X if it is reserved."<< endl;
    cout << "2) Reserve Seat -- this will ask you first for a row number... 1,2,3... then will ask you for the seat letter, this will be... A,B,C... This will then switch the letter to a X which will signify that it is booked" << endl;
    cout << "3) Cancel Reservation -- this will ask you first for a row number... 1,2,3... then the seat you booked...A,B,C... it will then make sure that that seat is currently being displayed as X and if it is it will toggle it back to its original letter... A,B,C...if it isn't it will let the user know it wasn't booked, and not do anything" << endl;
    cout << "4) Save Seat Chart to File -- this will save the current seat chart with updated bookings to a file called currentSeatChart.txt" << endl;
    cout << "5) Statistics -- this will calculate the amount of seats left that arent booked, it will also show that in a percent, this being percent of seats booked, it will then calculate the amount of aisle seats that are available and list those, aisle seats are seats in the first and last columns, it will also do this with the interior seats, interior seats are all the seats in between the aisle seats" << endl;
    cout << "7) Quit -- This will exit the program" << endl;
}