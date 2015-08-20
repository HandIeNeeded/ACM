#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
vector<int> edge[N];
int son[N], in[N];

void dfs(int x, int p = 0) {
    REP(i, edge[x].size()) {
        int y = edge[x][i];
        if (y != p) {
            dfs(y, x);
            son[x] += son[y];
        }
    }
    son[x]++;
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) > 0) {
        MST(in, 0), MST(son, 0);
        REPP(i, 1, n) edge[i].clear();
        REPP(i, 1, n - 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            edge[x].push_back(y);
            in[y]++;
        }
        int root = -1;
        REPP(i, 1, n) {
            if (in[i] == 0) {
                root = i;
            }
        }
        assert(root >= 0);
        dfs(root);
        int ans = 0;
        REPP(i, 1, n) {
            if (son[i] == m + 1) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

