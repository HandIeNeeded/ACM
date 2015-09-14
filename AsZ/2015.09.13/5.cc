#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 20005;
const int M = 1e5 + 5;

struct Edge{
    int x, y, val;
}e[M];

int f[N], cnt[N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

pair<int, int> p[N];
int ans[N];

int calc(int x) {
     return x * (x - 1);
}

bool cmp(const Edge &a, const Edge &b) {
    return a.val < b.val;
}

int main() {
#ifdef HOME
    freopen("5.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        REPP(i, 1, n) f[i] = i, cnt[i] = 1;
        REPP(i, 1, m) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            e[i] = (Edge) {x, y, z};
        }
        REPP(i, 1, q) {
            int x;
            scanf("%d", &x);
            p[i] = {x, i};
        }
        sort(e + 1, e + m + 1, cmp);
        sort(p + 1, p + q + 1);
        int now = 1;
        int res = 0;
        REPP(i, 1, q) {
            int id = p[i].second;
            while (now <= m && e[now].val <= p[i].first) {
                int x = e[now].x, y = e[now].y;
                int tx = find(x), ty = find(y);
                if (tx != ty) {
                    res -= calc(cnt[tx]), res -= calc(cnt[ty]);
                    f[tx] = ty;
                    cnt[ty] += cnt[tx];
                    res += calc(cnt[ty]);
                }
                now++;
            }
            ans[id] = res;
        }
        REPP(i, 1, q) {
            printf("%d\n", ans[i]);
        }
    }


    return 0;
}

