#include "Theatre/Theatre.cpp"

int main(){
    string FILE = "chartIn.txt";
    int usrChoice, rows, seatsPerRow;

    do{
        cout << "Enter the amount of rows in your Theatre: ";
        cin >> rows;
        cout << endl;

        cout << "Enter the amount of seats per row in your Theatre: ";
        cin >> seatsPerRow;
        cout << endl;
    }while(cin.fail());

    Theatre theatre(rows, seatsPerRow);
    theatre.writeSeatChartToFile(FILE);
    theatre.readSeatChart(FILE);

    do{
        theatre.displayMenu();
        usrChoice = theatre.getUserChoice();

        switch(usrChoice){
            case 1:
                theatre.displaySeatChart();
                cout << endl;
                break;
            case 2:
                theatre.reserveSeat();
                cout << endl;
                break;
            case 3:
                theatre.cancelSeat();
                cout << endl;
                break;
            case 4:
                theatre.writeSeatChartToFile();
                cout << "Seat Chart successfully saved" << endl;
                cout << endl;
                break;
            case 5:
                theatre.displayStatistics();
                cout << endl;
                break;
            case 6:
                theatre.displayHelp();
                cout << endl;
                break;
            case 7:
                break;
        }
    }while(usrChoice != 7);
};