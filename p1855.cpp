#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n + 10);
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i = 1;i <= m;i ++)
	{
		q.push(a[i]);
	}

	for(int i = m + 1;i <= n;i ++)
	{
		int t = q.top();
		q.pop();
		q.push(a[i] + t);
	}

	int ans = 0;
	while(q.size())
	{
		ans = max(ans,q.top());
		q.pop();
	}
	cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}