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
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;
    set<long long> st;
    for(int i = 1;i <= n;i ++)
    {
        int t;
        cin >> t;
        st.insert(2 * t);
    }

    while (q--) {
        int op;
        long long x;
        cin >> op >> x;
        if (op == 1) {
            st.insert(2 * x);
        } else if (op == 2) {
            long long ans = 0,now = x;
            if(st.empty())
            {
                cout << now << '\n';
                continue;
            }
            while(now != 1)
            {
                auto it = st.upper_bound(now);
                if(it == st.begin()){
                    ans += now - 1;
                    break;
                }
                --it;
                long long t = *it;
                ans += (now - t);
                ans += 1;
                now = t / 2;
                //cerr << now << " "  << ans << '\n';
            }
            cout << ans + 1 << '\n';
        }
        else
        {
            st.erase(x * 2);
        }
    }

    return 0;
}
