#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

struct Manacher{
    int p[N << 1], r[N << 1], n;

    void init(int *s, int num) {
        n = 0, r[n++] = -2;
        REPP(i, 1, num) {
            r[n++] = -1, r[n++] = s[i];
        }
        r[n++] = -1, r[n] = -2;
    }

    void get() {
        int id = 1, mx = 2;
        p[0] = p[1] = 1;
        REPP(i, 2, n - 1) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (r[i + p[i]] == r[i - p[i]]) p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
    }
}M;

int a[N];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REPP(i, 1, n) scanf("%d", a + i);
        M.init(a, n), M.get();
        int ans = 0;
        int *p = M.p;
        //REP(i, M.n) {
        //    cout << i << ' ' << p[i] << endl;
        //}
        for (int i = 1; i < n; i += 2) {
            if (p[i + p[i] - 1] >= p[i]) {
                ans = max(ans, (p[i] - 1) / 2 * 3);
            }
        }
        for (int i = n - 1; i >= 1; i -= 2) {
            if (p[i - p[i] + 1] >= p[i]) {
                ans = max(ans, (p[i] - 1) / 2 * 3);
            }
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;

}
