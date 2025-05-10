#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int l,m;
	cin >> l >> m;
	vector<int> a(l + 10);
	while(m --)
	{
		int l,r;
		cin >> l >> r;
		for(int i = l;i <=r;i ++)
			a[i] = 1;
	}
	int ans = 0;
	for(int i = 0;i <=l;i ++)
	{
		ans += (a[i] == 0);
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