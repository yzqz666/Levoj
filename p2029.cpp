#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int m,n;
	cin >> m >> n;
	vector<vector<int>> a(n + 10);

	for(int i = 1;i <= n;i ++)
	{
		int x,y;
		cin >> x >> y;
		a[y].push_back(x);
	}

	for(int i = m;i >=0;i --)
	{
		cout << i << " ";
		for(auto x : a[i])
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