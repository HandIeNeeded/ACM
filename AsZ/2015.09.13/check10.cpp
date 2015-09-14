#include <bits/stdc++.h>

using namespace std;
const int lim = 50;

int cnt[lim];

void get(int k, long long val)
{
    long long x = val;
    for (int i = 2; i <= x; ++i)
        if (x % i == 0)
        {
            for (; x % i == 0; x /= i, cnt[i] += k);
        }
}

int main()
{
    freopen("10.in", "r", stdin);
    int T;
    for (scanf("%d", &T); T; --T)
    {
        long long n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        long long mod = 1;
        for (int i = 1; i <= k; ++i)
        {
            int x;
            scanf("%d", &x);
            mod *= x;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i)
            get(1, i);
        for (int i = 1; i <= m; ++i)
            get(-1, i);
        for (int i = 1; i <= n - m; ++i)
            get(-1, i);
        long long ans = 1;
        for (int i = 1; i <= lim; ++i)
            for (int j = 1; j <= cnt[i]; ++j)
                ans = ans * i % mod;
        cout << ans << endl;
    }
    return 0;
}
