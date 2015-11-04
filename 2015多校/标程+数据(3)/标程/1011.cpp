#include <bits/stdc++.h>
using namespace std;
const int N = 110;
vector<int> E[N];
int in[N], son[N];
bool vis[N];
void dfs(int u)
{
    vis[u] = true;
    son[u] = 1;
    for(int v: E[u]) {
        dfs(v);
        son[u] += son[v];
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, k, a, b;
    while(scanf("%d%d", &n, &k) == 2) {
        memset(vis, false, sizeof(vis));
        memset(in, 0, sizeof(in));
        for(int i = 0; i < n; i++) {
            E[i].clear();
        }
        for(int i = 1; i < n; i++) {
            scanf("%d%d", &a, &b);
            assert(1 <= a && a <= n);
            assert(1 <= b && b <= n);
            a--; b--;
            E[a].push_back(b);
            in[b]++;
        }
        int root = -1;
        for(int i = 0; i < n; i++) if(!in[i]) {
            root = i;
        }
        assert(root == 0);
        dfs(root);
        for(int i = 0 ; i < n; i++) if(!vis[i]) {
            while(1);
        }
        int ret = 0;
        for(int i = 0; i < n; i++) if(son[i] - 1 == k) {
            ret ++;
        }
        printf("%d\n", ret);
    }
    return 0;
}
