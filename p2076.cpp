#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 10),b(n + 10);
	int cnt = 0;
	for(int i = 1; i<=n;i ++)
		cin >> a[i];
	for(int i = 1;i <=n;i ++)
		cin >> b[i];

	int q;
	cin >> q;
	while(q--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			cnt ++ ;
		}
		else
		{
			int  t;
			cin >> t;
			cout << a[t] + b[t] * cnt << '\n';
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}