#include <stdio.h>
#include <ctype.h>  // Required for tolower() and toupper()
void make_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}
void make_lowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}
int main() {
    char text[100];
    gets(text);
    make_uppercase(text);
    printf("Upper: %s\n", text); // Output: LEARN C PROGRAMMING!

    make_lowercase(text);
    printf("Lower: %s\n", text); // Output: learn c programming!

    return 0;
}
