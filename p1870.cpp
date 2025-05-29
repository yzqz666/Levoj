#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 10),dp(n + 10);
	for(int i = 1 ;i <= n;i ++)
	{
		cin >> a[i];
	}

	for(int i = 1;i <= n;i ++)
	{
		dp[i] = max(dp[i - 1],dp[i - 2] + a[i]);

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