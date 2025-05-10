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


// 块内记录操作数，块外暴力修改
void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n + 10);
	vector<int> belong(n + 10),st(n + 10),end(n + 10);
	vector<int> cnt(n + 10),sum(n + 10);
	int block = sqrt(n);
	int tot = n / block;
	if(n % block != 0) tot ++;

	for(int i = 1;i <= tot;i ++)
	{
		st[i] = (i - 1) * block + 1;
		end[i] = i * block;
	} 
	end[tot] = n;
	for(int i = 1;i <= n;i ++)
	{
		belong[i] = (i - 1) / block + 1;
	}

	function<void(int,int)> update = [&](int l,int r){
		if(belong[l] == belong[r])
		{
			for(int i = l;i <= r;i ++)
			{
				if(a[i] == 0)
				{
					a[i] = 1;
					sum[belong[i]] ++;
				}
				else
				{
					a[i] = 0;
					sum[belong[i]] --;
				}
			}
			return;
		}

		for(int i = l;i <= end[belong[l]];i ++)
		{
			if(a[i] == 0)
			{
				a[i] = 1;
				sum[belong[i]] ++;
			}
			else
			{
				a[i] = 0;
				sum[belong[i]] --;
			}
		}
		//cout << "MMM" << sum[2] << '\n';
		for(int i = st[belong[r]];i <= r;i ++)
		{
			//cout << belong[i] << "? "<< '\n';
			if(a[i] == 0)
			{
				a[i] = 1;
				sum[belong[i]] ++;
			}
			else
			{
				a[i] = 0;
				sum[belong[i]] --;
			}
		}
		// 1 2 3 4 5 6 7 8
		//cout << "MMM" << sum[2] << '\n';

		for(int i = belong[l] + 1;i < belong[r];i ++)
		{
			//cerr << "#" << i << '\n';
			cnt[i]++;
		}
	};

	function<ll(int,int)> ask = [&](int l,int r){
		ll ans = 0;
		if(belong[l] == belong[r])
		{
			for(int i = l;i <= r;i ++)
			{
				if(cnt[belong[i]] & 1)
				{
					if(a[i] == 0)
					{
						ans ++;
					}
				}
				else
				{
					if(a[i] == 1)
					{
						ans ++;
					}
				}
			}
			return ans;
		}

		for(int i = l;i <= end[belong[l]];i ++)
		{
			if(cnt[belong[i]] & 1)
			{
				if(a[i] == 0)
				{
					ans ++;
				}
			}
			else
			{
				if(a[i] == 1)
				{
					ans ++;
				}
			}
		}
		

		for(int i = st[belong[r]];i <= r;i ++)
		{
			if(cnt[belong[i]] & 1)
			{
				if(a[i] == 0)
				{
					ans ++;
				}
			}
			else
			{
				if(a[i] == 1)
				{
					ans ++;
				}
			}
		}

		for(int i = belong[l] + 1;i < belong[r];i ++)
		{
			if(cnt[i] & 1)
			{
				ans += block - sum[i];
			}
			else
			{
				ans += sum[i];
			}
		}

		return ans;
	};

	while(m--)
	{
		int op,l,r;
		cin >> op >> l >> r;
		if(op == 0)
		{
			update(l,r);

		}
		else
		{
			cout << ask(l,r) << '\n';
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