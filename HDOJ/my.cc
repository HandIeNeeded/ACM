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
        r[n++] = -1, r[n] = -3;
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
    freopen("tmp.in", "r", stdin);
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
        for (int i = 1; i < M.n; i += 2) {
            for (int j = i + p[i] - 1; j - i > ans; j -= 2) {
                if (p[j] >= j - i) {
                    ans = j - i;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", ca++, ans / 2 * 3);
    }
    return 0;

}
