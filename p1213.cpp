#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n,k;
	while(cin >> n >> k)
	{
		vector<int> a(n + 10);
		for(int i = 1;i <= k;i ++)
		{
			int t = i;
			while(t <= n)
			{
				a[t] ^= 1;
				t += i;
			}
			
			
		}
		//cout << (0 ^ 1) << '\n';
		for(int i = 1;i <=n;i ++)
		{
			if(!a[i]) cout << i << " ";
		}
		cout << '\n';
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}