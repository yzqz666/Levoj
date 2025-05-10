#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	string s;
	int n;
	cin >> s >> n;
	int len = s.size();
	for(int i = 0;i < s.size();i ++)
	{
		cout << s[i];
		if(i == n - 1)
		{
			for(int j = 1;j <= len - n; j ++)
				cout << s[i];
			cout << '\n';
			for(int j = 1;j <= n;j ++)
				cout << s[i + 1] ;
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