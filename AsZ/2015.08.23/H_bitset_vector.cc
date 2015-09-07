#include <cstdio>
#include <bitset>
#include <vector>
#include <iostream>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

const int N = 2e4 + 5;
const int M = 1e5 + 5;
const int step = 64;
const int MO = 63;
vector<LL> from[N], to[N];
vector<int> edge[N], inv[N];
int in[N], out[N];
int a[M], b[M];
bool vis[N];

void set(vector<LL> &a, int pos) {
    a[pos / step] |= 1LL << (pos & MO);
}

void Or(vector<LL> &a, const vector<LL> &b) {
    REP(i, a.size()) a[i] |= b[i];
}

vector<LL> And(const vector<LL> &a, const vector<LL> &b) {
    vector<LL> c(a);
    REP(i, c.size()) c[i] &= b[i];
    return c;
}

int Count(const vector<LL> &a) {
    int ans = 0;
    REP(i, a.size()) {
        ans += __builtin_popcountll(a[i]);
    }
    return ans;
}

void dfs(int x) {
    set(from[x], x), vis[x] = 1;
    for(auto &y: edge[x]) {
        if (!vis[y]) dfs(y);
        Or(from[x], from[y]);
    }
}

void go(int x) {
    set(to[x], x), vis[x] = 0;
    for (auto &y: inv[x]) {
        if (vis[y]) go(y);
        Or(to[x], to[y]);
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
        REP(i, n) {
            from[i].clear(), to[i].clear();
            from[i].assign((n + MO) / step, 0), to[i].assign((n + MO) / step, 0);
            edge[i].clear(), inv[i].clear();
            in[i] = out[i] = 0;
        }
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            edge[x].push_back(y);
            inv[y].push_back(x);
            a[i] = x, b[i] = y;
            in[y]++, out[x]++;
        }
        REP(i, n) if (in[i] == 0) {
            dfs(i);
        }
        REP(i, n) if (out[i] == 0) {
            go(i);
        }
        int ans = 0;
        REPP(i, 1, m) {
            if (Count(And(from[a[i]], to[b[i]])) > 2) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

