#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 25;
int a[N], alive[N];
int now, pre, dir, n, c, cnt;

int next(int now) {
    if (dir > 0) {
        now++;
        if (now == n) now = 0;
    }
    else {
        now--;
        if (now == -1) now = n - 1;
    }
    return now;
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &c);
        REP(i, n) scanf("%d", a + i);
        pre = -1, now = 0;
        REP(i, n) alive[i] = 1;
        dir = 1, cnt = n;
        REP(turn, n + 5) {
            if (cnt == 0) break;
            if (!alive[now]) {
                now = next(now);
                turn--;
                continue;
            }
            else {
                pre = now;
                a[now] -= c;
                if (a[now] <= 0) {
                    dir *= -1;
                    cnt--;
                    alive[now] = 0;
                }
                now = next(now);
            }
        }
        printf("%d\n", pre + 1);
    }


    return 0;
}

