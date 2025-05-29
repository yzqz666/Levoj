#include <algorithm>
#include <bitset>
#include <complex>
#include <vector>
#include<iostream>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

//设 dp[i][j] 表示：s1 的前 i 个字符 和 s2 的前 j 个字符 是否能交错组成 s3 的前 i + j 个字符。
void solve(){
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	int n = s1.size(),m = s2.size(),l = s3.size();
	vector<int> dp[n + 10];
	for(int i = 0;i <= n;i ++)
		dp[i].resize(m + 10);
	if(abs(n + m - l) > 1)
	{
		cout << "NO" << '\n';
		return;
	}
	dp[0][0] = 1;
	//cerr << n << " " << m << '\n';
	for(int i = 0;i <= n;i ++)
	{
		for(int j = 0;j <= m;j ++)
		{
			//cerr << i << " " << j << '\n';
			if(i > 0 && s1[i - 1] == s3[i + j - 1])
				dp[i][j] = dp[i][j] || dp[i - 1][j];
			if(j > 0 && s2[j - 1] == s3[i + j - 1])
				dp[i][j] = dp[i][j] || dp[i][j - 1];
		}
	}

	if(dp[n][m])
		cout << "YES" << '\n';
	else
		cout <<"NO" << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}