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
	while(cin >> n)
	{
		if(n == 0) return ; 
		vector<string> s(n + 10);
		for(int i = 1;i <=n;i ++)
		{
			cin >> s[i];
		}
		auto cmp = [&](string a,string b){
			return a + b > b + a;
		};
		sort(s.begin() + 1 ,s.begin() + 1 + n,cmp);
	
		for(int i = 1;i <= n;i ++)
			cout << s[i];
		cout << '\n';
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}