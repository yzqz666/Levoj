#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int f[1001], n, res[1001], sav[1001];
void t1()
{
    memset(sav, 0, sizeof(sav));
    for (int i = 1; i <= 500; i += 1)
    {   for (int j = 1; j <= 500; j += 1)
        {
            sav[i + j - 1] += res[i] * f[j];
        }
    }
    for (int i = 1; i <= 500; i += 1)
    {
        sav[i + 1] += sav[i] / 10;
        sav[i] %= 10;
    }
    memcpy(res, sav, sizeof(res));
}

void t2()
{
    memset(sav, 0, sizeof(sav));
    for (int i = 1; i <= 500; i += 1)
    {
        for (int j = 1; j <= 500; j += 1)
        {
            sav[i + j - 1] += f[i] * f[j];
        }
    }
    for (int i = 1; i <= 500; i += 1)
    {
        sav[i + 1] += sav[i] / 10;
        sav[i] %= 10;
    }
    memcpy(f, sav, sizeof(f));
}

void solve()
{

    cin >> n;
    res[1] = 1;
    f[1] = 2;
    while (n != 0)
    {
        if (n % 2 == 1)t1();
        n /= 2;
        t2();
    }
    res[1] -= 1;
    // }
    for (int i = 500; i >= 1; i -= 1)
        cout << res[i];
    cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    solve();
    return 0;
}
