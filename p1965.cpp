#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> cnt(n + 10);
	for(int i = 1;i <= n;i ++)
		cin >> cnt[i];
	vector<vector<int>> a(n + 10);
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= cnt[i];j ++)
		{
			int t;
			cin >> t;
			a[i].push_back(t);
		}

	}
	int m;
	cin >> m;
	vector<vector<int>> b(n + 10);
	while(m --)
	{
		int l,r;
		cin >> l >> r;
		b[r].push_back(l);

	}
	for(int i = 1;i <=n;i ++)
	{
		reverse(b[i].begin(),b[i].end());
		for(auto x : b[i])
			cout << x << " ";
		for(auto x: a[i])
			cout << x << " ";
		cout << '\n';
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}