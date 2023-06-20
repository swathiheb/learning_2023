#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

// Function to swap the fields of two Person structures
void swapFields(struct Person* person1Ptr, struct Person* person2Ptr) {
    // Swap name
    char tempName[50];
    strcpy(tempName, person1Ptr->name);
    strcpy(person1Ptr->name, person2Ptr->name);
    strcpy(person2Ptr->name, tempName);

    // Swap age
    int tempAge = person1Ptr->age;
    person1Ptr->age = person2Ptr->age;
    person2Ptr->age = tempAge;
}

int main() {
    struct Person person1, person2;

    // Initialize person1
    strcpy(person1.name, "John");
    person1.age = 25;

    // Initialize person2
    strcpy(person2.name, "Alice");
    person2.age = 30;

    printf("Before swapping:\n");
    printf("Person 1:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("\n");
    printf("Person 2:\n");
    printf("Name: %s\n", person2.name);
    printf("Age: %d\n", person2.age);
    printf("\n");

    // Swap the fields using pointers
    swapFields(&person1, &person2);

    printf("After swapping:\n");
    printf("Person 1:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("\n");
    printf("Person 2:\n");
    printf("Name: %s\n", person2.name);
    printf("Age: %d\n", person2.age);
    printf("\n");

    return 0;
}

