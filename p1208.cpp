#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> w(m + 10),v(m + 10);
	for(int i = 1;i <= m;i ++)
	{
		cin >> w[i] >> v[i];
	}
	vector<int> dp(n + 10);
	for(int i = 1;i <= m ;i ++)
	{
		for(int j = n;j >= w[i];j --)
		{
			dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[n] << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}