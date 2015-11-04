#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e6 + 6;
const int MO = 258280327;

int ans[N], f[N], pw[N], p[N], vis[N], tot;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i, pw[i] = 2;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) {
                pw[i * p[j]] = pw[i];
                break;
            }
            else {
                pw[i * p[j]] = (pw[i] << 1) % MO;
            }
        }
    }
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void init() {
    pw[1] = 1;
    REPP(i, 1, 1000000) {
        for (int j = i + i; j <= 1000000; j += i) {
            add(f[j], pw[j / i - 1]);
        }
        ans[i] = ans[i - 1];
        add(ans[i], 2 * i - 1);
        add(ans[i], MO - f[i - 1]);
    }
    REPP(i, 1, 1000000) {
        add(ans[i], ans[i - 1]);
    }
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    prime();
    init();

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }

    return 0;
}

