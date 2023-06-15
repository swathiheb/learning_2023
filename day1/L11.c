#include <stdio.h>

int find_largest_number(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int num1 ;
    int num2 ;
    printf("Enter two numbers ");
    scanf("%d %d",&num1,&num2);
    int largest = find_largest_number(num1, num2);
    printf("The largest number is: %d\n", largest);

    return 0;
}
