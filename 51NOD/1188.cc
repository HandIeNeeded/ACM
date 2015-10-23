#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5e6 + 5;

int p[N / 10], mul[N] = {0, 1}, tot;
bool vis[N];
LL g[N] = {0, 1}, sum[N] = {0, 1}, ans[N / 100];

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i, sum[i] = g[i] = 2 * i - 1, mul[i] = i;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            int tmp = i * p[j];
            vis[tmp] = p[j];
            if (i % p[j] == 0) {
                mul[tmp] = mul[i] * p[j];
                g[tmp] = g[mul[i]] * p[j] + mul[tmp] - mul[i];
                sum[tmp] = g[tmp] * sum[tmp / mul[tmp]];
                break;
            }
            else {
                mul[tmp] = p[j];
                g[tmp] = g[p[j]];
                sum[tmp] = g[tmp] * sum[i];
            }
        }
    }
}

int id[N / 100], a[N / 100];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

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

void out(LL x) { //int
    if (x < 0) putchar('-'), x = -x;
    int len = 0, bit[20]; // LL  -> bit[20]
    while (x) {
        bit[len++] = x % 10;
        x /= 10;
    }
    if (!len) bit[len++] = 0;
    while (len--) putchar(bit[len] + 48);
    putchar('\n');
}
int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int t;
    prime();
    t = in();
    //scanf("%d", &t);
    REP(i, t) {
        a[i] = in();
        //scanf("%d", a + i);
        id[i] = i;
    }
    sort(id, id + t, cmp);
    LL ans = 0;
    int now = 1;
    REP(ii, t) {
        int i = id[ii];
        while (now <= a[i]) {
            ans += sum[now++];
        }
        ::ans[i] = ans;
    }
    REP(i, t) {
        out(::ans[i] - (a[i] + 1LL) * a[i] / 2);
        //printf("%lld\n", ::ans[i] - (a[i] + 1LL) * a[i] / 2);
    }

    return 0;
}

