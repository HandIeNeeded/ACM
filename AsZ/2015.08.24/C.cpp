#include <bits/stdc++.h>
#define MAXN 212345

typedef int arrayN[MAXN];

using namespace std;

int num, f[MAXN * 2];
arrayN fir, e, nxt, dp, vis, seq;

void link(int u, int v)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}

struct node
{
    int f, inCir, dep, sz, pre;
}g[MAXN];

int ok;
vector <int> cirVec;

void dye(int u, int v)
{
    int tu = u, tv = v;
    for (; u != v; )
    {
        if (g[u].dep < g[v].dep) swap(u, v);
        g[u].inCir = 1;
        //cirVec.push_back(u);
        u = g[u].f;
    }
    g[u].inCir = 1;
    for (; tu != u; tu = g[tu].f)
        cirVec.push_back(tu);
    cirVec.push_back(u);
    vector <int> vecTmp;
    for (; tv != u; tv = g[tv].f)
        vecTmp.push_back(tv);
    int n = vecTmp.size();
    for (int i = n - 1; i >= 0; --i)
        cirVec.push_back(vecTmp[i]);
}

void dfsCircle(int x, int fa, int dep)
{
    vis[x] = 1;
    g[x].f = fa;
    g[x].dep = dep;
    for (int p = fir[x]; p && !ok; p = nxt[p])
        if (e[p] != fa)
        {
            if (vis[e[p]])
            {
                ok = 1;
                dye(x, e[p]);
                break;
            }
            dfsCircle(e[p], x, dep + 1);
        }
}

int checkOk;

void dfsDp(int x, int fa, int nb)
{
    dp[x] = 1;
    for (int p = fir[x]; p && checkOk; p = nxt[p])
        if (e[p] != fa && g[e[p]].inCir == 0)
        {
            dfsDp(e[p], x, nb);
            dp[x] += dp[e[p]];
        }
    if (dp[x] == nb) dp[x] = 0;
    else if (dp[x] > nb)
    {
        checkOk = 0;
        return ;
    }
}

int checkNo0(int x)
{
    int n = cirVec.size();
    int sum = dp[cirVec[0]];
    if (sum == x) f[0] = -1;
    else f[0] = 0;
    int l = 0;
    for (int i = 1; i < n; ++i)
    {
        int p = cirVec[i];
        sum += dp[p];
        for (;sum > x; sum -= dp[cirVec[l++]]);
        if (sum == x)
        {
            if (l == 0) f[i] = l - 1;
            else f[i] = f[l - 1];
        } else f[i] = i;
        if (i - f[i] >= n / 2) return 1;
    }
    return 0;
}

int checkHave0(int x, int sta)
{
    int n = cirVec.size() / 2;
    int sum = 0;
    for (int i1 = 0; i1 < n; ++i1)
    {
        int i = i1 + sta;
        sum += dp[cirVec[i]];
        if (sum > x) return 0;
        if (sum == x) sum -= x;
        if (dp[cirVec[i]] == 0)
        {
            if (sum) return 0;
        }
    }
    return 1;
}

int check(int x, int n)
{
    //for (int i = 0; i < cirVec.size() / 2; ++i)
      //  dfsDp(cirVec[i], 0, x);
   /* for (int i = n; i >= 1; --i)
    {
        int u = seq[i];
        dp[u] = 1;
        for (int p = fir[u]; p; p = nxt[p])
            if (g[e[p]].inCir == 0 && g[u].pre != e[p])
            {
                dp[u] += dp[e[p]];
            }
        if (dp[u] > x) return 0;
        if (dp[u] == x) dp[u] = 0;
    }*/
    for (int i = 1; i <= n; ++i)
        dp[i] = 1;
    for (int i = n; i >= 1; --i)
    {
        int v = seq[i];
        int u = g[v].pre;
        if (v)
        {
            if (dp[v] > x) return 0;
            if (dp[v] == x) dp[v] = 0;
        }
        dp[u] += dp[v];
    }
    int m = cirVec.size() / 2;
    /*for (int i = 0; i < m; ++i)
    {
        int p = cirVec[i];
        dp[p] = g[p].sz % x;
    } */
    for (int i = 0; i < m; ++i)
    {
        if (dp[cirVec[i]] == 0)
            return checkHave0(x, i);
    }
    return checkNo0(x);
}


void getBfsSeq(int n)
{
    int l = 1, r = 0;
    for (int i = 1; i <= n; ++i) vis[i] = 0;
    for (int i = 0; i < cirVec.size() / 2; ++i)
    {
        seq[++r] = cirVec[i];
        vis[cirVec[i]] = 1;
        g[cirVec[i]].pre = 0;
    }
    for (; l <= r; ++l)
    {
        int u = seq[l];
        for (int p = fir[u]; p; p = nxt[p])
            if (!vis[e[p]])
            {
                seq[++r] = e[p];
                vis[e[p]] = 1;
                g[e[p]].pre = u;
            }
    }
    for (int i = n; i >= 1; --i)
    {
        int u = seq[i];
        g[u].sz = 1;
        for (int p = fir[u]; p; p = nxt[p])
            if (g[e[p]].inCir == 0 && g[u].pre != e[p])
                g[u].sz += g[e[p]].sz;
    }
}

int main()
{
  //  freopen("c.in", "r", stdin);
  // freopen("c.out", "w", stdout);
    int n;
    for (; scanf("%d", &n) != EOF; )
    {
        num = 0;
        for (int i = 0; i <= n; ++i)
            fir[i] = vis[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            scanf("%d", &x);
            link(i, x);
            link(x, i);
        }
        if (n <= 2)
        {
            printf("%d\n", n);
            continue;
        }
        ok = 0;
        for (int i = 1; i <= n; ++i)
            g[i].f = g[i].inCir = 0;
        cirVec.clear();
        dfsCircle(1, 0, 1);

        int m = cirVec.size();
        for (int i = 0; i < m; ++i)
            cirVec.push_back(cirVec[i]);

        getBfsSeq(n);
        int ans = 1;
        for (int i = 2; i <= n; ++i)
            if (n % i == 0)
            {
               ans += check(i, n);
               //for (int j = 1; j <= n; ++j);
            }
        printf("%d\n", ans);
    }
    return 0;
}
