#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e6 + 5;

int p[N], vis[N], phi[N] = {0, 1}, tot;

void prime() {
	for (int i = 2; i < N; i ++) {
		if (!vis[i]) {
			p[tot++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
			else {
				phi[i * p[j]] = phi[i] * (p[j] - 1);
			}
		}
	}
}

long long sum[N], num[N];
int cnt;

void init() {
	prime();
	REPP(i, 1, N) {
		if (1LL * i * (i + 1) > (long long) 2e12) {
			break;
		}
		else {
			num[i] = 1LL * i * (i + 1) >> 1;
			if (i & 1) {
				sum[i] = 1LL * phi[i] * phi[(i + 1) >> 1];
			}
			else {
				sum[i] = 1LL * phi[i >> 1] * phi[i + 1];
			}
			cnt = i;
		}
	}
	REPP(i, 1, cnt) {
		sum[i] += sum[i - 1];
	}
}

int main() {
	ios :: sync_with_stdio(0);
	init();
	int t;
	cin >> t;
	while (t--) {
		long long l, r;
		cin >> l >> r;
		l = lower_bound(num + 1, num + cnt + 1, l) - num;
		r = upper_bound(num + 1, num + cnt + 1, r) - num;
		cout << sum[r - 1] - sum[l - 1] << endl;
	}

	return 0;
}
