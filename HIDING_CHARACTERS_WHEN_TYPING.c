#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main()
{
    char password[20];
    char ch;
    int i = 0;

    system("cls");
#define blue "\033[1;34m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define RESET "\033[0m"
    printf(red "Enter PASSWORD: " RESET);
    while (1)
    {
        ch = getch();

        if (ch == 13)
        {
            password[i] = '\0';
            break;
        }

        password[i] = ch;
        printf("*");
        i++;
    }
    int a;

    printf(blue "\n enter 1 to show password: " RESET);
    scanf("%d", &a);
    if (a == 1)
    {

        printf(green "\n\nPassword Entered: %s\n", password, RESET);
    }

    return 0;
}