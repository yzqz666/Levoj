#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0;i < n;i ++)  cin >> a[i];

	sort(a.begin(),a.end());
	while(q--)
	{
		int x;
		cin >> x;
		auto pos = upper_bound(a.begin(),a.end(),x);
		cerr << *pos << '\n';
		cout << (int)(pos - a.begin()) << '\n';
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}