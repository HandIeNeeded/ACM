#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 500;
const int M = 10000;
int ne[M], fi[N], en[M], edge;

void add(int x, int y) {
    ne[++edge] = fi[x], fi[x] = edge, en[edge] = y;
}

int a[M], b[M];
bool ban[M], vis[N];

bool dfs(int x) {
    vis[x] = 1;
    for (int go = fi[x]; go; go = ne[go]) if (!ban[go]) {
        int y = en[go];
        if (!vis[y]) {
            dfs(y);
        }
    }
}

pair<int, int> solve(int id) {
    ban[2 * id] = ban[2 * id - 1] = 1;
    REPP(i, 1, n) {
        REPP(j, i + 1, n) {

            
        }
    }


}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) fi[i] = 0;
        edge = 0;
        REPP(i, 1, m) {
            scanf("%d%d", a + i, b + i);
            add(a[i], b[i]);
            add(b[i], a[i]);
        }
        REPP(i, 1, m) {
            pair<int, int> ans = solve(i);
            int x, y;
            tie(x, y) = ans;
            printf("%d %d\n", x, y);
        }
    }


    return 0;
}

