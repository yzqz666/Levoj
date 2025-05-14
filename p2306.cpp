#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 判断一个序列是否严格降序
bool isDescending(const vector<int>& seq) {
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i-1] <= seq[i]) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<bool> select(n, false);
    fill(select.begin(), select.begin() + m, true);

    int count = 0;
    do {
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
            if (select[i]) temp.push_back(nums[i]);
        }

        sort(temp.begin(), temp.end()); 
        do {
            if (isDescending(temp)) {
                count++;
            }
        } while (next_permutation(temp.begin(), temp.end()));

    } while (prev_permutation(select.begin(), select.end()));

    cout << count << endl;
    return 0;
}