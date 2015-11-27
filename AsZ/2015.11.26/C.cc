#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(a) (a).begin(), (a).end()
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 1005;
const int MO = 1e9 + 7;

int dp[N][N], a[N];
int n, m;

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void update(int x, int y, int d) {
    while (x <= n) {
        add(dp[y][x], d);
        x += LB(x);
    }
}

int query(int x, int y) {
    int ans = 0;
    while (x) {
        add(ans, dp[y][x]);
        x -= LB(x);
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    //t = 10;
    while (t--) {
        scanf("%d%d", &n, &m);
        //n = m = 1000;
        vector<int> num;
        REPP(i, 1, n) scanf("%d", a + i), num.push_back(a[i]);
        //REPP(i, 1, n) a[i] = i;
        //num.clear();
        //REPP(i, 1, n) num.push_back(i);
        sort(ALL(num));
        num.resize(unique(ALL(num)) - num.begin());
        REPP(i, 1, n) a[i] = lower_bound(ALL(num), a[i]) - num.begin() + 1;
        REPP(i, 0, n) REPP(j, 0, n) dp[i][j] = 0;
        REPP(i, 1, n) {
            REPP(j, 1, i) {
                int now = query(a[i] - 1, j - 1);
                if (j == 1) now++;
                update(a[i], j, now);
            }
        }
        int ans = 0;
        ans = query(n, m);
        printf("Case #%d: %d\n", ca++, ans);
    }

    return 0;
}


