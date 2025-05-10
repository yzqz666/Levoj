#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

const int mod = 10000;

ll quickpow(ll a,ll b)
{
	ll ans = 0;
	while(b)
	{
		if((b & 1) != 0) {
	    	ans += a;
	    	ans %= mod;
		}
		a += a;
		a %= mod;
		b >>= 1;
	}
	return ans % mod;
}
void solve(){
	int a,b;
	cin >> a >> b;
	ll ans = 0;
	for(int i = 1;i <= a;i ++)
	{
		ll cnt = 1;
		for(int j = 1;j <= b;j ++)
		{
			cnt = cnt * i;
			cnt %= mod;
		}
		ans += cnt;
		//cerr << cnt  << '\n';
		ans %= mod;
	}
	cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}