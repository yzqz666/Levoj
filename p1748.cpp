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
#include <vector>
#include <unordered_map>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve(){
	int n;
        cin >> n;

        vector<int> A(n), B(n), C(n), D(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i] >> B[i] >> C[i] >> D[i];
        }

        unordered_map<int, int> ab_sum;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = A[i] + B[j];
                ab_sum[sum]++;
            }
        }

        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = C[i] + D[j];
                if (ab_sum.find(-sum) != ab_sum.end()) {
                    count += ab_sum[-sum];
                }
            }
        }
	cout << count << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}