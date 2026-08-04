#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void spinner(int seconds) {
    // These 4 characters rotate to look like a spin
    char spin_chars[] = {'|', '/', '-', '\\'};
    int total_steps = seconds * 10; // 10 steps per second

    for (int i = 0; i < total_steps; i++) {
        // % 4 loops through index 0, 1, 2, 3 continuously
        printf("\r[*] Connecting to server... %c", spin_chars[i % 4]);
        fflush(stdout);
        usleep(100000); // 100ms
    }
    printf("\r[*] Connected successfully!   \n");
}

int main() {
    system("cls");
    spinner(3); // Spins for 3 seconds
    return 0;
}