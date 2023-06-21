#include <stdio.h>

#define MAX_STUDENTS 10

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(const struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}

int main() {
    struct Student students[MAX_STUDENTS] = {
        {1001, "Aron", 100.00},
        {1002, "Bob", 90.50},
        {1003, "Charlie", 85.75},
        // Add more students here if desired
    };
    int numStudents = 3;

    // Display all members of the array of structures
    displayStudents(students, numStudents);

    return 0;
}
