#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Color Definitions
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"
#define YELLOW  "\033[1;33m"
#define HEADER  "\033[44;37m" // White text on Blue background
#define RESET   "\033[0m"

void print_slow(const char *text, int speed_ms) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        usleep(speed_ms * 1000);
    }
}

void show_loading() {
    int total = 20;
    printf(CYAN "\n[+] Loading Bank Database... [" RESET);
    for (int i = 0; i <= total; i++) {
        printf("\r" CYAN "[+] Loading Bank Database... [" RESET);
        for (int j = 0; j < i; j++) printf(GREEN "=" RESET);
        if (i < total) printf(GREEN ">" RESET);
        for (int j = i; j < total; j++) printf(" ");
        printf("] %d%%", (i * 100) / total);
        
        fflush(stdout);
        usleep(40000);
    }
    printf("\n\n");
}

int main() {
    int choice;

    // Step 1: Clear screen
    system("cls");

    // Step 2: Show loading bar
    show_loading();

    // Step 3: Styled Header Banner
    printf(HEADER "          =========================================          " RESET "\n");
    printf(HEADER "                  BANK OF SANTOSH TERMINAL                   " RESET "\n");
    printf(HEADER "          =========================================          " RESET "\n\n");

    // Step 4: Typewriter Menu
    print_slow(CYAN "Select an option from below:\n" RESET, 20);
    printf("1. " GREEN "Check Balance" RESET "\n");
    printf("2. " GREEN "Deposit Funds" RESET "\n");
    printf("3. " RED "Exit" RESET "\n\n");

    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    // Step 5: Process Input with Sound
    system("cls");
    if (choice == 1) {
        printf("\a"); // Beep alert
        printf(GREEN "\n[SUCCESS] Your Current Balance is: $10,000\n\n" RESET);
    } else if (choice == 2) {
        printf("\a");
        printf(YELLOW "\n[INFO] Deposit feature coming soon!\n\n" RESET);
    } else {
        printf(RED "\nExiting System... Goodbye!\n\n" RESET);
    }

    return 0;
}