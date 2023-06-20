#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

// Function to read a complex number from the user
void readComplex(struct Complex* complexPtr) {
    printf("Enter the real part: ");
    scanf("%f", &(complexPtr->real));

    printf("Enter the imaginary part: ");
    scanf("%f", &(complexPtr->imaginary));
}

// Function to write a complex number
void writeComplex(struct Complex* complexPtr) {
    printf("Complex number: %.2f + %.2fi\n", complexPtr->real, complexPtr->imaginary);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex* complex1Ptr, struct Complex* complex2Ptr) {
    struct Complex result;

    result.real = complex1Ptr->real + complex2Ptr->real;
    result.imaginary = complex1Ptr->imaginary + complex2Ptr->imaginary;

    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex* complex1Ptr, struct Complex* complex2Ptr) {
    struct Complex result;

    result.real = complex1Ptr->real * complex2Ptr->real - complex1Ptr->imaginary * complex2Ptr->imaginary;
    result.imaginary = complex1Ptr->real * complex2Ptr->imaginary + complex1Ptr->imaginary * complex2Ptr->real;

    return result;
}

int main() {
    struct Complex complex1, complex2;

    printf("Enter the first complex number:\n");
    readComplex(&complex1);

    printf("Enter the second complex number:\n");
    readComplex(&complex2);

    printf("\nEntered complex numbers:\n");
    writeComplex(&complex1);
    writeComplex(&complex2);

    struct Complex sum = addComplex(&complex1, &complex2);
    printf("\nSum of the complex numbers:\n");
    writeComplex(&sum);

    struct Complex product = multiplyComplex(&complex1, &complex2);
    printf("\nProduct of the complex numbers:\n");
    writeComplex(&product);

    return 0;
}
