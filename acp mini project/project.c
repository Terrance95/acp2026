#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define NUM_STATIONS 37
#define BASE_FARE 10.0
#define FARE_PER_STATION 2.0

// Station Map Structure defining clean output vs simple search input keys
typedef struct {
    const char* display; 
    const char* key;     
} Station;

// Clean, user-forgiving Bangalore Purple Line Database
const Station STATIONS[NUM_STATIONS] = {
    {"Whitefield (Kadugodi)", "whitefield"},
    {"Channasandra (Hopefarm)", "channasandra"},
    {"Kadugodi Industrial Area", "kadugodi"},
    {"Pattandur Agrahara", "pattandur"},
    {"Sri Sathya Sai Hospital", "sathya sai"},
    {"Kundalahalli", "kundalahalli"},
    {"Seetharam Palya", "seetharam"},
    {"Hoodi", "hoodi"},
    {"Garudacharapalya", "garudacharapalya"},
    {"Singayyanapalya", "singayyanapalya"},
    {"K.R. Pura (Krishnarajapuram)", "kr pura"},
    {"Benniganahalli", "benniganahalli"},
    {"Baiyappanahalli", "baiyappanahalli"},
    {"Swami Vivekananda Road", "sv road"},
    {"Indiranagar", "indiranagar"},
    {"Halasuru", "halasuru"},
    {"Trinity", "trinity"},
    {"Mahatma Gandhi Road (MG Road)", "mg road"},
    {"Cubbon Park", "cubbon park"},
    {"Dr. B.R. Ambedkar Station (Vidhana Soudha)", "vidhana soudha"},
    {"Sir M. Visvesvaraya Station (Central College)", "central college"},
    {"Nadaprabhu Kempegowda Station (Majestic)", "majestic"},
    {"KSR Bengaluru City Railway Station", "railway station"},
    {"Magadi Road", "magadi road"},
    {"Sri Balagangadharanatha Swamiji Station (Hosahalli)", "hosahalli"},
    {"Vijayanagar", "vijayanagar"},
    {"Govindaraja Nagar", "govindaraja nagar"},
    {"Attiguppe", "attiguppe"},
    {"Deepanjali Nagar", "deepanjali nagar"},
    {"Mysuru Road", "mysuru road"},
    {"Pantharapalya (Nayandahalli)", "nayandahalli"},
    {"Rajarajeshwari Nagar", "rr nagar"},
    {"Jnanabharathi", "jnanabharathi"},
    {"Pattanagere", "pattanagere"},
    {"Kengeri Bus Terminal", "kengeri ttmc"},
    {"Kengeri", "kengeri"},
    {"Challaghatta", "challaghatta"}
};

// AI Predictive Engine Structure
typedef struct {
    float crowdDensity;       
    int predictedTravelTime;  
    char recommendations[100];
} AIPrediction;

// Master Ticket structure layout
typedef struct {
    char name[50];
    int age;
    char source[60];
    char destination[60];
    int ticketID;
    int stopsCount;
    float totalFare;
    char timestamp[30];
    AIPrediction aiReport; // Nested AI statistics
} Ticket;

// Helper function to force string processing into absolute lowercase
void convertToLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Pure C Predictive AI Heuristic Model
AIPrediction runCommuteAI(int currentHour, int isWeekend, int totalStops) {
    AIPrediction modelOutput;
    float baseTimePerStation = 2.0; 
    float congestionMultiplier = 1.0;

    int isMorningPeak = (currentHour >= 8 && currentHour <= 11);
    int isEveningPeak = (currentHour >= 17 && currentHour <= 20);

    if (!isWeekend) {
        if (isMorningPeak || isEveningPeak) {
            modelOutput.crowdDensity = 88.5; 
            congestionMultiplier = 1.5;     
            strcpy(modelOutput.recommendations, "CRITICAL CROWD: High boarding delay. Shift travel if possible.");
        } else {
            modelOutput.crowdDensity = 42.0; 
            congestionMultiplier = 1.1;
            strcpy(modelOutput.recommendations, "MODERATE CROWD: Normal boarding tempos expected.");
        }
    } else {
        if (currentHour >= 12 && currentHour <= 19) {
            modelOutput.crowdDensity = 65.0; 
            congestionMultiplier = 1.25;
            strcpy(modelOutput.recommendations, "LEISURE PEAK: High seating occupancy across central zones.");
        } else {
            modelOutput.crowdDensity = 18.5; 
            congestionMultiplier = 0.95;    
            strcpy(modelOutput.recommendations, "OPTIMAL WINDOW: Fast transit speeds predicted.");
        }
    }

    modelOutput.predictedTravelTime = (int)((totalStops * baseTimePerStation) * congestionMultiplier);
    return modelOutput;
}

