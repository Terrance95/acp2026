#include <stdio.h>

typedef struct {
    int units;
    float rate, total_bill;
} ElectricityBill;

ElectricityBill input();
ElectricityBill calculate_bill(ElectricityBill bill);
void output(ElectricityBill bill);

int main() {
    ElectricityBill bill;

    bill = input();
    
    if (bill.units < 0 || bill.rate < 0) {
        printf("Invalid input values.\n");
        return 0;
    }

    bill = calculate_bill(bill);
    output(bill);

    return 0;
}

ElectricityBill input() {
    ElectricityBill bill;

    printf("Enter units consumed: ");
    scanf("%d", &bill.units);

    printf("Enter rate per unit: ");
    scanf("%f", &bill.rate);

    return bill;
}

ElectricityBill calculate_bill(ElectricityBill bill) {
    if (bill.units > 100) {
        printf("High consumption alert! Extra charge applied.\n");
        
        // Logic: First 100 units at normal rate + Remaining units at (rate + 5)
        float base_charge = 100 * bill.rate;
        float extra_units = bill.units - 100;
        float extra_charge = extra_units * (bill.rate + 5);
        
        bill.total_bill = base_charge + extra_charge;
    } 
    else {
        bill.total_bill = bill.units * bill.rate;
    }

    return bill;
}

void output(ElectricityBill bill) {
    printf("Units Consumed: %d\n", bill.units);
    printf("Rate per Unit: %.2f\n", bill.rate);
    printf("Total Bill: %.2f\n", bill.total_bill);
}