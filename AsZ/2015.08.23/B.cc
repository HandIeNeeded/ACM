#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;
const int MO = 1e9 + 7;

int vis[N], p[N], tot;
int mul[N] = {0, 1};

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
}

int fac[N], inv[N], ans[N];

void init() {
    prime();
    REP(i, tot) {
        mul[p[i]] = p[i];
        int now = p[i];
        if (now > 1000) continue;
        while (now * p[i] <= int(1e6 + 5)) {
            now *= p[i];
            mul[now] = p[i];
        }
    }
    ans[1] = 1;
    REPP(i, 2, N - 1) {
        if (mul[i] == 0) mul[i] = 1;
        ans[i] = 1LL * ans[i - 1] * mul[i] % MO;
    }
	fac[0] = inv[0] = inv[1] = 1;
	REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
	REPP(i, 2, N - 1) inv[i] = MO - 1LL * MO / i * inv[MO % i] % MO;
}

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif

    init();
    int t;
    scanf("%d", &t);    
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", 1LL * ans[n + 1] * inv[n + 1] % MO);
    }


    return 0;
}

