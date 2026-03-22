#include <stdio.h>
#include <string.h>

typedef struct {
    char player_name[30];
    int jersey_number;
    int runs_scored;
} Player;

void readPlayers(int n, Player p[]);
float calculateAverageRuns(int n, Player p[]);

int main() {
    Player p[11];
    float avg;

    readPlayers(11, p);
    avg = calculateAverageRuns(11, p);

    printf("\n---- Match Statistics ----\n");
    printf("Average Runs of the Team: %.2f\n", avg);

    return 0;
}

void readPlayers(int n, Player p[]) {
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for Player %d:\n", i + 1);
        
        printf("Name: ");
        getchar(); 
        fgets(p[i].player_name, 30, stdin);
        
        p[i].player_name[strcspn(p[i].player_name, "\n")] = 0;

        printf("Jersey Number: ");
        scanf("%d", &p[i].jersey_number); 

        printf("Runs Scored: ");
        scanf("%d", &p[i].runs_scored);  
    }
}

float calculateAverageRuns(int n, Player p[]) {
    float total = 0;
    for(int i = 0; i < n; i++) {
        total += p[i].runs_scored;
    }
    return (n > 0) ? (total / n) : 0;
}