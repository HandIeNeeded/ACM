#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e4 + 5;

vector<int> edge[N];
int n;
int a[N], b[N], p[N], q[N];

bool cmp(int i, int j) {
    return max(a[i], b[i] + a[j]) < max(a[j], b[j] + a[i]);
}

void dfs(int x, int fa) {
    vector<int> tmp;
    for (auto &y: edge[x]) {
        if (y != fa) {
            dfs(y, x);
            tmp.push_back(y);
        }
    }
    sort(tmp.begin(), tmp.end(), cmp);
    if (tmp.size() == 0) {
        a[x] = p[x], b[x] = p[x] - q[x];
    }
    else {
        int mx = p[x], tot = p[x] - q[x];
        for (auto &y: tmp) {
            mx = max(mx, tot + a[y]);
            tot += b[y];
        }
        a[x] = mx, b[x] = tot;
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    REPP(i, 1, n) {
        scanf("%d %d", p + i, q + i);
    }
    REPP(i, 1, n - 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, 0);
    //REPP(i, 1, n) {
    //    cout << a[i] << ' ' << b[i] << endl;
    //}
    printf("%d\n", a[1]);

    return 0;
}

