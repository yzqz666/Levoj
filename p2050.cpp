#include <iostream>
using namespace std;

int main() {
    int M, V1, V2, T1, T2;
    cin >> M >> V1 >> V2 >> T1 >> T2;

    int t1 = M / V1;

    int dis = V2 * T1;
    int cycles = M / dis;
    int cnt = M % dis;
    int t2 = cycles * (T1 + T2);
    if (cnt > 0) {
        t2 += cnt / V2;
    } else {
        t2 -= T2;
    }

    if (t1 < t2) {
        cout << "1" << endl;
    } else if (t2 < t1) {
        cout << "2" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}