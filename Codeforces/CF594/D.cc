#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define LB(x) ((x) & (-(x)))

using namespace std;
const int N = 1e6 + 5;
const int MO = 1e9 + 7;
int a[N], b[N];
int p[N], vis[N], tot;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

int fac[N], inv[N];

void init() {
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    REPP(i, 2, N - 1) {
        fac[i] = 1LL * fac[i - 1] * i % MO;
        inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
    }
}

int tmp[N];
pair<int, int> q[N];

bool cmp(int i, int j) {
    return q[i].second < q[j].second || (q[i].second == q[j].second && q[i].first < q[j].first);
}

int pos[N];

int get(int p) {
    return 1LL * (p - 1) * inv[p] % MO;
}

int getInv(int p) {
    return 1LL * p * inv[p - 1] % MO;
}

int mul[N];

void update(int x, int d) {
    while (x < N) {
        mul[x] = 1LL * mul[x] * d % MO;
        x += LB(x);
    }
}

int query(int x) {
    int ans = 1;
    while (x) {
        ans = 1LL * ans * mul[x] % MO;
        x -= LB(x);
    }
    return ans;
}

void add(int x, int now) {
    for (int i = 0; i < tot && p[i] * p[i] <= x; i++) {
        if (x % p[i] == 0) {
            while (x % p[i] == 0) x /= p[i];
            int lastpos = pos[p[i]];
            if (lastpos) {
                update(lastpos, getInv(p[i]));
            }
            update(now, get(p[i]));
            pos[p[i]] = now;
        }
    }
    if (x > 1) {
        int lastpos = pos[x];
        if (lastpos) {
            update(lastpos, getInv(x));
        }
        update(now, get(x));
        pos[x] = now;
    }
}

int prefix[N] = {1};

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

int getAns(int l, int r) {
    return 1LL * prefix[r] * pow_mod(prefix[l - 1], MO - 2) % MO;
}

int query(int l, int r) {
    return 1LL * query(r) * pow_mod(query(l - 1), MO - 2) % MO;
}

int ans[N];

int main() {

    prime();
    init();
    int n;
    scanf("%d", &n);
    REPP(i, 1, n) scanf("%d", a + i);
    int Q;
    scanf("%d", &Q);
    REP(i, Q) {
        int x, y;
        scanf("%d%d", &x, &y);
        q[i] = {x, y};
    }
    REP(i, Q) tmp[i] = i;
    sort(tmp, tmp + Q, cmp);
    REP(i, N) mul[i] = 1;
    REPP(i, 1, n) prefix[i] = 1LL * prefix[i - 1] * a[i] % MO;
    //REPP(i, 1, 5) {
    //    cout << i << ' ' << p[i] << ' ' << inv[i] << ' ' << prefix[i] << endl;
    //}
    int now = 1;
    REP(ii, Q) {
        int i = tmp[ii];
        //cout << i << ' ' << "hehe" << endl;
        int L, R;
        tie(L, R) = q[i];
        while (now <= R) {
            add(a[now], now);
            now++;
        }
        ans[i] = 1LL * getAns(L, R) * query(L, R) % MO;
    }
    REP(i, Q) {
        printf("%d\n", ans[i]);
    }

    return 0;
} 
