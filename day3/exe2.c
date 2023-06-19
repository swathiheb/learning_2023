#include <stdio.h>

void print_bits(unsigned int num) {
    int i;
    unsigned int mask = 1 << 31;  // Start with the leftmost bit

    for (i = 0; i < 32; i++) {
        // Print the current bit (0 or 1)
        printf("%d", (num & mask) ? 1 : 0);
        
        // Shift the mask to the right by one bit
        mask >>= 1;
    }
    
    printf("\n");
}

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);
    
    printf("Bits: ");
    print_bits(num);
    
    return 0;
}
