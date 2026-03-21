#include <stdio.h>

typedef struct {
    int units;
    float rate;
    float total_bill;
} ElectricityBill;

// Function prototypes
ElectricityBill input();
ElectricityBill calculate_bill(ElectricityBill bill);
void output(ElectricityBill bill);

int main() {
    ElectricityBill bill;

    bill = input();
    bill = calculate_bill(bill);
    output(bill);

    return 0;
}

// Function to read input
ElectricityBill input() {
    ElectricityBill bill;

    printf("Enter units consumed:\n");
    scanf("%d",&bill.units);
    // TODO: read units using scanf

    printf("Enter rate per unit:\n");
    scanf("%f",&bill.rate);
    // TODO: read rate using scanf

    return bill;
}

// Function to calculate bill
ElectricityBill calculate_bill(ElectricityBill bill) {

    // TODO: if units < 50 then bill = 0
    // TODO: else calculate bill = units * rate
    if(bill.units<50){
        bill.total_bill=0;
    }
    else{
        bill.total_bill=bill.units*bill.rate;
    }

    return bill;
}

// Function to display result
void output(ElectricityBill bill) {
    printf("\nUnits Consumed: %d\n", bill.units);
    printf("Rate per Unit: %.2f\n", bill.rate);
    printf("Total Bill: %.2f\n", bill.total_bill);
}