#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 1e4 + 5;
const int LOG = 10;//2 * 3 * ... * 29 = 6469693230

int factor[LOG], cnt[LOG];
LL pw[LOG];
LL Mod[LOG], a[LOG];
int ql, qr, qd, MO, n, q, tot, phi;
int p[N * 10], vis[N * 10], num;

void prime() {
    for (int i = 2; i < 100000; i++) {
        if (!vis[i]) p[num++] = i;
        for (int j = 0; j < num && i * p[j] < 100000; j++) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

void exgcd( LL a, LL b, LL &x, LL &y){
    if (!b) x = 1, y = 0;
    else exgcd(b, a % b, y, x), y -= (a / b) * x;
}

LL china (LL n, LL *a, LL *mod){// i = 0, 1, ... , n - 1
    LL re = 0, M = 1;
    REP(i, n) M *= mod[i];
    REP(i, n) {
        LL x, y;
        exgcd(M / mod[i], mod[i], x, y);
        re = (re + M / mod[i] * x * a[i]) % M; //be careful overflow
    }
    return (re + M) % M;
}

void getFactor() {
    int tmp = MO;
    phi = MO;
    tot = 0;
    for (int i = 0; i < num && p[i] * p[i] <= tmp; i++) {
        if (tmp % p[i] == 0) {
            cnt[tot] = 0;
            phi = phi / p[i] * (p[i] - 1);
            Mod[tot] = 1;
            while (tmp % p[i] == 0) cnt[tot]++, tmp /= p[i], Mod[tot] *= p[i];
            factor[tot++] = p[i];
        }
    }
    if (tmp > 1) cnt[tot] = 1, Mod[tot] = tmp, factor[tot++] = tmp, phi = phi / tmp * (tmp - 1);
}

int pow_mod(int a, LL b, int mod = MO) {
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

struct Tree{
    LL cnt[N << 2], flag[N << 2];

    void build(int x, int l, int r) {
        if (l == r) {
            cnt[x] = flag[x] = 0;
        }
        else {
            build(LC), build(RC);
            cnt[x] = flag[x] = 0;
        }
    }

    void push(int x, int l, int r) {
        cnt[L] += flag[x] * (MID - l + 1), cnt[R] += flag[x] * (r - MID);
        flag[L] += flag[x], flag[R] += flag[x];
        flag[x] = 0;
    }

    void update(int x, int l, int r) {
        if (ql <= l && qr >= r) {
            cnt[x] += 1LL * qd * (r - l + 1);
            flag[x] += qd;
        }
        else {
            if (flag[x]) push(x, l, r);
            if (ql <= MID) update(LC);
            if (qr > MID) update(RC);
            cnt[x] = cnt[L] + cnt[R];
        }
    }

    LL query(int x, int l, int r) {
        if (ql <= l && qr >= r) {
            return cnt[x];
        }
        else {
            if (flag[x]) push(x, l, r);
            LL ans = 0;
            if (ql <= MID) ans += query(LC);
            if (qr > MID) ans += query(RC);
            assert(ans >= 0);
            return ans;
        }
    }
}t[LOG];

struct Segment{
    int mul[N << 2], flag[N << 2];

    void build(int x, int l, int r) {
        if (l == r) {
            mul[x] = flag[x] = 1;
        }
        else {
            build(LC), build(RC);
            mul[x] = flag[x] = 1;
        }
    }

    void push(int x, int l, int r) {
        mul[L] = 1LL * mul[L] * pow_mod(flag[x], MID - l + 1) % MO;
        flag[L] = 1LL * flag[L] * flag[x] % MO;
        mul[R] = 1LL * mul[R] * pow_mod(flag[x], r - MID) % MO;
        flag[R] = 1LL * flag[R] * flag[x] % MO;
        flag[x] = 1;
    }

    void update(int x, int l, int r) {
        if (ql <= l && qr >= r) {
            mul[x] = 1LL * mul[x] * pow_mod(qd, r - l + 1) % MO;
            flag[x] = 1LL * flag[x] * qd % MO;
        }
        else {
            if (flag[x] != 1) push(x, l, r);
            if (ql <= MID) update(LC);
            if (qr > MID) update(RC);
            mul[x] = 1LL * mul[L] * mul[R] % MO;
        }
    }

    int query(int x, int l, int r) {
        if (ql <= l && qr >= r) {
            return mul[x];
        }
        else {
            if (flag[x] != 1) push(x, l, r);
            int ans = 1;
            if (ql <= MID) ans = 1LL * ans * query(LC) % MO;
            if (qr > MID) ans = 1LL * ans * query(RC) % MO;
            return ans;
        }
    }
}nouse;

int Inv(int x) {
    return pow_mod(x, phi - 1);
}

void update(int num, int type) {
    REP(i, tot) {
        int cnt = 0;
        while (num % factor[i] == 0) {
            cnt++;
            num /= factor[i];
        }
        qd = cnt;
        if (cnt) {
            if (!type) qd = -qd;
            t[i].update(1, 1, n);
        }
    }
    if (num > 1) {
        if (type) {
            qd = num;
        }
        else {
            qd = Inv(num);
        }
        nouse.update(1, 1, n);
    }
}

int query() {
    REP(i, tot) {
        pw[i] = t[i].query(1, 1, n);
        //if (pw[i] < 0) {
        //    cout << 1 / 0 << endl;
        //}
    }
    REP(i, tot) {
        if (pw[i] >= cnt[i]) a[i] = 0;
        else {
            int mod = pow_mod(factor[i], cnt[i] - pw[i]);
            a[i] = 1;
            REP(j, tot) if (j != i) {
                a[i] = 1LL * a[i] * pow_mod(factor[j], pw[j], mod) % mod;
            }
            a[i] *= pow_mod(factor[i], pw[i]);
        }
    }
    //REP(i, tot) {
    //    cout << i << ' ' << a[i] << ' ' << Mod[i] << endl;
    //}
    int ans = china(tot, a, Mod);
    return 1LL * ans * nouse.query(1, 1, n) % MO;
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
    //clock_t st = clock();
#endif
    prime();

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &MO);
        getFactor();
        REP(i, tot + 1) ::t[i].build(1, 1, n);
        nouse.build(1, 1, n);
        REPP(i, 1, n) {
            int x;
            scanf("%d", &x);
            if (x == 0) {
                ::t[tot].update(1, 1, n);
                continue;
            }
            ql = i, qr = i;
            REP(j, tot) {
                int cnt = 0;
                while (x % factor[j] == 0) {
                    cnt++;
                    x /= factor[j];
                }
                if (cnt) {
                    qd = cnt;
                    ::t[j].update(1, 1, n);
                }
            }
            if (x > 1) {
                qd = x;
                nouse.update(1, 1, n);
            }
        }
        //cout << ::t[0].cnt[1] << endl;
        //cout << nouse.mul[1] << endl;
        scanf("%d", &q);
        printf("Case #%d:\n", ca++);
        while (q--) {
            char s[3];
            scanf("%s%d%d", s, &ql, &qr);
            if (s[0] == 'Q') {
                if (::t[tot].query(1, 1, n)) {
                    puts("0");
                    continue;
                }
                printf("%d\n", query());
            }
            else {
                int type = s[0] == 'M';
                int x;
                scanf("%d", &x);
                if (x == 0) {
                    ::t[tot].update(1, 1, n);
                    continue;
                }
                update(x, type);
            }
        }
    }
#ifdef HOME
    //cout << fixed << setprecision(10) << 1.0 * (clock() - st) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
//pw is LL
//a[i] can be 0 which leads to tle when you try to get the factor of 0

