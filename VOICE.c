#include <stdio.h>
#include <stdlib.h>
void speak(const char *message) {
    char command[300];
    sprintf(command, "powershell -c \"Add-Type -A System.Speech; (New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak('%s')\"", message);
    system(command);
}
int main() {
    printf("Talking...\n");
    speak("Hello! Welcome to my program");

    int a;
    speak("give a number");
    scanf("%d", &a);
    char response[100];
    sprintf(response, "you selected %d",a);
    speak(response);
    speak("give another number");
    int b;
    scanf("%d", &b);
    sprintf(response, "in this time you given %d",b);
    speak(response);
    speak("Your code is working perfectly.");
    printf("Done!\n");
    return 0;
}