#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	vector<int> a(1005);
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		int l,r;
		cin >> l >> r;
		a[l] ++ ;
		a[r + 1] --;
	}

	int ans = 0;
	int cnt = 0;
	for(int i = 1;i <= 1004;i ++)
	{
		cnt += a[i];
		//cerr << cnt << '\n';
		ans = max(ans,cnt);
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