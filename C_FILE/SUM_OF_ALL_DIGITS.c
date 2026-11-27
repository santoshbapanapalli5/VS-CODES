#include <stdio.h>

int main() {
    long long num, originalNum, digit;
    long long sum = 0;

    printf("Enter an integer: ");
    scanf("%lld", &num);

    originalNum = num; // Store original number for output

    // Handle negative numbers if the user enters one
    if (num < 0) {
        num = -num;
    }

    // Loop until all digits are processed
    while (num > 0) {
        digit = num % 10; // Extract the last digit
        sum += digit;     // Add the digit to sum
        num /= 10;        // Remove the last digit
    }

    printf("The sum of digits of %lld is %lld\n", originalNum, sum);

    return 0;
}