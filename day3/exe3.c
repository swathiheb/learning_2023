#include<stdio.h>


int findLargestNumber(int num) {
    int largest = 0;
    int multiplier = 1;
    
    while (num > 0) {
        int temp = (num / 10) * multiplier + (num % 10);
        
        if (temp > largest) {
            largest = temp;
        }
        
        num /= 10;
        multiplier *= 10;
    }
    
    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    
    int largestNumber = findLargestNumber(num);
    
    printf("Largest number after deleting a single digit: %d\n", largestNumber);
    
    return 0;
}
