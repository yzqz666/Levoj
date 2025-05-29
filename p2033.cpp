#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m;
	cin >>n >> m;
	vector<int> a;
	for(int i = 1;i <= n;i ++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	while(m--)
	{
		int x;
		cin >> x;
		int ans = upper_bound(a.begin(),a.end(),x) - a.begin();
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