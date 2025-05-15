#include <bits/stdc++.h>
using ull = unsigned long long;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	int ans = 0;
	function<void(int)> dfs = [&](int now){
		
		if(now == n)
		{
			ans ++;
			return;
		}

		for(int i = 1;i <= 6;i ++)
		{
			if(now + i > 6)
			{
				return;
			}
			dfs(now + i);
		}
	};
	
	dfs(0);

	cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
