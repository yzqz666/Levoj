#include<iostream>
using namespace std;
int a[105][105];  //a[r][c]
int dp[105][105];
// 从 DP[x][y] 处 出发 ，滑最大距离
int d1[5] = { 0,1,0,-1,0 };
int d2[5] = { 0,0,1,0,-1 };
int r, c;
int dfs(int x, int y)
{
	if (dp[x][y]) return dp[x][y];
	dp[x][y] = 1;
	for (int i = 1; i <= 4; i++)
	{
		int x2 = x + d1[i];
		int y2 = y + d2[i];
		if (x2 > 0 && y2 > 0 && x2 <= r && y2 <= c && a[x][y] > a[x2][y2])
		{
			dfs(x2, y2);
			dp[x][y] = max(dp[x][y], dp[x2][y2] + 1);
		}
	}
	return dp[x][y];
}
void printfdp()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	cin >> r >> c;
	int ans = 0;
	
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans;
	
	return 0;
}