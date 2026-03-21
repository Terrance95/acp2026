#include <stdio.h>

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

    printf("Average Runs: %.2f\n", avg);

    return 0;
}

void readPlayers(int n, Player p[]) {
    // TODO: Use a loop to read player_name, jersey_number, and runs_scored
    for(int i=0;i<n;i++){
        printf("enter player %d details(name,jersey no,runs scored):\n",i+1);
        fgets(p[i].player_name,30,stdin);
        scanf("%d%d",p[i].jersey_number,p[i].runs_scored);
    }
}

float calculateAverageRuns(int n, Player p[]) {
    float average = 0;
    float total=0;
    for(int i=0;i<n;i++){
        total+=p[i].runs_scored;
    }
    average=total/n;
    // TODO: Calculate total runs using a loop
    // TODO: Compute average = total_runs / n

    return average;
}