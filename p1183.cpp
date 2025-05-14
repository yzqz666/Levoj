#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    int caseNum = 1;

    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        // 创建三个矩阵分别存储 R G B 值
        vector<vector<int>> R(N, vector<int>(M));
        vector<vector<int>> G(N, vector<int>(M));
        vector<vector<int>> B(N, vector<int>(M));

        // 读入 R、G、B 值
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> R[i][j];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> G[i][j];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> B[i][j];

        // 输出结果
        cout << "Case " << caseNum++ << ":\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int gray = (R[i][j] + G[i][j] + B[i][j]) / 3;
                cout << gray;
                if (j != M - 1) cout << ","; // 添加逗号
            }
            cout << "\n";
        }
    }

    return 0;
}