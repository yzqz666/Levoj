#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double maxFlightTime(int n, vector<int>& batteries) {
    long long total = 0;
    int maxBattery = 0;

    for (int b : batteries) {
        total += b;
        maxBattery = max(maxBattery, b);
    }

    double res = min(total / 2.0, (double)(total - maxBattery));

    // 保留一位小数，只可能是整数或 .5
    return ((int)(res * 2 + 0.1)) / 2.0;
}

int main() {
    int n;
    cin >> n;
     {
        vector<int> batteries(n);
        for (int i = 0; i < n; ++i) {
            cin >> batteries[i];
        }

        double result = maxFlightTime(n, batteries);
        cout << fixed << setprecision(1) << result << endl;
    }

    return 0;
}