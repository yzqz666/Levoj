#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> dis[n + 10];
	for(int i = 1;i <= n;i ++)
	{
		dis[i].resize(n + 10);
		for(int j = 1;j <= n;j ++)
		{
			cin >> dis[i][j];
		}
	}

	int q;
	cin >> q;
	while(q--)
	{
		int u,v,w;
		cin >> u >> v >> w;
		for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j <= n;j ++)
			{
				 //cerr << i << " " << j << " " << u << " " << v << '\n';
				 //cerr << dis[i][j] << " " << dis[i][u] + w + dis[u][j] << '\n';
				dis[i][j] = min(dis[i][j],dis[i][u] + w + dis[v][j]);
				dis[i][j] = min(dis[i][j],dis[i][v] + w + dis[u][j]);
			}
		}

		int ans = 0;
		for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j < i;j ++)
			{
				ans += dis[i][j];
			}
		}
		cout << ans <<" ";

	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}