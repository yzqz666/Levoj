#include<bits/stdc++/h>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> dp[n + 10];
	vector<int> a[n + 10];
	for(int i = 1;i <= n;i ++)
	{
		dp[i].resize(m + 10);
		a[i].resize(m + 10);
		for(int j = 1;j <= m;j ++)
		{
			cin >> a[i][j];
			dp[i][j] = 0;
		}
	}

	dp[1][1] = a[1][1];
	a[0].resize(m + 10),dp[0].resize(m + 10);
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{

			dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]) + a[i][j];
		}
	}

	cout << dp[n][m] << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
