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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 10);#include <iostream>  
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
 } 
int gcd(int a, int b) 
{  
    if (b==0) 
	{  
        return a;  
    }  
    return gcd(b, a % b);  
}  
int main()
{
	int n;
	cin>>n;
	int a[n];
	int dp[n]={1};
	int ans=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(gcd(a[i],a[j])==1)
			dp[i]=max(dp[j]+1,dp[i]);
			ans=max(ans,dp[i]);//因为dp[n]不一定是最长相邻互质子序列的尾数 
		}
	}
	cout<<ans<<endl;
	return 0;
}

	for(int i = 1;i <= n;i ++)
		cin >> a[i];

	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		vector<int> b;
		b.push_back(a[i]);
		
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