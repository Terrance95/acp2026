#include <stdio.h>

typedef struct {
    int units;
    float rate;
    float total_bill;
} ElectricityBill;

ElectricityBill input();
ElectricityBill calculate_bill(ElectricityBill bill);
void output(ElectricityBill bill);

int main() {
    ElectricityBill bill;

    bill = input();
    
    if (bill.units < 0 || bill.rate < 0) {
        printf("Error: Units and Rate must be non-negative.\n");
        return 1; 
    }

    bill = calculate_bill(bill);
    output(bill);

    return 0;
}

ElectricityBill input() {
    ElectricityBill bill;

    printf("Enter units consumed:\n");
    scanf("%d", &bill.units);

    printf("Enter rate per unit:\n");
    scanf("%f", &bill.rate);

    return bill;
}

ElectricityBill calculate_bill(ElectricityBill bill) {
    // Edge Case: Threshold logic
    // If the requirement is "less than 50", then 50 is charged.
    if (bill.units < 50) {
        bill.total_bill = 0.0;
    } else {
        bill.total_bill = (float)bill.units * bill.rate;
    }

    return bill;
}

void output(ElectricityBill bill) {
    printf("\nUnits Consumed: %d\n", bill.units);
    printf("Rate per Unit: %.2f\n", bill.rate);
    
    if (bill.total_bill == 0.0 && bill.units > 0) {
        printf("Total Bill: 0.00 (Minimum usage threshold not met)\n");
    } else {
        printf("Total Bill: %.2f\n", bill.total_bill);
    }
}