#include <stdio.h>
#include <stdlib.h> // Needed for system("cls")
#include <unistd.h> // Needed for usleep()

// 1. Function for typewriter typing
void print_with_delay(const char *text, int speed_ms) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        usleep(speed_ms * 1000);
    }
}

// 2. Function for loading progress bar
void loading_bar() {
    int total = 30;
    printf("\n Loading System: [");
    for (int i = 0; i <= total; i++) {
        printf("\r Loading System: [");
        for (int j = 0; j < i; j++) printf("=");
        if (i < total) printf(">");
        for (int j = i; j < total; j++) printf(" ");
        printf("] %d%%", (i * 100) / total);
        
        fflush(stdout);
        usleep(50000); // Speed of loading bar (50ms per tick)
    }
    printf("\n\n");
}

int main() {
    // Step 1: Wipe all the terminal clutter
    system("cls");

    // Step 2: Run the loading animation
    loading_bar();

    // Step 3: Run your actual program content
    print_with_delay(">>> SYSTEM READY.\n", 30);
    print_with_delay("Hi I am Santosh!\n", 30);

    return 0;
}