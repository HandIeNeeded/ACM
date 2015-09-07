#include <cstdio>
#include <bitset>
#include <vector>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

const int N = 2e4 + 5;
const int M = 1e5 + 5;
bitset<20001> from[N], to[N];
vector<int> edge[N], inv[N];
int in[N], out[N];
int a[M], b[M];
bool vis[N];

void dfs(int x) {
    from[x][x] = vis[x] = 1;
    for(auto &y: edge[x]) {
        if (!vis[y]) dfs(y);
        from[x] |= from[y];
    }
}

void go(int x) {
    to[x][x] = 1, vis[x] = 0;
    for (auto &y: inv[x]) {
        if (vis[y]) go(y);
        to[x] |= to[y];
    }
}

int main() {
#ifdef HOME
    freopen("H.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) from[i].reset(), to[i].reset(), edge[i].clear(), in[i] = out[i] = 0;
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            edge[x].push_back(y);
            inv[y].push_back(x);
            a[i] = x, b[i] = y;
            in[y]++, out[x]++;
        }
        REPP(i, 1, n) if (in[i] == 0) {
            dfs(i);
        }
        REPP(i, 1, n) if (out[i] == 0) {
            go(i);
        }
        int ans = 0;
        REPP(i, 1, m) {
            if ((from[a[i]] & to[b[i]]).count() > 2) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

