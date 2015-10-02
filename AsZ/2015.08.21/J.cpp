#include <bits/stdc++.h>

#define N 1010
#define MOD 1000000007

using namespace std;

int line[N * 2], nex[N * 2], en[N];
int c[N][N], son[N], vis[N];
int f[N][N], ff[N];
int n, ca, tot;

inline int add(int x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
    return x;
}

inline int mul(int x, int y)
{
    int t = 1LL * x * y % MOD;
    return t;
}

void prepare()
{
    for (int i = 0; i < N; i++)
        c[i][0] = 1;
    for (int i = 0; i < N; i++)
        c[i][i] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 1; j < N - 1; j++)
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
}

void ins(int x, int y)
{
    line[++tot] = y;
    nex[tot] = en[x];
    en[x] = tot;
}

void dfs(int u)
{
    vis[u] = ca;
    son[u] = 0;
    for (int i = 0; i <= n; i++)
        f[u][i] = 0;
    f[u][0] = 1;

    int i = en[u];
    bool flag = true;
    while (i)
    {
        int v = line[i];
        if (vis[v] < ca)
        {
            dfs(v);
            int tmp = son[u];
            son[u] += son[v];
            for (int j = son[u]; j >= 0; j--)
            {
                f[u][j] = 0;
                for (int k = max(0, j - son[v]); k <= tmp; k++)
                    f[u][j] = add(f[u][j], mul(f[u][k], f[v][j - k]));
                f[u][j] = mul(f[u][j], c[son[u]][son[v]]);
            }
        }
        i = nex[i];
    }
    son[u]++;
    for (int i = son[u]; i > 0; i--)
    {
        f[u][i] = add(f[u][i], f[u][i - 1]);
        f[u][i - 1] = mul(f[u][i - 1], son[u] - 1);
    }
    f[u][0] = 0;
}

int main()
{

    prepare();

    ca = 1;
    int ttt;
    scanf("%d", &ttt);
    for (int tt = 1; tt <= ttt; tt++)
    {
        int k;
        scanf("%d %d", &n, &k);

        tot = 0;
        for (int i = 0; i < n; i++)
            en[i] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            x--, y--;
            ins(x, y);
            ins(y, x);
        }
        dfs(0);
        ca++;
//        for (int i = 0; i < n; i++)
//            for (int j = 0; j < n; j++)
//                printf("%d%c", f[i][j], " \n"[j == n - 1]);
        printf("Case #%d: %d\n", tt, f[0][k]);
    }
    return 0;
}
