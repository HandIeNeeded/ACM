#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int K = 6;
const int N = 6 * 6 * 6 * 6 * 6 * 6 + 5;
const int L = 115;
const int inf = 0x3f3f3f3f;

int dp[N];
char s[L], r[L], tmp[L];
char target[N][K];

void init() {
    REP(i, N - 5) {
        int tmp = i;
        for (int j = K - 1; j >= 0; j--) {
            target[i][j] = tmp % K + '1';
            tmp /= K;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    const int start = 1865;
    int state = start;
    queue<int> q;
    q.push(state), q.push(63), dp[state] = 0;
    while (q.size()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        //cout << x << ' ' << y << endl;
        REP(j, K) if (y & (1 << j)) {
            REP(k, K) if (k != j) {
                int z = y;
                z ^= (1 << j), z |= (1 << k);
                int bit[K];
                int tmp = x;
                for (int d = K - 1; d >= 0; d--) {
                    bit[d] = tmp % K;
                    tmp /= K;
                }
                REP(d, K) if (bit[d] == j) bit[d] = k;
                tmp = 0;
                REP(d, K) tmp = tmp * K + bit[d];
                if (dp[tmp] == inf) {
                    dp[tmp] = dp[x] + 1;
                    q.push(tmp), q.push(z);
                }
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
    clock_t st = clock();
#endif
    init();
    while (scanf("%s%s", s, r) > 0) {
        swap(s, r);
        int n = strlen(s);
        int state = 0;
        REP(i, n) state |= (1 << (s[i] - '1'));
        memcpy(tmp, s, sizeof(s));
        int ans = n;
        REP(i, N - 5) if (dp[i] < inf) {
            int bit[K];
            int x = i;
            for (int d = K - 1; d >= 0; d--) {
                bit[d] = x % K;
                x /= K;
            }
            int bad = 0;
            REP(d, K) if (!(state & (1 << d))) {
                if (bit[d] != d) {
                    bad = 1;
                    break;
                }
            }
            if (bad) continue;
            int cost = dp[i];
            REP(j, n) {
                s[j] = target[i][s[j] - '1'];
                cost += s[j] != r[j];
            }
            ans = min(ans, cost);
            memcpy(s, tmp, sizeof(tmp));
        }
        printf("%d\n", ans);
    }
    //cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
