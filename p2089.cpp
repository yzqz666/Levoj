#include<iostream>
#include<algorithm>
#include<vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;


void solve(){
    int k,n;
    cin >> k >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    int ans = 0;
    ll sum = 0;
    ll term = 1;
    while (sum < n) {
        sum += term;
        term *= k;
        ans++;
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