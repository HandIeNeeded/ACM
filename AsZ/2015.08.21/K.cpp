#include <bits/stdc++.h>
#define MAXN 212345
#define MO 1000000007

using namespace std;

typedef int arrayN[MAXN];

arrayN fir, nxt, e, sz, jc, ans;
int num;

void link(int u, int v)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}


int mul(int u, int v)
{
    long long tmp = 1LL * u * v;
    tmp %= MO;
    return (int)tmp;
}

int ok;

void dfs(int x, int fa)
{
    if (!ok) return ;
    sz[x] = 1;
    int oneCnt = 0, mulCnt = 0;
    int mulArr[3];
    for (int p = fir[x]; p; p = nxt[p])
        if (e[p] != fa)
        {
            dfs(e[p], x);
            sz[x] += sz[e[p]];
            if (sz[e[p]] == 1)
                ++oneCnt;
            else
            {
                if (mulCnt > 2)
                {
                    ok = 0;
                    return;
                }
                mulArr[mulCnt++] = e[p];
            }
        }
    if (sz[x] == 1)
    {
        ans[x] = 1;
        return ;
    }
    int tmp = 1;
    if (mulCnt == 0)
    {
        tmp = mul(tmp, jc[oneCnt]);
        if (x == 1) tmp = mul(tmp, 2);
    } else if (mulCnt == 1)
    {
        if (x == 1) tmp = 2;
        tmp = mul(tmp, 2);
        tmp = mul(tmp, ans[mulArr[0]]);
        tmp = mul(tmp, jc[oneCnt]);
    } else
    {
        if (x == 1) tmp = 2;
        tmp = mul(tmp, 2);
        tmp = mul(tmp, ans[mulArr[0]]);
        tmp = mul(tmp, ans[mulArr[1]]);
        tmp = mul(tmp, jc[oneCnt]);
    }
    ans[x] = tmp;
}

int main()
{
  //  freopen("k.in", "r", stdin);
    int ca;
    scanf("%d", &ca);
    jc[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        jc[i] = mul(jc[i - 1], i);
    for (int t = 1; t <= ca; ++t)
    {
        int n;
        num = 0;
        ok = 1;
        memset(fir, 0, sizeof(fir));
        memset(ans, 0, sizeof(ans));
        scanf("%d", &n);
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            link(u, v);
            link(v, u);
        }
        dfs(1, 0);
        int tmp = ans[1];
        if (!ok) tmp = 0;
        printf("Case #%d: %d\n", t, tmp);
    }
    return 0;
}
