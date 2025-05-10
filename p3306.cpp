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
// sqrt(n) 
// 模 x 后为 y 的所有数
// sum[i][j]记录buchang i  start j 的所有下标所对应的数的和
ll sum[400][400];
void solve(){
	int n,m;
	cin >> n >> m;
	//cerr << " !!! " << '\n'
	vector<ll> a(n + 10);
	
	int t = sqrt(n);
	
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}

	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= t;j ++)
		{
			sum[j][i % j] += a[i];
		}
	}
	//cout << " /" << t << '\n';
	while(m --)
	{
		char c;
		int x,y;
		cin >> c >> x >> y;
		ll ans = 0;
		if(c == 'A')
		{
			if(x > t)
			{
				for(int i = y;i <= n;i += x)
				{
					ans += a[i];
				}
			}
			else
			{
				//cerr << "!" << '\n';
				ans = sum[x][y];
			}
			cout << ans << '\n';
		}
		else
		{
			for(int i = 1;i <= t;i ++)
			{
				//cerr << " ! "<< y - a[x] << '\n';
				sum[i][x % i] += y - a[x];
			}
			a[x] = y;
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