#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Required for Beep() on Windows

int main() {
    system("cls");

    printf("Processing...\n");
    Sleep(1000); // Sleep() in windows.h takes milliseconds (1000ms = 1s)

    // Plays a 1000Hz beep for 300 milliseconds
    Beep(1000, 4000); 

    printf("SUCCESS!\n");

    return 0;
}