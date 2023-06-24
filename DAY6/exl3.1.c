#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
} LogEntry;

void readCSV(const char *filename, LogEntry entries[], int *numEntries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];

    // Skip the header line
    fgets(line, MAX_LINE_LENGTH, file);

    *numEntries = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && *numEntries < MAX_ENTRIES) {
        // Extract data from each line
        char *token = strtok(line, ",");
        entries[*numEntries].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strncpy(entries[*numEntries].sensorNo, token, sizeof(entries[*numEntries].sensorNo));

        token = strtok(NULL, ",");
        entries[*numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        entries[*numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        entries[*numEntries].light = atoi(token);

        token = strtok(NULL, ",");
        strncpy(entries[*numEntries].timestamp, token, sizeof(entries[*numEntries].timestamp));

        (*numEntries)++;
    }

    fclose(file);
}

void printEntries(const LogEntry entries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n",
               entries[i].entryNo,
               entries[i].sensorNo,
               entries[i].temperature,
               entries[i].humidity,
               entries[i].light,
               entries[i].timestamp);
    }
}

int main() {
    LogEntry entries[MAX_ENTRIES];
    int numEntries;

    readCSV("data.csv", entries, &numEntries);
    printEntries(entries, numEntries);

    return 0;
}
