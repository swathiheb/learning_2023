#include <stdio.h>

#define MAX_STUDENTS 10

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortStudents(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap the students
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

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

    // Sort the array of structures based on marks in descending order
    sortStudents(students, numStudents);

    // Display all members of the sorted array
    displayStudents(students, numStudents);

    return 0;
}
