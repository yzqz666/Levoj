#include <algorithm>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <functional>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	struct node{
		int u,v;
		ll dis;
	};
	vector<pair<int,int>> a(n + 1);
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i].first >> a[i].second;
	}
	vector<bool> vis(n + 10, false);
    vector<ll> dist(n + 10, 1e18);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    dist[1] = 0;
    pq.emplace(0, 1);
    ll max_edge = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (vis[u]) continue;
        vis[u] = true;
        max_edge = max(max_edge, d);

        for (int v = 1; v <= n; ++v) {
            if (vis[v]) continue;
            ll dx = a[u].first - a[v].first;
            ll dy = a[u].second - a[v].second;
            ll w = dx * dx + dy * dy;
            if (w < dist[v]) {
                dist[v] = w;
                pq.emplace(w, v);
            }
        }
    }

    cout << max_edge << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}