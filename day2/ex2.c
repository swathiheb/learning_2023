#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char* temp = (char*)malloc(size);
     memcpy(temp, a, size);
     memcpy(a, b, size);
     memcpy(b, temp, size);
     free(temp);
}

int main() {
    int num1 = 10;
    int num2 = 20;
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);

    swap(&num1, &num2, sizeof(int));
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    char ch1 = 'A';
    char ch2 = 'B';
    printf("Before swap: ch1 = %c, ch2 = %c\n", ch1, ch2);

    swap(&ch1, &ch2, sizeof(char));
    printf("After swap: ch1 = %c, ch2 = %c\n", ch1, ch2);

    float float1 = 3.14;
    float float2 = 2.718;
    printf("Before swap: float1 = %f, float2 = %f\n", float1, float2);

    swap(&float1, &float2, sizeof(float));
    printf("After swap: float1 = %f, float2 = %f\n", float1, float2);

    return 0;
}
