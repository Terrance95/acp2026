#include <stdio.h>

void inputTemperatures(int n, float temps[n]);
float findHighest(int n, float temps[n]);
float findLowest(int n, float temps[n]);
void output(float max, float min);

int main() {
    int n;
    float max, min;
    printf("enter no of temperatures u want to enter:");
    scanf("%d",&n);
    if(n<=0){
        printf("invalid value for n entered:");
        return 0;
    }
    float temps[n];
    // Call function to input 7 temperatures
    inputTemperatures(n,temps);
    // Call function to find highest temperature
    max=findHighest(n,temps);
    // Call function to find lowest temperature
    min=findHighest(n,temps);
    // Call function to display results
    output(max,min);

    return 0;
}

void inputTemperatures(int n, float temps[n]) {
    printf("Enter temperatures:\n");
    for(int i=0;i<n;i++){
        scanf("%f",&temps[i]);
    }
    // Write code to read temperatures
}

float findHighest(int n, float temps[n]) {
    // Write code to find highest temperature
    float max=0;
    for(int i=0;i<n;i++){
        if(temps[i]>max){
            max=temps[i];
        }
    }
    return max;

}

float findLowest(int n, float temps[n]) {
    // Write code to find lowest temperature
    float min=temps[0];
    for(int i=0;i<n;i++){
        if(temps[i]<min){
            min=temps[i];
        }
    }
    return min;

}

void output(float max, float min) {
    printf("Highest temperature: %.2f\n", max);
    printf("Lowest temperature: %.2f\n", min);
    // Write code to display results
}