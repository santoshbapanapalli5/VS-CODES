#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD prev_mode;
    GetConsoleMode(hInput, &prev_mode);
    
    // Enable mouse input mode in terminal
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

    printf("\033[H\033[2J");
    printf("\033[1;33m=== MOUSE CLICK DETECTOR ===\033[0m\n");
    printf("Click anywhere inside this terminal window! Press Ctrl+C to exit.\n\n");

    INPUT_RECORD inRec;
    DWORD numRead;

    while (1) {
        ReadConsoleInput(hInput, &inRec, 1, &numRead);

        if (inRec.EventType == MOUSE_EVENT) {
            MOUSE_EVENT_RECORD mouse = inRec.Event.MouseEvent;
            
            // Detect left click press
            if (mouse.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                printf("Left Click Detected at Column: \033[1;32m%2d\033[0m | Row: \033[1;32m%2d\033[0m\n", 
                       mouse.dwMousePosition.X, mouse.dwMousePosition.Y);
            }
        }
    }

    // Restore original terminal mode
    SetConsoleMode(hInput, prev_mode);
    return 0;
}