#include <bits/stdc++.h>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e4 + 5;
int p[N], cnt[N], vis[N], tot;

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
	int n;
	cin >> n;
	int ans = 0;
	REPP(i, 1, n) ans = max(ans, cnt[i] + 1);
	cout << ans << endl;
	REPP(i, 1, n) {
		cout << cnt[i] + 1 << " \n"[i == n];
	}

    return 0;
}

