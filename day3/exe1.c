#include <stdio.h>

void print_numbers(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d", i);
    }
    for (i = n; i >= 1; i--) {
        printf("%d", i);
    }
   printf("\n");
}

void print_spaces(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("");
    }
}

void print_pattern(int n) {
    int i;
    for (i = n; i >= 1; i--) {
       
        if (i > 1) {
            print_spaces(i-1);
            print_numbers(i-1);
        }
    }
}

int main() {
    int n = 5;
    print_pattern(n);
    return 0;
}
