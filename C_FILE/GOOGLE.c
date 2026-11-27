#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep/usleep functions on Linux/macOS or MinGW

// Function to print text with a typewriter effect
void type_writer(const char *text, unsigned int speed_ms) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout); // Forces the character to display immediately
        usleep(speed_ms * 1000); // Wait in milliseconds
    }
}

// Function to render an animated loading bar
void progress_bar() {
    int total = 30;
    printf("\n[");
    for (int i = 0; i <= total; i++) {
        printf("\r[");
        for (int j = 0; j < i; j++) printf("=");
        if (i < total) printf(">");
        for (int j = i; j < total; j++) printf(" ");
        printf("] %d%%", (i * 100) / total);
        
        fflush(stdout);
        usleep(80000); // Speed of loading bar
    }
    printf("\n\n");
}

int main() {
    // Clear screen trick
    system("cls || clear");

    // Message animation
    type_writer(">>> INITIALIZING NEURAL LINK...\n", 40);
    type_writer(">>> ACCESSING IIITDM JABALPUR MAIN FRAME...\n", 40);
    
    // Progress bar animation
    progress_bar();

    type_writer(">>> ACCESS GRANTED! Welcome, Agent Santosh.\n\n", 50);

    return 0;
}