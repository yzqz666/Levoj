#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int x,y,z;
	cin >> x >> y >> z;
	vector<int> a(z + 10);
	a[0] = x,a[1] = y;
	map<int,int> m;
	m[a[0]] = 0,m[a[1]] = 1;

	for(int i = 2;i <= z;i ++)
	{
		a[i] = a[i / 2] + a[i / 4];
		//cerr << i << " " << a[i] << '\n';
		if(m[a[i]] == 0) m[a[i]] = i;
		else continue;
	}
	
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x ;
		if(x == a[0])
		{
			cout << "0" << '\n';
			continue;
		}
		if(m[x])
		{
			cout << m[x] << '\n';
		}
		else
		{
			cout << "-1" << '\n';
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