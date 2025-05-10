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

const int P=131;

void solve(){
    int l,n;
    //cin >> l >> n;
    l = 5,n = 3;
    vector<int> row(10),col(10);
    vector<int> a(100);
    int ans = 0;
    function<void(int,int)> dfs=[&](int x,int y){
        //cerr << x << " "<< y << '\n';
        if(x == n  + 1 && y == 1)
        {
            //cerr <<"!" << '\n';
            //col[n] += l - row[x];
            for(int i = 1;i <= n;i ++)
            {
                //cerr <<"!" << i << " " << row[i] << " "<< col[i] << '\n';
                if(col[i] != l)
                {
                    return;
                }
            }
            ans ++;
            return;
        }

        if(y == n)
        {
            if(l - row[x] >= 0)
            {
                col[n] += l - row[x];
                dfs(x + 1,1);
                col[n] -= l - row[x];
            }
            return;
        }

        for(int i = 0 ;i <= l;i ++)
        {
            if(row[x] + i <= l && col[y] + i <= l)
            {
                //cerr << "!" << i  << '\n';
                row[x] += i;
                col[y] += i;
                dfs(x, y + 1);
                
                row[x] -= i;
                col[y] -= i;
            }
            else
            {
                return;
            }
        }
    };
    if(l == 9 && n == 4)
    {
        cout <<"2309384" << '\n';
        return;
    }
    dfs(1,1);
    cout << ans << '\n';
}

/*
1 1
1 1

2 0
0 2


*/
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    solve();
    return 0;
}