#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans = "";
	for(int i = n;i < s.size();i ++)
		ans += s[i];
	for(int i = 0;i < n;i ++)
	{
		ans += s[i];
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