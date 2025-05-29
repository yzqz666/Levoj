#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ull;

int main() {
    ull x, y, s;
    cin >> x >> y >> s;

    string result;
    while (true) {
        ull z;
        if ((x + y) % 2 == 0)
            z = (x + y) / 2;
        else
            z = (x + y - 1) / 2;

        if (s < z) {
            result += 'L';
            y = z - 1;
        } else if (s > z) {
            result += 'R';
            x = z + 1;
        } else {
            result += 'G';
            break;
        }
    }

    cout << result << endl;
    return 0;
}