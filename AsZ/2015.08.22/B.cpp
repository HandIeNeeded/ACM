#include <bits/stdc++.h>
#define MAXN 212345

using namespace std;

struct node
{
    int mx, mi;
} g[MAXN * 4];

int base, a[MAXN];

const int oo = 1e9 + 10;
void change(int x, int v)
{
    x += base;
    g[x].mx = g[x].mi = v;
    for (x >>= 1; x; x >>= 1)
    {
        g[x].mx = max(g[x << 1].mx, g[x << 1 ^ 1].mx);
        g[x].mi = min(g[x << 1].mi, g[x << 1 ^ 1].mi);
    }
}

void ask(int l, int r, int &mi, int &mx)
{
    int tmp = 0;
    mi = oo;
    mx = -1;
    l += base - 1, r += base + 1;
    for (; (l ^ r) != 1; l >>= 1, r >>= 1)
    {
        if (!(l & 1))
        {
            mi = min(mi, g[l + 1].mi);
            mx = max(mx, g[l + 1].mx);
        }
        if (r & 1)
        {
            mi = min(mi, g[r - 1].mi);
            mx = max(mx, g[r - 1].mx);
        }

    }
}

int main()
{
    //freopen("b.in", "r", stdin);
    int ca, n, k;
    scanf("%d", &ca);
    for (int t = 1; t <= ca; ++t)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int l = 0, r = 0;
        for (base = 1; base <= n + 3; base <<= 1);
        for (int i = 1; i <= n; ++i)
            change(i, a[i]);
        long long ans = 0;
        for (;;)
        {
            ++l;
            for (;r < n;)
            {
                int mx, mi;
                ask(l, r + 1, mi, mx);
                if (mx - mi < k)
                {
                    ++r;
                    ans += r - l + 1;
                } else break;
            }
            if (r == n) break;
        }
        cout << ans << endl;
    }
    return 0;
}
