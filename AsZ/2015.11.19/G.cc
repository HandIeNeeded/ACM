#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define LB(x) ((x) & (-(x)))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int N = 2e5 + 6;

vector<int> pos[N];
int a[N], b[N], c[N], cnt[N], tot;

void add(int x, int d) {
    while (x < tot) {
        cnt[x] += d;
        x += LB(x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += cnt[x];
        x -= LB(x);
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        vector<int> num;
        int n, m;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            a[i] = x, b[i] = y, c[i] = z;
            num.push_back(x);
        }
        sort(ALL(num));
        num.resize(unique(ALL(num)) - num.begin());
        tot = num.size();
        REPP(i, 1, m) pos[i].clear(), pos[i].push_back(0);
        REPP(i, 1, n) {
            a[i] = lower_bound(ALL(num), a[i]) - num.begin() + 1;
            pos[c[i]].push_back(a[i]);
        }
        REPP(i, 1, m) sort(ALL(pos[i]));
        REPP(i, 1, m) pos[i].push_back(tot);
        int ans = 0;
        REPP(i, 1, m) {
            REPP(j, 1, pos[i].size() - 1) {
                int L = pos[i][j - 1], R = pos[i][j];
                ans = max(ans, query(R - 1) - query(L + 1));
            }
        }
        printf("%d\n", ans);
        REPP(i, 1, tot) cnt[i] = 0;
    }

    return 0;
}


