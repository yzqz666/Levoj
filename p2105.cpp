#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n + 10);
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	int l = 0;
	int ans = 0;
	int sum = 0;
	for(int r = 1;r <= n;r ++)
	{
		sum += a[r];
		if(sum <= m)
		{
			ans = max(ans,sum);
		}
		else
		{
			while(sum > m)
			{
				sum -= a[l];
				l ++;
			}
			ans = max(ans,sum);
		}
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