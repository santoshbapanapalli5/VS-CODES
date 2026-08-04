#include <stdio.h>
#include <stdlib.h>

// Color Definitions
#define RED "\033[1;34m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m" // Resets text back to default white

int main() {
    system("cls");

    printf(GREEN " [SUCCESS] File saved successfully!\n" RESET);
    printf(YELLOW " [WARNING] Battery level low.\n" RESET);
    printf(RED " [ERROR] Access Denied!\n" RESET);

    return 0;
}