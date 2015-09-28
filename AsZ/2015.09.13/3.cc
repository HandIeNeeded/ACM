#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LB(x) ((x) & (-(x)))

using namespace std;

const int MO = 1e9 + 7;
const int upper = 438744;
const int N = upper + 5;

LL cnt[N] = {0, 1, 3};
int has[N] = {0, 1, 2};
int s[N];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int calc(LL start, int length) {
    start %= MO;
    return (start + start + length - 1) * length / 2 % MO;
}

void init() {
    REPP(i, 3, N - 1) {
        has[i] = lower_bound(cnt + 1, cnt + i, i) - cnt; //how many numbers appear i times
        cnt[i] = cnt[i - 1] + has[i]; //how many numbers appear no more than i times
        if (cnt[i] > MO) break;
    }
    REPP(i, 1, upper) {
        s[i] = s[i - 1];
        add(s[i], 1LL * calc(cnt[i - 1] + 1, has[i]) * i % MO);
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    init();
    //REPP(i, 1, 20) {
    //    cout << i << ' ' << has[i] << ' ' << cnt[i] << ' ' << s[i] << endl;
    //}
    int t;

    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int pos = lower_bound(cnt + 1, cnt + upper, n) - cnt;
        int ans = s[pos - 1];
        add(ans, 1LL * calc(cnt[pos - 1] + 1, n - cnt[pos - 1]) * pos % MO);
        printf("%d\n", ans);
    }

    return 0;
}
