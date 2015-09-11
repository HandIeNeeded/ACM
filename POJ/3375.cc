#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <climits>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
const int M = 1e5 + 5;

int dp[2][M], f[M];
int a[M], b[N];
int L[N], R[N];
int n, m;

void getRange(int x, int i) {
    int pos = lower_bound(a + 1, a + m + 1, x) - a;
    L[i] = max(1, pos - (n + 2));
    R[i] = min(m, pos + (n + 2));
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &m, &n);
    REPP(i, 1, m) {
        scanf("%d", a + i);
    }
    REPP(i, 1, n) {
        scanf("%d", b + i);
    }
    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);
    int cur = 0;
    getRange(b[1], 1);
    REPP(i, L[1], R[1]) {
        dp[cur][i] = abs(b[1] - a[i]);
    }
    f[L[1]] = dp[cur][L[1]];
    REPP(i, L[1] + 1, R[1]) f[i] = min(f[i - 1], dp[cur][i]);
    REPP(i, 2, n) {
        getRange(b[i], i);
        REPP(j, L[i], R[i]) {
            if (j == L[i] && L[i] == L[i - 1]) {
                dp[cur ^ 1][j] = 2e9;
                continue;
            }
            int tmp = j - 1;
            if (j - 1 > R[i - 1]) {
                tmp = R[i - 1];
            }
            dp[cur ^ 1][j] = f[tmp] + abs(a[j] - b[i]);
        }
        cur ^= 1;
        f[L[i]] = dp[cur][L[i]];
        REPP(j, L[i] + 1, R[i]) f[j] = min(f[j - 1], dp[cur][j]);
    }
    printf("%d\n", f[R[n]]);

    return 0;
}
