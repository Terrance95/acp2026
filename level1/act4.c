#include <stdio.h>

typedef struct {
    int consumerID;
    float unitsConsumed;
    float billAmount;
} Bill;

void input(int n, Bill bills[n]);
void calculate_Bills(int n, Bill bills[n]);
int findHighestBillIndex(int n, Bill bills[n]);
void displayHighestBill(int index, Bill bills[]);

int main() {

    int n;
    Bill bills[100];
    int index;

    printf("Enter number of consumers:\n");
    scanf("%d",&n);

    // Call function to input consumer details
    input(n,bills);
    // Call function to calculate electricity bills
    calculate_Bills(n,bills);
    // Call function to find index of highest bill
    index=findHighestBillIndex(n,bills);
    // Call function to display highest bill
    displayHighestBill(index,bills);

    return 0;
}

void input(int n, Bill bills[n]) {
    printf("Enter consumer details(ID,units consumed):\n");
    // Write code to read consumerID and unitsConsumed
    for(int i=0;i<n;i++){
        printf("comsumer %d:",i+1);
        scanf("%d %f",&bills[i].consumerID,&bills[i].unitsConsumed);
    }
}

void calculate_Bills(int n, Bill bills[n]) {
    // Write code to calculate billAmount
    for(int i=0;i<n;i++){
        bills[i].billAmount=bills[i].unitsConsumed*3.5;
    }
}

int findHighestBillIndex(int n, Bill bills[n]) {
    // Write code to find index of highest bill
    int index=0;
    for(int i=1;i<n;i++){
        if(bills[index].billAmount>bills[i].billAmount){
            index=i;
        }
    }
    return index;
}

void displayHighestBill(int index, Bill bills[]) {
    printf("Consumer with highest bill:\n");
    printf("consumer id:%d\n",bills[index].consumerID);
    printf("bill amount:%f",bills[index].billAmount);
    // Write code to display consumer details
}