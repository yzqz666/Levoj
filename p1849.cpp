#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n + 10);
	vector<int> cnt(m + 10);
	for(int i =1;i <= n;i ++)
		cin >> a[i];
	for(int i = 1;i <= m;i ++)
	{
		int t;
		cin >> t;
		cnt[t] ++;
	}
	//cerr << "!" << '\n';
	int dp[51][51][51][51];
	memset(dp,-1,sizeof(dp));

	dp[0][0][0][0] = a[1];

	for(int i = 0;i <= cnt[1];i ++)
	{
		for(int j = 0;j <= cnt[2];j ++)
		{
			for(int k = 0;k <= cnt[3];k ++)
			{
				for(int l = 0;l <= cnt[4];l ++)
				{
					if(dp[i][j][k][l] == -1) continue;
					int pos = i * 1 + j * 2 + k * 3 + l * 4;
					if(i < cnt[1])
						dp[i + 1][j][k][l] = max(dp[i + 1][j][k][l],dp[i][j][k][l] + a[pos + 2]);

					if(j < cnt[2])
						dp[i][j + 1][k][l] = max(dp[i][j + 1][k][l],dp[i][j][k][l] + a[pos + 3]);

					if(k < cnt[3])
						dp[i][j][k + 1][l] = max(dp[i][j][k + 1][l],dp[i][j][k][l] + a[pos + 4]);

					if(l < cnt[4])
						dp[i][j][k][l + 1] = max(dp[i][j][k][l + 1],dp[i][j][k][l] + a[pos + 5]);
				}
			}
		}
	}

	cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}