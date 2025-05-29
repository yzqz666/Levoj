#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,w;
	cin >> n >> w;
	vector<int> a(n + 10);
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	int ans = 0;
	sort(a.begin() + 1,a.begin() + 1 + n);
	int l = 1,r = n;
	while(l < r)
	{
		//cerr << l << " " << r << '\n';
		if(a[l] + a[r] <= w)
		{
			ans ++;
			l ++,r --;
		}
		else
		{
			ans ++;
			r --;
		}
	}
	if(l == r)
	{
		ans ++;
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