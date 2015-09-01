#include <bits/stdc++.h>

#define N 100100

using namespace std;

long long s[N];

long long sum(long long a, long long b)
{
    return (a + b) * (b - a + 1) / 2LL;
}

int main()
{
    freopen("F.in", "r", stdin);
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            s[i] = s[i - 1] + (long long)x;
        }
        if (s[n] == 0)
        {
            long long ans = 0;
            for (int i = 1; i <= n; i++)
                ans += 1LL * (n - i + 1) * i + 1LL * sum(i, n);
            cout << ans << endl;
            continue;
        }
        int mu = (log(s[n]) / log(2)) + 2;
        long long ans = 0;
        for (int k = 0; k < mu; k++)
        {
            long long bl = k ? (1LL << k) : 0;
            long long br = 1LL << (k + 1);
            int l = 1, r = 1;
            for (int i = 1; i <= n; i++)
            {
                if (l < i)
                    l++;
                while (l <= n && s[l] - s[i - 1] < bl)
                    l++;
                while (r <= n && s[r] - s[i - 1] < br)
                    r++;
                if (l == r)
                    continue;
                if (l <= n)
                    ans += 1LL * (k + 1) * (1LL * (r - l) * i + sum(l, r - 1));
                else
                    break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
