#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;

struct Manacher{
    int p[N << 1], n;
    char r[N << 1];

    void init(char *s) {
        n = 0, r[n++] = '$';
        while (*s) {
            r[n++] = '#', r[n++] = *s++;
        }
        r[n++] = '#', r[n] = 0;
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

char s[N];

int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    while (scanf("%s", s) > 0) {
        M.init(s), M.get();
        int ans = 0;
        REP(i, M.n) ans = max(ans, M.p[i] - 1);
        printf("%d\n", ans);
    }

    return 0;
}

