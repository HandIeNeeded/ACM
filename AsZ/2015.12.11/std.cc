#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 50;
const int MO = 1e9 + 7;

LL bit[N];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int sqr(int x) {
    return x * x * x;
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REP(i, m) bit[i] = 0;
        REP(i, m) {
            int cnt;
            scanf("%d", &cnt);
            REP(j, cnt) {
                int x;
                scanf("%d", &x);
                x--;
                bit[i] |= 1LL << x;
            }
        }
        int ans = 0;
        REP(i, 1 << m) {
            LL now = 0;
            REP(j, m) if (i & (1 << j)) {
                now ^= bit[j];
            }
            add(ans, sqr(__builtin_popcountll(now)));
        }
        printf("Case #%d: %d\n", ca++, ans);
    }


    return 0;
}


