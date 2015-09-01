#include <bits/stdc++.h>

using namespace std;

int a[100000];

long long getgcd(long long u, long long v)
{
    if (u == 0 || v == 0) return u + v;
    return getgcd(v, u % v);
}
long long gcd(int l, int r)
{
    long long tmp = a[l];
    for (int i = l + 1; i <= r; ++i)
        tmp = getgcd(tmp, a[i]);
}

long long ask(int l, int r)
{
    long long tmp = 0;
    for (int i = l; i <= r; ++i)
        for (int j = i; j <= r; ++j)
            tmp += gcd(i, j);
    return tmp;
}

int main()
{
    int ca;
    freopen("B.in", "r", stdin);
    for (scanf("%d", &ca); ca; --ca)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int q;
        scanf("%d", &q);
        for (int i = 1; i <= q; ++i)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", ask(l, r));
        }
    }
    return 0;
}
