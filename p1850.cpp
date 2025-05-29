#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 10),dp1(n + 10),dp2(n + 10);
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		dp1[i] = dp2[i] = 1;
	}

	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j < i;j ++)
		{
			if(a[j] < a[i])
				dp1[i] = max(dp1[i],dp1[j] + 1);
		}
	}

	reverse(a.begin() + 1,a.begin() + 1 + n);

	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j < i;j ++)
		{
			if(a[j] < a[i])
				dp2[i] = max(dp2[i],dp2[j] + 1);
		}
	}

	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		ans = max(ans,dp1[i] + dp2[n - i + 1] - 1);
	}

	cout << n - ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}