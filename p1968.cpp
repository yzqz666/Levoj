#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> queue;
    int i = 1;

    while (n--) {
        int op;
        cin >> op;

        if (op == 1) {
            i++; 
        } else if (op == 2) {
            int x;
            cin >> x;
            queue.insert(queue.begin() + i - 1, x);
        } else if (op == 3) {
            queue.erase(queue.begin() + i - 1);
        }
    }

    for (int j = 0; j < queue.size(); ++j) {
        if (j > 0) cout << " ";
        cout << queue[j];
    }
    cout << endl;

    return 0;
}