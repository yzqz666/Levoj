#include<bits/stdc++.h>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int v;
	cin >> v;
	int n;
	cin >> n;
	vector<int> val(n + 10),w(n + 10);
	for(int i = 1;i <= n;i ++)
		cin >> w[i] >> val[i];
	vector<int> dp(v + 10);
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = v ;j >= w[i];j --)
		{
			dp[j] = max(dp[j],dp[j - w[i]] + val[i]);
		}
	}
	cout << dp[v] << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
