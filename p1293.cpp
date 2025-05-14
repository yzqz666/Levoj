#include <iostream>
#include <vector>

using namespace std;

int countWays(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 初始化：0 个苹果无论几个盘子都只有一种放法
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1;
    }

    // 开始填表
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i < j)
                dp[i][j] = dp[i][i]; // 盘子多于苹果时，等价于 dp[i][i]
            else
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
        }
    }

    return dp[m][n];
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << countWays(m, n) << endl;
    
    return 0;
}