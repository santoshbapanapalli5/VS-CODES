#include <stdio.h>

int main() {
    int n;

    // Ask user for the exact number of terms
    printf("Enter number of terms: ");
    scanf("%d", &n);

    // Create an array named 'a' with the size the user wants
    int a[n];

    // Set the starting 3 positions using correct array brackets
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;

    // Print the first 3 numbers
    printf("%d, %d, %d", a[0], a[1], a[2]);

    // Loop runs exactly up to the limit, printing 1 term per turn
    for (int i = 3; i < n; i++) {
        // Add the last 3 positions in the array
        a[i] = a[i-1] + a[i-2] + a[i-3]; 
        printf(", %d", a[i]);
    }

    printf("\n");
    return 0;
}