#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m;
	while(cin >> n >> m)
	{
	vector<int> a(n + 10);
	for(int i = 1 ;i <= n;i ++)
	{
		cin >> a[i];
	}

	sort(a.begin() + 1,a.begin() + 1 + n);
	int ans= 0 ;
	for(int i = 1;i <=n;i ++)
	{
		if(m >= a[i])
		{
			ans = max(ans,i);
			m -= a[i];
		}
	}
	cout << ans << '\n';
	}	
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}