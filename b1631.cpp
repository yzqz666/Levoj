#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	struct node{
		int ne,to,dis;
	};
	int n,m,x;
	cin >> n >> m >> x;
	vector<node> e1(m + 10),e2(m + 10);
	vector<int> head1(n * 4),head2(n * 4);
	int id1 = 1;
	auto add1 = [&](int now,int to,int dis){
		e1[id1].to = to;
		e1[id1].dis = dis;
		e1[id1].ne = head1[now];
		head1[now] = id1 ++;
	};

	int id2 = 1;
	auto add2 = [&](int now,int to,int dis){
		cerr << now << " " << to << '\n';
		e2[id2].to = to;
		e2[id2].dis = dis;
		e2[id2].ne = head2[now];
		head2[now] = id2 ++;
	};

	for(int i = 1;i <= m;i ++)
	{
		int now ,to ,dis;
		cin >> now >> to >> dis;
		add1(now,to,dis);
		add2(to,now,dis);
	}

	auto dij = [&](vector<node> e,vector<int> head){
		vector<int> dis(n + 10),vis(n + 10);
		priority_queue< pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> q;
		q.push({0,x});
		fill(dis.begin(),dis.end(),1e9);
		dis[x] = 0;

		while(q.size())
		{
			auto now = q.top().second;
			
			q.pop();

			if(vis[now]) continue;
			vis[now] = 1;
			
			for(int i = head[now];i;i = e[i].ne)
			{
				int next = e[i].to;
				if(dis[now] + e[i].dis < dis[next])
				{
					dis[next] = dis[now] + e[i].dis;
					q.push({dis[next],next});
				}
			}
		}

		return dis;
	};

	vector<int>dis = dij(e1,head1);
	vector<int> ans(n + 10);

	for(int i = 1;i <=n;i ++) ans[i] += dis[i];

	dis = dij(e2,head2);
	for(int i = 1;i <=n;i ++) ans[i] += dis[i];

	int sum = 0;
	for(int i = 1;i <=n;i ++) sum = max(sum,ans[i]);
	cout << sum << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}