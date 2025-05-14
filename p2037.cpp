#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	struct node{
		int to,ne,dis;
	};
	vector<int> head(n + 10);
	vector<node> e(m * 2 + 10); 
	int id = 1;
	
	auto add =[&](int now,int to,int dis){
		e[id].to = to;
		e[id].dis = dis;
		e[id].ne = head[now];
		head[now] = id ++;
	};

	for(int i = 1;i <=m;i ++)
	{
		int now,to,dis;
		cin >> now >> to >> dis;
		add(now,to,dis);
		add(to,now,dis);
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

		return dis[n];
	};

	int dis1 = dij(x);
	int dis2 = dij(y);

	if(dis1 <= dis2)
	{
		cout << "YES " << dis1 << '\n';
	}
	else
	{
		cout << "NO " << dis2 << '\n';
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}