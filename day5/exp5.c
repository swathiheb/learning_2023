#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudents(const struct Student students[], int numStudents, const char* searchName) {
    int found = 0;

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Student found!\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);

            found = 1;
        }
    }

    if (!found) {
        printf("Student not found.\n");
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

    const char* searchName = "Bob";

    // Perform search operation based on the name of the student
    searchStudents(students, numStudents, searchName);

    return 0;
}
