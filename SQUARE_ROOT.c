#include <stdio.h>

int main() {
    double number;
    double guess, prev_guess;
    printf("Enter a positive number: ");
    scanf("%lf", &number);
    if (number < 0) {
        printf("Error: Cannot calculate the square root of a negative number.\n");
        return 1; 
    }
    guess = number / 2.0;
    prev_guess = 0.0;

    while (guess != prev_guess) {
        prev_guess = guess;
        guess = (number / prev_guess + prev_guess) / 2.0;
    }
    printf("The square root of %.2lf is approximately %.5lf\n", number, guess);

    return 0;
}
