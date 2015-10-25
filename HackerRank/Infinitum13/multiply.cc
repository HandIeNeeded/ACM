#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int MO = 1e9 + 7;

const int N = 1e6 + 5;

int p[N], vis[N], tot;
int cnt[N], ans;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int pow_mod(int a, int b, int mod = MO) {
    a %= mod; 
    if (a < 0) a += mod;
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return ans;
}

int qx, qd, ql, qr;
int mul[N << 2];

void update(int x, int l, int r) {
    if (l == r) mul[x] = qd;
    else {
        if (qx <= MID) update(LC);
        else update(RC);
        mul[x] = 1LL * mul[L] * mul[R] % MO;
    }
}

int query(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return mul[x];
    }
    else {
        int a = 1, b = 1;
        if (ql <= MID) a = query(LC);
        if (qr > MID) b = query(RC);
        return 1LL * a * b % MO;
    }
}

void update(int x) {
    for (int i = 0; i < tot && p[i] * p[i] <= x; i++) {
        if (x % p[i] == 0) {
            while (x % p[i] == 0) {
                cnt[p[i]]++;
                x /= p[i];
            }
            qx = i + 1, qd = 1LL * (pow_mod(p[i], cnt[p[i]]) - 1) * pow_mod(p[i] - 1, MO - 2) % MO;
            update(1, 1, tot);
        }
    }
    if (x > 1) {
        cnt[x]++;
        qx = lower_bound(p, p + tot, x) - p + 1;
        qd = 1LL * (pow_mod(x, cnt[x]) - 1) * pow_mod(x - 1, MO - 2) % MO;
        update(1, 1, tot);
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    prime();

    int n, q;
    scanf("%d%d", &n, &q);
    fill(cnt, cnt + N, 1);
    fill(mul, mul + 4 * N, 1);
    update(n);
    while (q--) {
        int x;
        scanf("%d", &x);
        update(x);
        printf("%d\n", mul[1]);
    }
    return 0;
}


