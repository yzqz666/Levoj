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
	int v;
	cin >> v;
	int n;
	cin >> n;
	vector<int> val(n + 10),w(n + 10);
	for(int i = 1;i <= n;i ++)
		cin >> w[i] >> val[i];
	vector<int> dp(v + 10);
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = v ;j >= w[i];j --)
		{
			dp[j] = max(dp[j],dp[j - w[i]] + val[i]);
		}
	}
	cout << dp[v] << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}