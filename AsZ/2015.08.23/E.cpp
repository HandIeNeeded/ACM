#include <bits/stdc++.h>
#define MAXN 212345
#define MAXM 2123456

using namespace std;
typedef int arrayN[MAXN];

arrayN fir, e, nxt, c, xo;
int num, cnt[MAXM];

void link(int u, int v, int w)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num, c[num] = w;
}
void dfs(int x, int fa, int sum)
{
    xo[x] = sum;
    for (int p = fir[x]; p; p = nxt[p])
        if (e[p] != fa)
        {
            dfs(e[p], x, sum ^ c[p]);
        }
    cnt[xo[x]]++;
}

int main()
{
   // freopen("k.in", "r", stdin);
    int ca;
    scanf("%d", &ca);
    for (; ca; --ca)
    {
        int n;
        scanf("%d", &n);
        num = 0;
        memset(fir, 0, sizeof(fir));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i < n; ++i)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            link(u, v, w);
            link(v, u, w);
        }
        dfs(1, 0, 0);
        int q;
        scanf("%d", &q);
        for (; q; --q)
        {
            int s;
            long long ans = 0;
            scanf("%d", &s);

            for (int i = 1; i <= n; ++i)
            {
                ans += 1LL * cnt[s ^ xo[i]];
            }
            if (s == 0) ans += n;
            cout << ans / 2 << endl;
        }
    }
    return 0;
}
