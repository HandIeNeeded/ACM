#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 205;
int now;
set<int> ans[N];
vector<int> g[N][N], f[N][N];

void getUnion(int x, int y) {
    auto a = ans[x].begin(), b = ans[y].begin();
    while (a != ans[x].end() && b != ans[y].end()) {
        while (a != ans[x].end() && *a < *b) a++;
        if (a == ans[x].end()) break;
        while (b != ans[y].end() && *b < *a) b++;
        if (b == ans[y].end()) break;
        if (*a == *b) {
            f[x][y].push_back(*a);
            b++;
        }
    }
}

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    REPP(i, 1, (n - 1) * n / 2) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x > y) swap(x, y);
        REP(i, z) {
            int t;
            scanf("%d", &t);
            ans[x].insert(t);
            ans[y].insert(t);
            g[x][y].push_back(t);
        }
    }
    REPP(i, 1, n) {
        REPP(j, i + 1, n) {
            getUnion(i, j);
            sort(g[i][j].begin(), g[i][j].end());
            if (f[i][j] != g[i][j]) {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    REPP(i, 1, n) {
        printf("%d", int(ans[i].size()));
        for(auto &x: ans[i]) {
            printf(" %d", x);
        }
        puts("");
    }
    return 0;
}