// Function Prototypes
void displayBanner();
void showStations();
int getStationIndex(char* input);
void simulateRoutingEngine();
void generateTicketFile(Ticket t);
void displayTicketOnTerminal(Ticket t);
void clearInputBuffer();

int main() {
    int choice;
    Ticket currentTicket;
    char srcInput[60], destInput[60];
    int srcIdx, destIdx;
    int inputHour, inputDayType;

    srand(time(NULL));

    while (1) {
        displayBanner();
        printf("  [1] View Purple Line Network Map & Shortcuts\n");
        printf("  [2] Open AI-Powered Ticketing Terminal\n");
        printf("  [3] Secure System Shutdown\n");
        printf("  ---------------------------------------------------------\n");
        printf("  Enter your selection: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n  [!] Invalid parameter type. Refreshing core interface.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                showStations();
                printf("\n  Press Enter to return to main dashboard...");
                getchar();
                break;

            case 2:
                showStations();
                printf("\n  --- PASSENGER BIO-REGISTRATION ---\n");
                printf("  Enter Passenger Name: ");
                fgets(currentTicket.name, sizeof(currentTicket.name), stdin);
                currentTicket.name[strcspn(currentTicket.name, "\n")] = 0; 

                printf("  Enter Passenger Age: ");
                if (scanf("%d", &currentTicket.age) != 1) {
                    printf("\n  ❌ Invalid Age. Aborting.\n");
                    clearInputBuffer();
                    getchar();
                    break;
                }
                clearInputBuffer();

                printf("\n  --- TRAVEL ENVIRONMENT INPUTS FOR PREDICTIVE AI ---\n");
                printf("  Enter current hour of travel (0-23 format): ");
                scanf("%d", &inputHour);
                if (inputHour < 0 || inputHour > 23) inputHour = 12; // Fallback default safely

                printf("  Select Day Type -> [0] Weekday / [1] Weekend: ");
                scanf("%d", &inputDayType);
                clearInputBuffer();

                printf("\n  --- TRAVEL LOGISTICS CONTROLS ---\n");
                printf("  Enter Boarding Point (e.g. 'kr pura', 'whitefield', or 1-37): ");
                fgets(srcInput, sizeof(srcInput), stdin);
                srcInput[strcspn(srcInput, "\n")] = 0;

                printf("  Enter Destination  (e.g. 'majestic', 'mg road', or 1-37): ");
                fgets(destInput, sizeof(destInput), stdin);
                destInput[strcspn(destInput, "\n")] = 0;

                srcIdx = getStationIndex(srcInput);
                destIdx = getStationIndex(destInput);

                if (srcIdx == -1 || destIdx == -1) {
                    printf("\n  ❌ ERROR: Verification failed. Station context unrecognized.\n");
                    printf("  Press Enter to return to system menu...");
                    getchar();
                    break;
                }

                if (srcIdx == destIdx) {
                    printf("\n  ⚠ NOTICE: Spatial mismatch. Source and Target match.\n");
                    printf("  Press Enter to return to dashboard...");
                    getchar();
                    break;
                }

                // Hydrate structures
                strcpy(currentTicket.source, STATIONS[srcIdx].display);
                strcpy(currentTicket.destination, STATIONS[destIdx].display);
                currentTicket.stopsCount = abs(destIdx - srcIdx);
                currentTicket.totalFare = BASE_FARE + (currentTicket.stopsCount * FARE_PER_STATION);
                currentTicket.ticketID = (rand() % 90000) + 10000; 

                if (currentTicket.age >= 60) {
                    currentTicket.totalFare *= 0.70; 
                }

                // Inject Predictive AI Model Computation Processing Pipeline
                currentTicket.aiReport = runCommuteAI(inputHour, inputDayType, currentTicket.stopsCount);

                time_t rawTime = time(NULL);
                struct tm *timeInfo = localtime(&rawTime);
                strftime(currentTicket.timestamp, sizeof(currentTicket.timestamp), "%Y-%m-%d %H:%M:%S", timeInfo);

                simulateRoutingEngine();

                // Display outputs
                displayTicketOnTerminal(currentTicket);
                generateTicketFile(currentTicket);

                printf("\n  Press Enter to finalize transaction and loop back...");
                getchar();
                break;

            case 3:
                printf("\n  [+] Releasing system memory allocation pointers... Closed cleanly.\n");
                exit(0);

            default:
                printf("\n  [!] Selection out of bounds. Select 1, 2, or 3.\n");
                printf("  Press Enter to continue...");
                getchar();
        }
    }
    return 0;
}

void displayBanner() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    printf("=================================================================\n");
    printf("     NAMMA METRO SMART ROUTER & PREDICTIVE AI SYSTEMS CORE      \n");
    printf("=================================================================\n\n");
}

