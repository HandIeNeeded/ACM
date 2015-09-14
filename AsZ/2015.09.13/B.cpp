#include <bits/stdc++.h>
#define MAXN 11234
#define MAXM 212345

using namespace std;

typedef int arrayN[MAXN], arrayM[MAXM];

arrayN fir, vis, deg, rem, val;
arrayM nxt, e;
int cnt;

int num;
void link(int u, int v)
{
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num; deg[v]++;
}

long long dfs(int x)
{
    vis[x] = 1;
    cnt++;
    long long tmp = val[x];
    for (int p = fir[x]; p; p = nxt[p])
        if (!vis[e[p]])
        {
            tmp += dfs(e[p]);
        }
    return tmp;
}

int main()
{
    int T;
   //freopen("in.txt", "r", stdin);
    for (scanf("%d", &T); T; --T)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        num = 0;
        for (int i = 1; i <= n; ++i)
        {
            fir[i] = 0;
            deg[i] = 0;
            vis[i] = 0;
            rem[i] = 0;
        }

        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &val[i]);
        }
        for (int i = 1; i <= m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u == v) continue;
            link(u, v);
            link(v, u);
        }
        vector <int> vec;
        for (int i = 1; i <= n; ++i)
        {
            if (deg[i] <= 1)
            {
                vec.push_back(i);
                vis[i] = 1;
            }
        }
        for ( ; !vec.empty(); )
        {
            int u = vec.back();
            vec.pop_back();
            rem[u] = 1;
            for (int p = fir[u]; p; p = nxt[p])
            {
                deg[e[p]]--;
                if (deg[e[p]] <= 1 && !vis[e[p]])
                {
                    vec.push_back(e[p]);
                    vis[e[p]] = 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            vis[i] = rem[i];
        long long ans = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
            {
                cnt = 0;
                long long tmp = dfs(i);
                if (cnt & 1) ans += tmp;
            }
        cout << ans << endl;
    }
    return 0;
}
