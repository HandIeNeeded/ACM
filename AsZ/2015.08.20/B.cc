#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;

int vis[N], p[N], cnt[N], tot;

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i, cnt[i] = 1;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
            cnt[i * p[j]] = cnt[i] + 1;
			if (i % p[j] == 0) {
                cnt[i * p[j]]--;
                break;
            }
		}
	}
}

int use[10];
short have[10][N];
int mp[10][10];

void init() {
    prime();
    REP(i, 10) REP(j, 10) mp[i][j] = __gcd(i, j);
    REP(i, 10) {
        REPP(j, 1, N - 1) {
            have[i][j] = have[i][j - 1] + (cnt[j] == i);
        }
    }
}

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif
    init();
    int t;
    scanf("%d", &t);
    while(t--) {
        int l, r;
        scanf("%d%d", &l, &r);
        REP(i, 10) {
            use[i] = have[i][r] - have[i][l - 1];
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = i; j < 10; j++) {
                if (i == j) {
                    if (use[i] >= 2) {
                        ans = max(ans, i);
                    }
                }
                else {
                    if (use[i] >= 1 && use[j] >= 1) {
                        ans = max(ans, mp[i][j]);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

