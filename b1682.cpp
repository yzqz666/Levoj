#include<bits/stdc++.h>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> fa(n + 10);
	for(int i = 1;i <=n;i ++)
	{
		fa[i] = i;
	}

	function<int(int)> find = [&](int x){
		return x == fa[x] ? x :fa[x] = find(fa[x]); 
	};

	struct node{
		int u,v,dis;
	};
	vector<node> e;

	for(int i = 1;i <= m;i ++)
	{
		int u,v,dis;
		cin >> u >> v >> dis;
		e.push_back({u,v,dis});
	}

	auto cmp = [&](node a,node b){
		return a.dis < b.dis;
	};

	sort(e.begin(),e.end(),cmp);

	int mx = 0;
	for(auto x : e)
	{
		auto [u,v,dis] = x;
		int fu = find(u);
		int fv = find(v);
		if(fu != fv)
		{
			mx = max(mx,dis);
			fa[fu] = fv;
		}
	}
	cout << mx << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
