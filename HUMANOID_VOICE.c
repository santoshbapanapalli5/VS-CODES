#include <stdio.h>
#include <stdlib.h>
void speak(const char *message) {
    char command[300];
    sprintf(command, "powershell -c \"Add-Type -A System.Speech; (New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak('%s')\"", message);
    system(command);
}
int main() {
    printf("Talking...\n");

    speak("Hello! Welcome to IIIT Jabalpur.");
    
    speak("Your code is working perfectly.");

    printf("Done!\n");
    return 0;
}