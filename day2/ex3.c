#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            sum += arr[i];
        }
    }

    printf("Sum of alternate elements: %d\n", sum);

    return 0;
}

