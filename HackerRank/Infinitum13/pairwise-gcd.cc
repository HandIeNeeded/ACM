#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
const int N = 1e5 + 5;
const LL MO = 1234567891;

int b[205], cnt[N];
LL f[N];

void add(LL &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

LL calc(int x) {
    return 1LL * x * (x - 1) / 2 % MO;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    REPP(i, 1, n) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    REPP(i, 0, m) scanf("%d", b + i);
    REPP(i, 0, m) {
        b[i] %= MO;
        if (b[i] < 0) b[i] += MO;
    }
    for (int i = 1; i < N; i++) {
        for (int j = i + i; j < N; j += i) {
            cnt[i] += cnt[j];
        }
    }
    for (int i = N - 1; i >= 1; i--) {
        f[i] = calc(cnt[i]);
        for (int j = i + i; j < N; j += i) {
            add(f[i], MO - f[j]);
        }
    }
    LL ans = 0;
    REPP(i, 1, N - 1) if (f[i]) {
        LL tmp = 0, now = 1;
        REPP(j, 0, m) {
            add(tmp, 1LL * b[j] * now % MO);
            now = 1LL * i * now % MO;
        }
        tmp = 1LL * f[i] * tmp % MO;
        add(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}


