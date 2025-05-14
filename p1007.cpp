#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	while(cin >> n)
	{
		while(n--)
		{
			int a,b,c;
			cin >> a >> b >> c;
			cout << (__gcd(__gcd(a,b),c)) << '\n';
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