#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> dp(n + 10);
	for(int i = 1;i <=n;i ++)
	{
		int  t;
		cin >> t;
		if(i == 1) 
		{
			dp[i] = t;
			continue;
		}
		dp[i] = max(dp[i - 1] + t,t);
	}
	int ans = -1e8;
	for(int i = 1;i <=n;i ++) ans= max(ans,dp[i]);
	cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}