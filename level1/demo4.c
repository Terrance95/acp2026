#include <stdio.h>
#include <string.h>

/* Structure Definition */
typedef struct{
    int flight_number;
    char destination[50];
    int available_seats;
}Flight;


/* Function Prototypes */
void input_flights(int n, Flight flights[n]);
int search_flights(int n, Flight flights[n], char destination[], int result[]);
void display(int count, int results[], Flight flights[]);

int main()
{
    /*n=4-Number of flights
    flight[]-Array of structures
    /*destination -User inputb for search
    /*result-stores matching flight indices
    /*count-Number of matches*/
    
    int n=4;
    Flight flights[n];
    char destination[50];
    int results[n];
    int count;
    
    /*input flight details*/
    input_flights(n,flights);
    
    /*input destination to search*/
    printf("\nEnter destination to search: ");
    scanf("%d",destination);
    
    /*Search flights*/
    count=search_flights(n,flights,destination,results);
    
    /*Display result*/
    display(count,results,flights);
    
     return 0;
}

/* Function to input flight details */
void input_flights(int n, Flight flights[n])
{
        for(int i=0;i<n;i++)
        {
        printf("\nEnter details of flight %d\n",i+1 ); //. dot operator is used to access the structure member//
        
        printf("Enter flight number: ");
        scanf("%d",&flights[i].flight_number);
        // write code

        printf("Enter destination: ");
        scanf("%d",&flights[i].destination);
        // write code

        printf("Enter available seats: ");
        scanf("%d",&flights[i].available_seats);
        // write code
    }
}

/* Function to search flights */
int search_flights(int n, Flight flights[n], char destination[], int result[])
    /*initialize count=0
    loop through all flights
    compare destination using */
    {
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(strcmp(flights[i].destination,destination)==0){
                result[count]=i;
                count++;
                /*Total number of matching flights*/
            }
        }
        return count;
    }
    
    
        // write condition using strcmp
        // store index in result[count]



/* Function to display result */
void display(int count, int results[], Flight flights[])
{
    if(count==0)
    {
       printf("No flight available to the given destination\n"); 
    }
    else
    {
            printf("Flights available:\n");
            for(int i=0;i<count;i++)
            {
                int index=results[i];
                printf("Flight Number: %d\n",flights[index].flight_number);
            }
    }

}