#include <bits/stdc++.h>

#define MOD 530600414
#define N 205000

using namespace std;

int s[N], l[N], r[N], c[N], len[N];

int add(int x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
    return x;
}

int mul(int x, int y)
{
    return 1LL * x * y % MOD;
}

int main()
{
    freopen("10.in", "r", stdin);

    s[3] = 0, l[3] = 0, r[3] = 3, c[3] = 1, len[3] = 3;
    s[4] = 0, l[4] = 2, r[4] = 3, c[4] = 1, len[4] = 5;
    for (int i = 5; i <= 201314; i++)
    {
        s[i] = add(add(s[i - 2], s[i - 1]), add(mul(r[i - 2], c[i - 1]), mul(l[i - 1], c[i - 2])));
        l[i] = add(add(l[i - 2], l[i - 1]), mul(c[i - 1], len[i - 2]));
        r[i] = add(add(r[i - 2], r[i - 1]), mul(c[i - 2], len[i - 1]));
        c[i] = add(c[i - 2], c[i - 1]);
        len[i] = add(len[i - 2], len[i - 1]);
    }

    int ttt;
    scanf("%d", &ttt);
    for (int tt = 1; tt <= ttt; tt++)
    {
        int x;
        scanf("%d", &x);
        printf("Case #%d: %d\n", tt, s[x]);
    }
    return 0;
}
