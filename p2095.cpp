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
	vector<int> e[n + 10];
	for(int i = 1;i <=n;i ++)
	{
		e[i].resize(n + 10);
		for(int j = 1;j <=n;j ++)
		{
			cin >> e[i][j];
		}
	}
	int cnt = 0;
	vector<int> deg(n + 10);
	for(int i = 1;i <= n;i ++)
	{
		for(int j = i;j <= n;j ++)
		{
			if(e[i][j])
			{
				deg[i] ++ ;
				deg[j] ++ ;
			}
		}
	}
	for(int i = 1;i <= n;i ++)
		if(deg[i] & 1) cnt ++ ;
	if(cnt == 0 || cnt == 2)
	{
		cout << "YES" << '\n';
	}
	else
	{
		cout << "NO" << '\n';
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}