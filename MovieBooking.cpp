#include <iostream>
#include <vector>

using namespace std;

// Constants for the number of rows and columns in the theater
const int NUM_ROWS = 5;
const int NUM_COLS = 10;

// Represents a seat
struct Seat {
    bool isAvailable;
    int row;
    int col;
};

// Represents a movie
struct Movie {
    string title;
    string time;
    double price;
};

// Function to display the seating chart
void displaySeatingChart(const vector<vector<Seat>>& theater) {
    cout << "Seating Chart:\n";
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            if (theater[i][j].isAvailable) {
                cout << "O "; // Available seat
            } else {
                cout << "X "; // Booked seat
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to display available movies
void displayMovies(const vector<Movie>& movies) {
    cout << "Available Movies:\n";
    for (int i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].title << " (" << movies[i].time << ") - $" << movies[i].price << endl;
    }
    cout << endl;
}

int main() {
    // Initialize the theater seating chart
    vector<vector<Seat>> theater(NUM_ROWS, vector<Seat>(NUM_COLS, {true, 0, 0}));

    // Initialize available movies
    vector<Movie> movies = {
        {"Movie 1", "10:00 AM", 750.0},
        {"Movie 2", "1:00 PM", 650.0},
        {"Movie 3", "4:00 PM", 750.0},
    };

    while (true) {
        cout << "Welcome to the Movie Ticket Booking System!\n";
        displayMovies(movies);

        int choice;
        cout << "Enter the number of the movie you want to watch (0 to exit): ";
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > movies.size()) {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        // Display the seating chart for the selected movie
        int selectedMovieIndex = choice - 1;
        displaySeatingChart(theater);

        int row, col;
        cout << "Enter the row and column of the seat you want to book (e.g., 1 5): ";
        cin >> row >> col;

        if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS) {
            cout << "Invalid seat selection. Please try again.\n";
            continue;
        }

        // Check seat availability
        if (theater[row - 1][col - 1].isAvailable) {
            // Book the seat
            theater[row - 1][col - 1].isAvailable = false;
            theater[row - 1][col - 1].row = row;
            theater[row - 1][col - 1].col = col;

            // Calculate and display the total cost
            double totalCost = movies[selectedMovieIndex].price;
            cout << "Seat booked successfully! Total cost: $" << totalCost << endl;
        } else {
            cout << "Seat already booked. Please select another seat.\n";
        }
    }

    cout << "Thank you for using the Movie Ticket Booking System!\n";

    return 0;
}
