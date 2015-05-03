#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#pragma comment(linker, "/STACK:102400000,102400000")

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

#define N 100100
#define M 300300

using namespace std;

int line[M * 2], pre[M * 2];
bool treeEdge[M * 2];
int en[N], fa[N], col[N], cnt[N];
bool vis[N];
int tot;

void ins(int x, int y)
{
    line[++tot] = y;
    pre[tot] = en[x];
    en[x] = tot;
}

void dfs(int x, int colo, int acc)
{
    vis[x] = true;
    fa[x] = acc;
    col[x] = colo;
    int i = en[x];
    while (i)
    {
        int y = line[i];
        if (!vis[y])
        {
            treeEdge[i] = 1;
            treeEdge[i ^ 1] = 1;
            dfs(y, colo ^ 1, acc);
        }
        i = pre[i];
    }
}

int main() {
    ios :: sync_with_stdio(0);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        tot = 1;
        memset(en, 0, sizeof(en));
        memset(pre, 0, sizeof(pre));
        memset(treeEdge, 0, sizeof(treeEdge));

        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            x--, y--;
            ins(x, y), ins(y, x);
        }

        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(i, 0, i);

        bool oddCyc = false;
        bool evenCyc = false;
        memset(cnt, 0, sizeof(cnt));
        for (int u = 0; u < n && (!evenCyc || !oddCyc); u++)
        {
            int i = en[u];
            while (i && (!evenCyc || !oddCyc))
            {
                int v = line[i];
                if (!treeEdge[i])
                {
                    if (col[u] != col[v])
                        evenCyc = true;
                    else
                    {
                        oddCyc = true;
                        cnt[fa[u]]++;
                    }
                    treeEdge[i] = true;
                    treeEdge[i ^ 1] = true;
                }
                i = pre[i];
            }
        }

        for (int i = 0; i < n && !evenCyc; i++)
            if (cnt[i] > 1)
                evenCyc = true;

        if (oddCyc)
            printf("YES\n");
        else
            printf("NO\n");

        if (evenCyc)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
