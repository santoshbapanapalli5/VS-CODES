#include <stdio.h>
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int getDaysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}
long long countLeapYears(int year, int month) {
    if (month <= 2) {
        year--;
    }
    return (year / 4) - (year / 100) + (year / 400);
}
long long getTotalDaysFromEpoch(int d, int m, int y) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long long total = (long long)y * 365 + d;
    
    for (int i = 0; i < m - 1; i++) {
        total += days[i];
    }
    total += countLeapYears(y, m);
    return total;
}

void calculateDetailedAge(int d1, int m1, int y1, int d2, int m2, int y2) {
    int target_d = d2;
    int target_m = m2;
    int target_y = y2;

    if (target_d < d1) {
        target_m -= 1;
        int prev_month = (target_m == 0) ? 12 : target_m;
        int prev_year = (target_m == 0) ? target_y - 1 : target_y;
        target_d += getDaysInMonth(prev_month, prev_year);
    }

    if (target_m < m1) {
        target_y -= 1;
        target_m += 12;
    }

    int years = target_y - y1;
    int months = target_m - m1;
    int days = target_d - d1;

    long long total_days = getTotalDaysFromEpoch(d2, m2, y2) - getTotalDaysFromEpoch(d1, m1, y1);
    long long total_months = (long long)years * 12 + months;
    long long total_weeks = total_days / 7;
    int remaining_days = total_days % 7;
    long long total_hours = total_days * 24;
    long long total_minutes = total_hours * 60;
    long long total_seconds = total_minutes * 60;

    printf("\n================ AGE OUTPUT ================\n");
    printf("Age:          %d years %d months %d days\n", years, months, days);
    printf("--------------------------------------------\n");
    printf("Total Months : %lld months (and %d days)\n", total_months, days);
    printf("Total Weeks  : %lld weeks (and %d days)\n", total_weeks, remaining_days);
    printf("Total Days   : %lld days\n", total_days);
    printf("Total Hours  : %lld hours\n", total_hours);
    printf("Total Mins   : %lld minutes\n", total_minutes);
    printf("Total Secs   : %lld seconds\n", total_seconds);
    printf("============================================\n");
}

int main() {
    int d1, m1, y1;
    int d2, m2, y2;
    printf("Enter start/birth date (DD MM YYYY): ");
    scanf("%d %d %d", &d1, &m1, &y1);

    printf("Enter end/target date (DD MM YYYY): ");
    scanf("%d %d %d", &d2, &m2, &y2);

    calculateDetailedAge(d1, m1, y1, d2, m2, y2);

    return 0;
}