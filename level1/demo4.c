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
    int n = 4; 
    Flight_t flights[n];
    char searchDest[50];

    readFlights(n, flights);

    printf("\nEnter destination to search for: ");
    if (scanf(" %s", searchDest) != 1) {
        return 1;
    }

    searchByDestination(n, flights, searchDest);

    return 0;
}

void readFlights(int n, Flight_t f[]) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Flight %d (Number Destination Seats):\n", i + 1);
        // Combined scanf for stability in automated testing
        if (scanf("%d %s %d", &f[i].flight_number, f[i].destination, &f[i].available_seats) != 3) {
            // Handle error if needed
        }
    }
}

void searchByDestination(int n, Flight_t f[], char searchDest[]) {
    int found = 0;

    for (int i = 0; i < i < n; i++) {
        if (strcmp(f[i].destination, searchDest) == 0) {
            printf("\nFlight available: %d\n", f[i].flight_number);
            printf("Seats remaining: %d\n", f[i].available_seats);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("\nNo flight available to %s\n", searchDest);
    }
}