#include <bits/stdc++.h>
#define N 20
#define MAXN (1 << 17)

using namespace std;

int a[N], b[N], c[N];
int INF;
int term[MAXN], dp[MAXN], vis[MAXN];

int check(int n, int m, int x) {
    for (int i = 0; i < n; ++i) {
        c[i] = x % 2;
        x >>= 1;
    }
    int p = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        for (; j + 1 < n && (c[j + 1] == c[j]); ++j);
        int len = j - i + 1;
        if (len != b[p]) return -1;
        ++p, i = j;
    }
    if (p == m) return 0;
    else return -1;
}

deque <int> deq;

int bfs(int s, int n, int m) {
    dp[s] = 0;
    if (term[s] == 0) return 0;
    deq.push_back(s);
    vis[s] = 1;
    for (; !deq.empty(); ) {
        int u = deq.front();
        deq.pop_front();
        for (int i = 0; i < n - 1; ++i) {
            int x = (u & (1 << i));
            int y = (u & (1 << (i + 1)));
            int v = u - x - y + x * 2 + y / 2;
            if (term[v] == 0) return dp[u] + 1;
            if (!vis[v]) {
                deq.push_back(v);
                vis[v] = 1;
                dp[v] = dp[u] + 1;
            }
        }
    }
}

int main() {
#ifdef HOME
freopen("in.txt", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    int sta = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sta += a[i] << i;
    }
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    int lim = 1 << n;
    memset(term, -1, sizeof(term));
    memset(dp, 0x3f, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < lim; ++i)
        term[i] = check(n, m, i);
    printf("%d\n", bfs(sta, n, m));
    return 0;
}

