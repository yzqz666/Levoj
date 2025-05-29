#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> a(n + 10);
	for(int i = 1;i <= n;i ++)
	{
		cin >>  a[i].first >> a[i].second;
	}

	int ans = 0;
	int now = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(now >= m) break;
		if(i == 1)
		{
			ans += a[i].first - now;
			now = a[i].first + a[i].second;
			continue;
		}

		if(a[i].first <= now)
		{
			now = max(now,a[i].first + a[i].second);
			continue;
		}
		else
		{
			ans += a[i].first - now;
			now = a[i].first + a[i].second;
		}

	}
	if (now < m) ans += m - now;
	cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}