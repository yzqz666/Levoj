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
	for(int i = 1;i <= n;i ++)
		cin >> a[i],dp[i] = 1;
	for(int i = 2;i <= n;i ++)
	{
		for(int j = 1;j < i;j ++)
		{
			if(__gcd(a[i],a[j]) == 1)
			{
				dp[i] = max(dp[i],dp[j] + 1);
			}
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