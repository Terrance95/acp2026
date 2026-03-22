#include <stdio.h>

typedef struct {
    int consumerID;
    float unitsConsumed;
    float billAmount;
} Bill;

void input(int n, Bill bills[]);
void calculate_Bills(int n, Bill bills[]);
int findHighestBillIndex(int n, Bill bills[]);
void displayHighestBill(int index, Bill bills[]);

int main() {
    int n;
    Bill bills[100]; 
    int index;

    printf("Enter number of consumers:\n");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid number of consumers (Min: 1, Max: 100).\n");
        return 1;
    }
    if(n<=0){
        printf("invalid n value entered");
        return 0;
    }

    input(n, bills);
    calculate_Bills(n, bills);
    index = findHighestBillIndex(n, bills);
    displayHighestBill(index, bills);

    return 0;
}

void input(int n, Bill bills[]) {
    printf("Enter consumer details (ID and units consumed) for %d consumers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Consumer %d: ", i + 1);
        if (scanf("%d %f", &bills[i].consumerID, &bills[i].unitsConsumed) != 2) {
            printf("Invalid input. Skipping record.\n");
        }
    }
}

void calculate_Bills(int n, Bill bills[]) {
    for (int i = 0; i < n; i++) {
        if (bills[i].unitsConsumed < 0) {
            bills[i].billAmount = 0;
        } else {
            bills[i].billAmount = bills[i].unitsConsumed * 3.5;
        }
    }
}

int findHighestBillIndex(int n, Bill bills[]) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (bills[i].billAmount > bills[maxIndex].billAmount) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void displayHighestBill(int index, Bill bills[]) {
    printf("\nConsumer with highest bill:\n");
    printf("Consumer ID: %d\n", bills[index].consumerID);
    printf("Units Consumed: %.2f\n", bills[index].unitsConsumed);
    printf("Bill Amount: %.2f\n", bills[index].billAmount);
}