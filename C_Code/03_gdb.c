#include <stdio.h>

int add(int a, int b) {
    int result = a + b;
    return result;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void print_values(int x, int y) {
    printf("The values are: x = %d, y = %d\n", x, y);
}

int main() {
    int a = 5;
    int b = 3;

    // Add two numbers
    int sum = add(a, b);
    printf("Sum of %d and %d is %d\n", a, b, sum);

    // Calculate factorial
    int num = 4;
    int fact = factorial(num);
    printf("Factorial of %d is %d\n", num, fact);

    // Print values
    print_values(a, fact);

    return 0;
}