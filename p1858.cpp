#include<bits/stdc++.h>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

const int maxn = 1e6;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 10),fa(maxn + 10);
	vector<int> ans;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}

	for(int i = 1;i <= maxn + 1;i ++) fa[i] = i;

	function<int(int)> find = [&](int x){
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	};

	for(int i = 1;i <= n;i ++)
	{
		int fx = find(a[i]);
		ans.push_back(fx);
		fa[fx] = fx  + 1;
	}
	
	for(auto x : ans)
		cout << x << " ";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}