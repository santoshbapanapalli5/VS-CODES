#include <stdio.h>

int main() {
    int day, month, year;

    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int h = (day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;

    if (h == 0) printf("It is Saturday\n");
    else if (h == 1) printf("It is Sunday\n");
    else if (h == 2) printf("It is Monday\n");
    else if (h == 3) printf("It is Tuesday\n");
    else if (h == 4) printf("It is Wednesday\n");
    else if (h == 5) printf("It is Thursday\n");
    else if (h == 6) printf("It is Friday\n");

    return 0;
}