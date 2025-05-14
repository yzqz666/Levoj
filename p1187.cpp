#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;
vector<int> primes;

// 筛选法生成质数表（埃氏筛）
void sieve() {
    vector<bool> isPrime(MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAXN; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= MAXN; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
}

bool isSemiPrime(int n) {
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; ++i) {
        if (n % primes[i] == 0) {
            int other = n / primes[i];
            // 如果商也是质数，且 n = p1 * p2，只能有两个质因数
            if (binary_search(primes.begin(), primes.end(), other)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    sieve(); // 预处理质数

    int n;
    while (cin >> n) {
        if (isSemiPrime(n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}