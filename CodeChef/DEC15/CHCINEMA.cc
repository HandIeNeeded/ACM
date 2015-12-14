#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

LL a[4];

LL get(int n, int m) {
    vector<LL> tmp;
    LL sum = 0, tot = 1LL * n * m;
    REP(i, 4) {
        sum += a[i];
        sum = min(sum, tot);
        tmp.push_back(sum);
    }
    REP(i, 4) {
        a[i] = i == 0 ? a[i] : tmp[i] - tmp[i - 1];
    }
    REP(i, 4) {
        cout << i << ' ' << a[i] << endl;
    }
    LL ans = 0;
    ans += min(a[0], a[3]) * 2;
    return ans;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REP(i, 4) scanf("%lld", a + i);
        printf("%lld\n", get(n, m));
    }

    return 0;
}


