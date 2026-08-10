#include <stdio.h>
#include <stdlib.h>
#include <stdalign.h>

_Static_assert(sizeof(int) == 4, "Expected 32-bit int");

int factorial(int n) {
    if (n < 0) {
        fprintf(stderr, "Error: Negative input\n");
        exit(EXIT_FAILURE);
    }
auto result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Invalid input\n");
        return EXIT_FAILURE;
    }
    printf("Factorial of %d is %d\n", num, factorial(num));
    return EXIT_SUCCESS;
}