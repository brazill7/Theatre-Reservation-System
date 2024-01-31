## Theatre Reservation System  -- done with C++ Classes

This project aims to provide a comprehensive solution for calculating a student's GPA (Grade Point Average) based on inputted credit hours and grades for their classes. The GPA Calculator simplifies the process of GPA calculation by offering a command-line interface for inputting class information and obtaining the total GPA.

### Components

#### Main Program (`main()` function)

- Asks For the amount of rows, and seats per row in your Theatre in order to initialize a Theatre class with the correct dimensions for each user
- It then displays a menu with 7 options for the user to choose from
    - [Display the Seat Chart](#seat_chart)
    - [Reserve a Seat](#seat_reserve)
    - [Cancel Seat Reservation](#seat_cancel)
    - [Write the Current Seat Chart to a File](#write_seat)
    - [Display Statistics](#display_stats)
    - [Display Help](#seat_help)
    - Exit
 
#### Seat Class (`Seat.h` and `Seat.cpp`)

- Responsible for holding the value of where it is located in the theatre (row # and seat #... 1A... 3C...2D)
- Contains methods to book the seat (change the letter to X), cancel the reservation (change the letter back to A..B..C..etc.), and return the seat letter, row number, and a boolean is booked value.

#### Theatre Class (`Theatre.h` and `Theatre.cpp`)

- Upon intialization it will first make sure the Theatre is within its bounds (<50 rows ... <26 seats per row)
- If it is within its bounds, then it will create a vector of seats with the correct dimensions and size as our theatre, it will also then initialize our seat chart text file, which is how we are storing the data
- After this it then contains 6 methods that are able to be run by the user

  * <a name="seat_chart"></a>**Display Seat Chart**: Displays the current seat chart to the console, indicating which seats are available and which are reserved.
   
  * <a name="seat_reserve"></a>**Reserve a Seat**: Allows the user to reserve a seat by entering the row number and seat letter. If the seat is available, it will be marked as reserved.

  * <a name="seat_cancel"></a>**Cancel Seat Reservation**: Allows the user to cancel a previously reserved seat by entering the row number and seat letter. If the seat is reserved, the reservation will be canceled.

  * <a name="write_seat"></a>**Write the Current Seat Chart to a File**: Writes the current seat chart to a file named `currentSeatChart.txt`.

  * <a name="display_stats"></a>**Display Statistics**: Calculates and displays statistics about the seat reservations, including the number of available seats, the percentage of seats that are reserved, and lists available aisle and interior seats.

  * <a name="seat_help"></a>**Display Help**: Provides helpful information about each menu option to the user.
