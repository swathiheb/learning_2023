#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time calculateTimeDifference(struct Time* startTimePtr, struct Time* endTimePtr) {
    struct Time difference;
    int startTimeInSeconds = startTimePtr->hours * 3600 + startTimePtr->minutes * 60 + startTimePtr->seconds;
    int endTimeInSeconds = endTimePtr->hours * 3600 + endTimePtr->minutes * 60 + endTimePtr->seconds;

    // Calculate the absolute difference in seconds
    int timeDifferenceInSeconds = (endTimeInSeconds > startTimeInSeconds) ? (endTimeInSeconds - startTimeInSeconds) : (startTimeInSeconds - endTimeInSeconds);

    // Convert back to hours, minutes, and seconds
    difference.hours = timeDifferenceInSeconds / 3600;
    difference.minutes = (timeDifferenceInSeconds % 3600) / 60;
    difference.seconds = (timeDifferenceInSeconds % 3600) % 60;

    return difference;
}

int main() {
    struct Time startTime, endTime;

    printf("Enter the start time:\n");
    printf("Hours: ");
    scanf("%d", &(startTime.hours));
    printf("Minutes: ");
    scanf("%d", &(startTime.minutes));
    printf("Seconds: ");
    scanf("%d", &(startTime.seconds));

    printf("Enter the end time:\n");
    printf("Hours: ");
    scanf("%d", &(endTime.hours));
    printf("Minutes: ");
    scanf("%d", &(endTime.minutes));
    printf("Seconds: ");
    scanf("%d", &(endTime.seconds));

    struct Time difference = calculateTimeDifference(&startTime, &endTime);

    printf("\nTime difference: %d hours, %d minutes, %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
