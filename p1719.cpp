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
	int n,k,t;
	cin >> n >> k;
	vector<int> pos;
	for(int i = 1;i <= n;i ++)
	{
		cin >> t;
		if(t == k) pos.push_back(i);
	}
	//for(auto x : pos) cout << x << '\n';

	int ans = 0;
	for(auto x : pos)
	{
		t = log2(x);
		if((int)pow(2,t) == x)
		{
			ans ++;
		}
		else
		{
			int cnt = x - pow(2,t) + 1;
			
			if(cnt <= ans) ans ++;
			else ans = max(cnt,ans);
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