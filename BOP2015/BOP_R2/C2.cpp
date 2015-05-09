#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define LL long long
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 1e5 + 5;

struct BIT {
    int s[N];
    void modify(int p,int x) {
        for (int i = p; i < N; i += LB(i)) s[i] += x;
    }
    int query(int p) {
        int ans = 0;
        for (int i = p; i > 0; i -= LB(i)) ans += s[i];
        return ans;
    }
}bit[16];

const LL INF = (LL) 1LL << 60;
int a[N], n, K;
LL cnt[16][1 << 16], dp[1 << 16];

void toMax(LL &a,LL b) {
    if (a > b) a = b;
}

LL go() {
    REP(i, K) {
		MST(bit[i].s, 0);
    }
	MST(cnt, 0);
   	REPP(i, 1, n) {
        REP(j, K) {
            if (a[i] == j) continue;
            cnt[a[i]][1 << j] += bit[j].query(i);
        }
        bit[a[i]].modify(i,1);
    }
    REP(i, K) {
        REP(j, K) {
            for (int mask = 0; mask < (1 << K); ++ mask) {
                if (mask >> j & 1) {
                    cnt[i][mask] += cnt[i][mask ^ 1 << j];
                }
            }
        }
    }
    REP(i, (1 << K)) {
        dp[i] = INF;
    }
    dp[(1 << K) - 1] = 0;
    for (int mask = (1 << K) - 1; mask > 0; -- mask) {
        for (int i = 0; i < K; ++ i) {
            if (!(mask >> i & 1)) continue;
            toMax(dp[mask ^ 1 << i],dp[mask] + cnt[i][mask]);
        }
    }
    return dp[0];
}

int main() {
    int t, ca = 1;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n, &K);
        REPP(i, 1, n) {
            scanf("%d", a + i);
            a[i]--;
        }
        printf("Case #%d: %lld\n", ca++, go());
    }
	return 0;
}
