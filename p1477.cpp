#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,v;
	cin >> n >> v;
	vector<double> val(n + 10),w(n + 10);
	for(int i = 1; i <= n;i ++)
	{
		cin >> w[i] >> val[i];
		val[i] /= w[i];
	}

	vector<double> dp(v + 10);
	for(int i = 1;i <=n;i ++)
	{
		for(int j = v;j >= 1;j --)
		{
			for(int k = 1;k <= min(w[i],j * 1.0) ;k ++)
			{
				dp[j] = max(dp[j],dp[j - k] + k * val[i]);
			}
		}
	}

	cout << (int)dp[v] << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
