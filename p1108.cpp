#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	char ans[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	string s;
	cin >> s;
	string a = "";
	int cnt = 0;
	int sum = 0;
	for(int i = s.size() - 1;i >= 0;i --)
	{
		int t = (int)(s[i] - '0');
		sum += t * pow(2,cnt);
		cnt ++ ;
		if(cnt == 4 || i == 0)
		{
			cnt = 0;
			a = ans[sum] + a;
			sum = 0;
		}
	}
	cout << a << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}