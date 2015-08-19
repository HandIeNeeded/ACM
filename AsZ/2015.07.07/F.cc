#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e7 + 5;
int vis[N], p[N], tot, cnt[N];

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i, cnt[i] = 1;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			cnt[i * p[j]] = cnt[i] + 1;
			if (i % p[j] == 0) break;
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	prime();
	freopen("funny.in", "r", stdin);
	freopen("funny.out", "w", stdout);
	int w, h;
	while (scanf("%d%d", &w, &h), w | h) {
		printf("%d %d - %s\n", w, h, cnt[w] > cnt[h] ? "Vera" : "Harry");
	}

	return 0;
}
