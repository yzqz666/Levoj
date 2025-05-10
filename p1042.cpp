#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	string s;
	cin >> s;
	string ans = "6";
	for(int i = s.size() - 5;i <s.size();i ++)
		ans += s[i];
	cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}