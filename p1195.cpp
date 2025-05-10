#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	while(cin >> n)
	{
		n --;
		ll ans = 1;
		while(n --)
		{
			ans = ans + 1;
			ans *= 2;
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