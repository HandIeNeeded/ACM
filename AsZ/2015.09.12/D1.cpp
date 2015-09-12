#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 405;
const int K = 55;

int dp[N][K];
int L[N], R[N], prefix[N];

int calc(int x) {
    return x * (x + 1) >> 1;
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        REPP(i, 1, n) {
            scanf("%d%d", L + i, R + i);
        }
        REPP(i, 1, n) {
            REPP(j, 0, k) {
                dp[i][j] = 0;
            }
        }
        REPP(i, 1, n) {
            prefix[i] = prefix[i - 1] + L[i] - R[i - 1] - 1;
        }
        REPP(i, 1, n) {
            REPP(t, 0, k) {
                int need = 0;
                int use = min(L[i] - R[i - 1] - 1, t);
                REP(s, use + 1) {
                    dp[i][t] = max(dp[i][t], dp[i - 1][t - s] + calc(R[i] - L[i] + 1 + s));
                }
                for (int j = i - 1; j >= 1; j--) {
                    need += L[j + 1] - R[j] - 1;
                    if (need > t) {
                        break;
                    }
                    int left = t - need;
                    int use = min(L[j] - R[j - 1] - 1, left);
                    REP(s, use + 1) {
                        dp[i][t] = max(dp[i][t], dp[j - 1][t - need - s] + calc(R[i] - L[j] + 1 + s));
                    }
                }

                need = 0;
                for (int j = i - 1; j >= 1; j--) {
                    if (j != i - 1) need += L[j + 1] - R[j] - 1;
                    if (need > t) {
                        break;
                    }
                    int left = t - need;
                    int use = min(L[j] - R[j - 1] - 1 + L[i] - R[i - 1] - 1, left);
                    REP(s, use + 1) {
                        dp[i][t] = max(dp[i][t], dp[j - 1][t - need - s] + calc(R[i - 1] - L[j] + 1 + s) + calc(R[i] - L[i] + 1));
                    }
                }
            }
        }
        int ans = 0;
        REPP(i, 0, k) ans = max(ans, dp[n][i]);
        printf("%d\n", ans);
    }

    return 0;
}