void showStations() {
    printf("\n  ===================== OPERATIONAL NETWORKS & SHORTCUT KEYS =====================\n");
    int half = (NUM_STATIONS + 1) / 2;
    for (int i = 0; i < half; i++) {
        printf("  [%2d] %-26s -> '%s'", i + 1, STATIONS[i].display, STATIONS[i].key);
        if (i + half < NUM_STATIONS) {
            printf("   [%2d] %-26s -> '%s'\n", i + half + 1, STATIONS[i + half].display, STATIONS[i + half].key);
        } else {
            printf("\n");
        }
    }
    printf("  ================================================================================\n");
    printf("  💡 SHORTCUT MODE: You can type numbers (1-37) or simplified keywords like 'kr pura'!\n");
}

int getStationIndex(char* input) {
    int isNumeric = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit((unsigned char)input[i])) {
            isNumeric = 0;
            break;
        }
    }

    if (isNumeric && strlen(input) > 0) {
        int stationNum = atoi(input);
        if (stationNum >= 1 && stationNum <= NUM_STATIONS) {
            return stationNum - 1; 
        }
    }

    convertToLowerCase(input);
    for (int i = 0; i < NUM_STATIONS; i++) {
        if (strcmp(STATIONS[i].key, input) == 0) {
            return i;
        }
    }
    return -1; 
}

void simulateRoutingEngine() {
    printf("\n  [+] Querying Heuristic Weights Matrix...\n");
    printf("  [Progress]: ");
    for (int i = 0; i < 25; i++) {
        printf("■");
        fflush(stdout);
        for (volatile int d = 0; d < 8000000; d++); 
    }
    printf(" 100%% AI Optimized.\n\n");
}

void displayTicketOnTerminal(Ticket t) {
    printf("  +-------------------------------------------------------------+\n");
    printf("  |             BMRCL NAMMA METRO SMART BOARDING PASS           |\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("    TICKET REF ID  : #%d\n", t.ticketID);
    printf("    TIMESTAMP      : %s\n", t.timestamp);
    printf("    PASSENGER NAME : %s (%d Years Old)\n", t.name, t.age);
    printf("    BOARDING ZONE  : %s\n", t.source);
    printf("    ALIGHTING ZONE : %s\n", t.destination);
    printf("    TOTAL STATIONS : %d Station Clusters Traversed\n", t.stopsCount);
    printf("    FARE AMOUNT    : INR %.2f\n", t.totalFare);
    printf("  +-------------------------------------------------------------+\n");
    printf("  |             🤖 LIVE AI COMMUTE ANALYTICS REPORT             |\n");
    printf("  +-------------------------------------------------------------+\n");
    printf("    PREDICTED CROWD DENSITY : %.1f%%\n", t.aiReport.crowdDensity);
    printf("    ESTIMATED TRAVEL TIME   : %d Minutes (AI Congestion Adjusted)\n", t.aiReport.predictedTravelTime);
    printf("    AI RECOMMENDATION       : %s\n", t.aiReport.recommendations);
    printf("  +-------------------------------------------------------------+\n");
}

void generateTicketFile(Ticket t) {
    char filename[50];
    sprintf(filename, "namma_metro_ticket_%d.txt", t.ticketID);

    FILE *file = fopen(filename, "w");
    if (file == NULL) return;

    fprintf(file, "=========================================================\n");
    fprintf(file, "         NAMMA METRO ELECTRONIC TRANSACTION SLIP         \n");
    fprintf(file, "=========================================================\n");
    fprintf(file, " Transaction ID : #%d\n", t.ticketID);
    fprintf(file, " Generated Time : %s\n", t.timestamp);
    fprintf(file, " Passenger Name : %s\n", t.name);
    fprintf(file, " From Station   : %s\n", t.source);
    fprintf(file, " To Station     : %s\n", t.destination);
    fprintf(file, " Transit Vector : %d Stations Crossed\n", t.stopsCount);
    fprintf(file, " Total Net Cost : INR %.2f\n", t.totalFare);
    fprintf(file, "---------------------------------------------------------\n");
    fprintf(file, " 🤖 EMBEDDED AI SYSTEM PASSENGER FORECAST REPORT:\n");
    fprintf(file, " Projected Crowd Volume : %.1f%%\n", t.aiReport.crowdDensity);
    fprintf(file, " Calculated Duration   : %d Mins\n", t.aiReport.predictedTravelTime);
    fprintf(file, " AI Advice System       : %s\n", t.aiReport.recommendations);
    fprintf(file, "=========================================================\n");

    fclose(file);
    printf("\n  [✔] Success: Ticket and AI metadata written to: '%s'\n", filename);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}