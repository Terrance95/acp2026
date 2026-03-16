#include <stdio.h>
#include <string.h>

typedef struct {
    int flight_number;
    char destination[50];
    int available_seats;
} Flight_t;

// Function Prototypes
void readFlights(int n, Flight_t f[]);
void searchByDestination(int n, Flight_t f[], char searchDest[]);

int main() {
    int n = 4; // As specified: Create an array of 4 flights
    Flight_t flights[n];
    char searchDest[50];

    // Read flight details
    readFlights(n, flights);

    // Get search input from user
    printf("\nEnter destination to search for: ");
    scanf("%s", searchDest);

    // Search for flight
    searchByDestination(n, flights, searchDest);

    return 0;
}

void readFlights(int n, Flight_t f[]) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Flight %d:\n", i + 1);
        printf("Flight Number: ");
        scanf("%d", &f[i].flight_number);
        printf("Destination: ");
        scanf("%s", f[i].destination);
        printf("Available Seats: ");
        scanf("%d", &f[i].available_seats);
    }
}

void searchByDestination(int n, Flight_t f[], char searchDest[]) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        // strcmp returns 0 if the strings match
        if (strcmp(f[i].destination, searchDest) == 0) {
            printf("\nFlight available: %d\n", f[i].flight_number);
            printf("Seats remaining: %d\n", f[i].available_seats);
            found = 1;
            break; // Stop searching once found
        }
    }

    if (!found) {
        printf("\nNo flight available to %s\n", searchDest);
    }
}