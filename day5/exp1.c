#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student students[], int* numStudents) {
    char temp[100];
    int i = 0;

    while (sscanf(input, "%d %[A-Za-z] %[0-9.]%*c", &students[i].rollno, temp, temp) == 3) {
        strcpy(students[i].name, temp);
        students[i].marks = atof(temp);

        input = strchr(input, ' ') + 1;
        i++;
    }

    *numStudents = i;
}

int main() {
    const char* input = "1001 Aron 100.00";
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    parseString(input, students, &numStudents);

    printf("Parsed Students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}
