#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int x;
	cin >> x;
	//ll l = 1, r = x;
	int ans = sqrt(x);
	int lst = ans;
	ll num = abs(x - ans * ans);
	//cerr << "!" << ans << " " << num <<'\n';
	//cerr << "!" << lst << '\n';
	if(abs(x - (ans + 1) * (ans + 1)) < num)
	{
		lst = ans + 1;
		num = abs(x - (ans + 1) * (ans + 1));
	}
	if(abs(x - (ans - 1) * (ans - 1)) < num)
	{
		lst = ans - 1;
		num = abs(x - (ans - 1) * (ans - 1));
	}

	cout << lst << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
