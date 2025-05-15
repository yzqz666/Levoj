#include <bits/stdc++.h>


typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m,s,t;
	cin >> n >> m >> s >> t;
	struct node{
		int to,ne,dis;
	};
	vector<node> e( m * 2 + 10);
	vector<int> head(n + 10);
	int id = 1;

	auto add=[&](int now,int to,int dis)
	{
		e[id].to = to;
		e[id].dis = dis;
		e[id].ne = head[now];
		head[now] = id  ++;
	};

	for(int i = 1;i <= m;i ++)
	{
		int now,to,dis;
		cin >> now >> to >> dis;
		add(now,to,dis);
		add(to,now,dis);
	}

	auto dij = [&](int now,int to){
		vector<int> dis(n + 10),vis(n + 10);
		fill(dis.begin(),dis.end(),1e9);
		dis[now] = 0;

		priority_queue<pair<int ,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		q.push({0,now});

		while(q.size())
		{
			auto now = q.top().second;
			q.pop();

			if(vis[now]) continue;
			vis[now] = 1;

			for(int i = head[now];i;i = e[i].ne)
			{
				int next = e[i].to;
				if(dis[next] > e[i].dis + dis[now])
				{
					dis[next] = e[i].dis + dis[now];
					q.push({dis[next],next});
				}
			}
		}

		return dis[to];
	};

	int ans = dij(s,t);
	cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
