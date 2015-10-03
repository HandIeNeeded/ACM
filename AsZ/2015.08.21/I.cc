#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int pow_mod(int a, int b, int mod) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return ans;
}

struct Root{
    //p^k, 2*p^k, 2, 4
    int phi, g, p;
    vector<int> fac;

    void getfac(int phi) {
        fac.clear();
        for (int i = 2; i * i <= phi; i ++) {
            if (phi % i == 0) {
                fac.push_back(i);
                while (phi % i == 0) {
                    phi /= i;
                }
            }
        }
        if (phi > 1) fac.push_back(phi);
    }

    int primitive_root(int x) {
        p = x, phi = p - 1, getfac(phi);
        REPP(i, 1, phi) {
            bool bad = 0;
            REP(j, fac.size()) {
                if (pow_mod(i, phi / fac[j], p) == 1) {
                    bad = 1;
                    break;
                }
            }
            if (!bad) return g = i;
        }
        return -1;
    }
}solver;

const int N = 4e4;
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

map<int, int> mp[20];
int step[20], cnt[20], inv[20];

void init(int q, const vector<int> &p, const vector<int> &g) {
    int n = p.size();
    REP(i, n) mp[i].clear();
    REP(i, n) {
        step[i] = int(sqrt(1.0 * p[i] * q + 0.5)) + 5;
        cnt[i] = p[i] / step[i] + 1;
        inv[i] = pow_mod(pow_mod(g[i], step[i], p[i]), p[i] - 2, p[i]);
        int now = 1;
        REP(j, step[i]) {
            if (!mp[i].count(now)) mp[i][now] = j;
            now = 1LL * now * g[i] % p[i];
        }
    }
}

void exgcd( LL a, LL b, LL &d, LL &x, LL &y){
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a % b, d, y, x), y -= (a / b) * x;
}

int get(int x, int p, int g, int id) {
    REP(i, cnt[id]) {
        if (mp[id].count(x)) return i * step[id] + mp[id][x];
        x = 1LL * x * inv[id] % p;
    }
    return -1;
}

int getPhi(int x) {
    int ans = 1;
    REP(i, tot) {
        if (p[i] * p[i] > x) break;
        if (x % p[i] == 0) {
            ans *= p[i] - 1;
            x /= p[i];
            while (x % p[i] == 0) {
                ans *= p[i];
                x /= p[i];
            }
        }
    }
    if (x > 1) {
        ans *= (x - 1);
    }
    return ans;
}

int solve(int x, int y, int p, int g, int id) {
    if (y == 1) return 0;
    if (p == 2) {
        return x == y ? 1 : -1;
    }
    int phi = p - 1;
    int a = get(x, p, g, id), b = get(y, p, g, id);
    int d = __gcd(a, phi);
    if (b % d) return -1;
    a /= d, b /= d, phi /= d;
    int tmp = getPhi(phi);
    return 1LL * pow_mod(a, tmp - 1, phi) * b % phi;
    //LL xx, yy, zz;
    //exgcd(a, phi, zz, xx, yy);
    //return xx * b % phi;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    prime();
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int sum, m;
        scanf("%d%d", &sum, &m);
        vector<int> fac, g;
        REP(i, tot) {
            if (p[i] * p[i] > sum) break;
            if (sum % p[i] == 0) {
                fac.push_back(p[i]);
                while (sum % p[i] == 0) sum /= p[i];
                g.push_back(solver.primitive_root(p[i]));
            }
        }
        if (sum > 1) {
            fac.push_back(sum);
            g.push_back(solver.primitive_root(sum));
        }
        init(m, fac, g);
        printf("Case #%d:\n", ca++);
        while (m--) {
            int ans = INT_MAX;
            int x, y;
            scanf("%d%d", &x, &y);
            REP(i, fac.size()) {
                int tmp = solve(x % fac[i], y % fac[i], fac[i], g[i], i);
                if (tmp >= 0) ans = min(ans, tmp);
            }
            if (ans == INT_MAX) ans = -1;
            printf("%d\n", ans);
        }
    }
    return 0;
}
