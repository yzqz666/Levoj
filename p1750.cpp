#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

const ll N = 5e5 + 10;
struct BIT{
    ll tre[N];
    BIT(){
        for(int i = 1;i < N;i ++) tre[i] = 0;
    }
    int lowbit(int x) { return x & (-x); }
    void update(int x,int d)
    {
        for(;x < N;x += lowbit(x))
            tre[x] += d;
    }
    ll query(int x)
    {
        ll ans = 0;
        for(;x;x -= lowbit(x))
            ans += tre[x];
        return ans;
    }
};

struct point{
	int val,num;
};
void solve(){
	int n;
	cin >> n;
	BIT bit;
	vector<point> a(n + 10);
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i].val;
		a[i].num = i;
	}

	auto cmp = [&](point a,point b){
		if(a.val == b.val)
			return a.num > b.num;
		return a.val > b.val;
	};

	sort(a.begin() + 1,a.begin() + 1 + n,cmp);

	ll ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		bit.update(a[i].num,1);
		ans += bit.query(a[i].num - 1);
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