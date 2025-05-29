#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int A, B, id;
};

// 主函数
int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    vector<Job> left, right;

    // 根据 Johnson 法则分类
    for (int i = 0; i < n; ++i) {
        if (A[i] <= B[i]) {
            left.push_back({A[i], B[i], i});
        } else {
            right.push_back({A[i], B[i], i});
        }
    }

    // left：按 A 升序
    sort(left.begin(), left.end(), [](const Job &j1, const Job &j2) {
        return j1.A < j2.A;
    });

    // right：按 B 降序
    sort(right.begin(), right.end(), [](const Job &j1, const Job &j2) {
        return j1.B > j2.B;
    });

    // 拼接最终顺序
    vector<Job> sequence;
    sequence.insert(sequence.end(), left.begin(), left.end());
    sequence.insert(sequence.end(), right.begin(), right.end());

    // 模拟加工流程
    int timeA = 0, timeB = 0;
    for (const auto& job : sequence) {
        timeA += job.A;
        timeB = max(timeB, timeA) + job.B;
    }

    cout << timeB << endl;
    return 0;
}