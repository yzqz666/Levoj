#include <iostream>

void advanceOnePalworldSecond(int& h, int& m, int& s) {
    s++;

    int seconds_per_minute;
    int minutes_per_hour;

    if (h >= 0 && h <= 8) {
        seconds_per_minute = 60;
        minutes_per_hour = 60;
    } else if (h >= 9 && h <= 16) {
        seconds_per_minute = 100;
        minutes_per_hour = 100;
    } else {
        seconds_per_minute = 30;
        minutes_per_hour = 30;
    }

    if (s >= seconds_per_minute) {
        s = 0;
        m++;

        if (m >= minutes_per_hour) {
            m = 0;
            h++;

            if (h >= 24) {
                h = 0; // Reset to 00:00:00
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);                   

    int h, m, s;
    std::cin >> h >> m >> s;

    int t_total_seconds;
    std::cin >> t_total_seconds;

    for (int i = 0; i < t_total_seconds; ++i) {
        advanceOnePalworldSecond(h, m, s);
    }

    std::cout << h << " " << m << " " << s << std::endl;

    return 0;
}