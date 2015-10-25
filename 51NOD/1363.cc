#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 7;
int sum[N], ans[N];

int in() {
    char c;
    while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
    bool flag = (c == '-');
    if (flag) c = getchar();
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - 48;
        c = getchar();
    }
    return flag ? -x : x;
}

void out(int x) { //int
    if (x < 0) putchar('-'), x = -x;
    int len = 0, bit[10]; // LL  -> bit[20]
    while (x) {
        bit[len++] = x % 10;
        x /= 10;
    }
    if (!len) bit[len++] = 0;
    while (len--) putchar(bit[len] + 48);
    putchar('\n');
}

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

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    //REPP(i, 1, 50) {
    //    REPP(j, 1, i) {
    //        if (__gcd(j, i) == 1) {
    //            sum[i] += j;
    //        }
    //    }
    //    REPP(j, 1, i) {
    //        if (i % j == 0) {
    //            ans[i] += sum[j];
    //        }
    //    }
    //    cout << i << ' ' << sum[i] << ' ' << ans[i] << endl;
    //}


    prime();

    int t = in();
    while (t--) {
        int n = in();
        int res = (MO + 1) >> 1, ans = 1;
        res = 1LL * n * res % MO;
        for (int i = 0; i < tot && p[i] * p[i] <= n; i++) {
            if (n % p[i] == 0) {
                int sqr = p[i] * p[i];
                int now = p[i] * (p[i] - 1LL) % MO, tmp = 1 + now;
                n /= p[i];
                while (n % p[i] == 0) {
                    now = 1LL * now * sqr % MO;
                    add(tmp, now);
                    n /= p[i];
                }
                //cout << tmp << endl;
                ans = 1LL * ans * tmp % MO;
            }
        }
        if (n > 1) {
            ans = 1LL * ans * (1 + n * (n - 1LL) % MO) % MO;
        }
        add(ans, 1);
        out(1LL * res * ans % MO);
    }

    return 0;
}
