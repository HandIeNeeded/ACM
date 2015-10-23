#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5e6 + 5;

int cnt[N];
int p[N], vis[N], tot;

void prime() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) p[tot++] = i, cnt[i] = 1;
        for (int j = 0; j < tot && i * p[j] < N; j++) {
            vis[i * p[j]] = p[j];
            cnt[i * p[j]] = cnt[i] + 1;
            if (i % p[j] == 0) break;
        }
    }
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

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    prime();
    REPP(i, 1, N - 1) cnt[i] += cnt[i - 1];
    int t = in();
    while (t--) {
        int a, b;
        a = in(), b = in();
        out(cnt[a] - cnt[b]);
        //printf("%d\n", cnt[a] - cnt[b]);
    }


    return 0;
}


