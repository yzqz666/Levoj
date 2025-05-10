#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<string> s(n + 10);
	for(int i = 1;i <= n;i ++)
	{
		cin >> s[i];
	}

	int ans = 0;
		for(int j = 0;j < s[1].size();j ++)
		{
			for(int k = j;k < s[1].size();k ++)
			{
				string t = "";
				for(int i = j;i <= k;i ++) t += s[1][i];

				int flag1 = 1;
				for(int i = 2;i <= n;i ++)
				{
					if((int)s[i].find(t) == -1)
					{
						string tt = t;
						reverse(tt.begin(),tt.end());
						if((int)s[i].find(tt) == -1)
							flag1 = 0;
					}
				}

				if(flag1)
					ans = max(ans,(int)t.size());

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