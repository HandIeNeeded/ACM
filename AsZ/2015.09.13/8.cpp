#include <bits/stdc++.h>

#define N 1010

using namespace std;

int a[N], p[N];
int fa[N], dir[N];

void dfs(int f, int d, int l, int r)
{
    fa[l] = f;
    dir[l] = d;
    int i = l + 1;
    while (i <= r && a[i] < a[l])
        i++;
    if (i > l + 1)
        dfs(l, 0, l + 1, i - 1);
    if (i <= r)
        dfs(l, 1, i, r);
}

int main()
{
    //freopen("8.in", "r", stdin);
    int ttt;
    scanf("%d", &ttt);
    while (ttt--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            p[a[i]] = i;
        }
        dfs(-1, 0, 0, n - 1);
//        for (int i = 0; i < n; i++)
//            printf("%d%c", fa[i], " \n"[i == n - 1]);
        int Q;
        scanf("%d", &Q);
        for (int q = 0; q < Q; q++)
        {
            int x;
            scanf("%d", &x);
            int now = p[x];
            vector<char> way;
            while (fa[now] != -1)
            {
                way.push_back(dir[now] ? 'W' : 'E');
                now = fa[now];
            }
            for (int i = way.size() - 1; i >= 0; i--)
                printf("%c", way[i]);
            printf("\n");
        }
    }
    return 0;
}
