#define LL long long

const int N = 1e5 + 5;

int vis[N], p[N], tot;
LL prefix[N];

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
	REPP(i, 1, N - 1) {
		prefix[i] = prefix[i - 1];
		if (!vis[i]) prefix[i] += i;
	}
}

LL dp[N];

LL getsum(int n, int p) {
	if (dp[p] >= 0) return dp[p];
	else if (p == 1) return dp[1] = 1LL * (n + 2) * (n - 1);
	else if (vis[p]) return dp[p] = getsum(n, p - 1);
	else if (1LL * p * p > n) return dp[p] = getsum(n, p - 1);
	else {
		dp[p] = getsum(n, p - 1);
		dp[p] -= (getsum(n / p, p - 1) - prefix[p]) * p;
		return dp[p];
	}
}
