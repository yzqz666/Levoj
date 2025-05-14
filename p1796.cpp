#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dp[16][16]; // 记忆数组，最大为 15×15 棋盘

// 递归函数：从 (x, y) 出发，到 (m, n) 的路径数量
int dfs(int x, int y) {
    if (x > m || y > n) return 0; 
    if (x == m && y == n) return 1; 
    if (dp[x][y] != -1) return dp[x][y];
    int res = dfs(x + 2, y + 1) + dfs(x + 1, y + 2);
    dp[x][y] = res;
    return res;
}

int main() {
    cin >> n >> m; // 注意输入是 n 列 m 行
    // 初始化记忆数组
    for (int i = 0; i <= 15; i++)
        for (int j = 0; j <= 15; j++)
            dp[i][j] = -1;
    // 从 (1,1) 开始
    cout << dfs(1, 1) << endl;
    return 0;
}