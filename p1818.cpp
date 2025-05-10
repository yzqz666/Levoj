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
	int n,q;
	cin >> n >> q;
	vector<ll> a(n+10);
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		a[i] += a[i-1];
	}

	for(int i = 1;i <= q ;i ++)
	{
		int t;
		cin >> t;
		auto pos = lower_bound(a.begin() + 1 ,a.begin() + 1 + n,t) 
		- (a.begin() + 1);
		cout << pos + 1 << " \n"[i==q];
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}