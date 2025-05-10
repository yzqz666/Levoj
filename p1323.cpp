#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n;
int ans = 0;
void g(int cnt)
{
	if(cnt < 0) return;
	if(cnt == 0)
	{
		ans ++;
		return;
	}
	else
	{
		g(cnt - 1);
		g(cnt - 2);
	}
}
void solve(){
	while(cin >> n)
	{
		ans = 0;
		g(n);
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