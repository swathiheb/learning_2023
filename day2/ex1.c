#include <stdio.h>
#include <stdint.h>

void printExponent(double num) {
    uint64_t* ptr = (uint64_t*)&num;
    uint16_t exponent = ((*ptr) >> 52) & 0x7FF;

    printf("Exponent in hexadecimal: 0x%03X\n", exponent);
    
    printf("Exponent in binary: ");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printExponent(x);

    return 0;
}
