#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((x + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

#define next hehe

int next[N];

int cnt[N << 2];

int build(int x, int l, int r) {
    if (l == r) {
        cnt[x] = 1;
    }
    else {
        build(LC), build(RC);
        cnt[x] = cnt[L] + cnt[R];
    }
}

int ql, qr, qx, qd;

void update(int x, int l, int r) {
    if (l == r) {
        cnt[x] += qd;
    }
    else {
        if (qx <= MID) update(LC);
        else update(RC);
        cnt[x] = cnt[L] + cnt[R];
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        build(1, 1, n);
        REPP(i, 1, n) next[i] = i;
        REPP(i, 1, n) {

        }
    }



    return 0;
}
