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
    printf("\n Loading Love System: [");
    for (int i = 0; i <= total; i++) {
        printf("\r Loading Love System: [");
        for (int j = 0; j < i; j++) printf("=");
        if (i < total) printf(">");
        for (int j = i; j < total; j++) printf(" ");
        printf("] %d%%", (i * 100) / total);
        fflush(stdout);
        usleep(30000); // Speed of loading bar (30ms per tick)
    }
    printf("\n\n");
}

// 3. Function to print the love symbol with delay
void print_heart(int speed_ms) {
    // Each string represents one row of the heart shape
    print_with_delay("      ******       ******      \n", speed_ms);
    print_with_delay("    **********   **********    \n", speed_ms);
    print_with_delay("  ************* *************  \n", speed_ms);
    print_with_delay(" ***************************** \n", speed_ms);
    print_with_delay(" ***************************** \n", speed_ms);
    print_with_delay("  ***************************  \n", speed_ms);
    print_with_delay("    ***********************    \n", speed_ms);
    print_with_delay("      *******************      \n", speed_ms);
    print_with_delay("        ***************        \n", speed_ms);
    print_with_delay("          ***********          \n", speed_ms);
    print_with_delay("            *******            \n", speed_ms);
    print_with_delay("              ***              \n", speed_ms);
    print_with_delay("               *               \n\n", speed_ms);
}

int main() {
    // Step 1: Clear the screen
    // Note: Use system("clear") instead of "cls" if you are running on Linux/macOS
    system("cls"); 

    // Step 2: Run the loading animation
    loading_bar(); 

    // Step 3: Type out the system ready text
    print_with_delay(">>> SYSTEM READY.\n", 30);
    print_with_delay(">>> INITIALIZING LOVE SYMBOL...\n\n", 30);
    
    // Step 4: Type out the heart symbol (using 10ms for a smoother draw speed)
    print_heart(10); 
    
    // Step 5: Final message
    print_with_delay("   Sent with love by Santosh! \n", 40);

    return 0;
}
