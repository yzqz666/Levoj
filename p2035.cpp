#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	struct node{
		int to,ne,dis;
	};
	vector<int> head(n + 10);
	int id = 1;
	vector<node> e(m * 2 + 10); 
	auto add =[&](int now,int to,int dis){
		e[id].to = to;
		e[id].dis = dis;
		e[id].ne = head[now];
		head[now] = id ++;
	};

	for(int i = 1;i <=m;i ++)
	{
		int now,to;
		cin >> now >> to;
		add(now,to,1);
		add(to,now,1);
	}

	auto dij = [&](int s){
		vector<int> dis(n  + 10),vis(n + 10);
		fill(dis.begin(),dis.end(),1e9);
		dis[s] = 0;

		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		q.push({0,s});

		while(q.size())
		{
			auto now = q.top().second;

			q.pop();

			if(vis[now]) continue;
			vis[now] = 1;

			for(int i = head[now];i;i = e[i].ne)
			{
				int next = e[i].to;
				if(dis[next] > dis[now] + e[i].dis)
				{
					dis[next] = dis[now] + e[i].dis;
					q.push({dis[next],next});
				}
			}
		}

		int cnt = 0;
		for(int i = 1;i <= n;i ++)	cnt += (dis[i] == 1e9);
		
		return cnt;
	};

	int ans = dij(1);
	cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
