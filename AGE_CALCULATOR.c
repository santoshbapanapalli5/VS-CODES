#include <stdio.h>

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

long long countTotalDays(int day, int month, int year) {
    long long totalDays = (long long)(year - 1) * 365;
    totalDays += (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

    for (int i = 0; i < month - 1; i++) {
        totalDays += monthDays[i];
    }

    if (month > 2 && isLeapYear(year)) {
        totalDays++;
    }

    totalDays += day;
    return totalDays;
}

int main() {
    int d1, m1, y1;
    int d2, m2, y2;
    long int finalDifference;

    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &d1, &m1, &y1);

    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &d2, &m2, &y2);

    long long totalDays1 = countTotalDays(d1, m1, y1);
    long long totalDays2 = countTotalDays(d2, m2, y2);

    if (totalDays1 > totalDays2) {
        finalDifference = totalDays1 - totalDays2;
    } else {
        finalDifference = totalDays2 - totalDays1;
    }

    printf("\nNumber of days: %ld days\n", finalDifference);

    long int b = finalDifference / 7;
    long int c = finalDifference % 7;
    long int d = finalDifference * 24;
    long int e = d * 60;
    long int f = e * 60;

    int g = (y2 - y1) * 12 + (m2 - m1);
    if (d2 < d1) {
        g--;
    }

    printf("no.of weeks: %ld days: %ld\n", b, c);
    printf("no.of hours: %ld\n", d);
    printf("no.of minutes: %ld\n", e);
    printf("no.of seconds: %ld\n", f);
    printf("no of months: %d\n", g);

    return 0;
}