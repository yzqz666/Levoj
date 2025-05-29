#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

string week_days[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int main() {
    int days;
    while (cin >> days && days != -1) {
        int year = 2000, month = 1, day = 1;
        int w = 0;

        while (days > 0) {
            int days_in_year = isLeap(year) ? 366 : 365;
            if (days >= days_in_year) {
                days -= days_in_year;
                year++;
            } else {
                break;
            }
        }

        while (true) {
            int days_in_month = month_days[month - 1];
            if (month == 2 && isLeap(year)) days_in_month = 29;
            if (days >= days_in_month) {
                days -= days_in_month;
                month++;
            } else {
                break;
            }
        }

        day += days;
        int total_days = 0;

        for (int y = 2000; y < year; ++y)
            total_days += isLeap(y) ? 366 : 365;
        for (int m = 1; m < month; ++m)
            total_days += (m == 2 && isLeap(year)) ? 29 : month_days[m - 1];
        total_days += day - 1;
        int weekday = total_days % 7;

        printf("%04d-%02d-%02d %s\n", year, month, day, week_days[weekday].c_str());
    }

    return 0;
}