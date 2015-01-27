#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 1e7 + 5;

int p[N], vis[N], tot;

void prime() {
	for (int i = 2; i < N; i ++) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
}

int fac[100], cnt[100], num;
LL ans;

void dfs(int dep, int minn) {
	if (dep == num) {
		if (minn == 100) return ;
		ans += minn;
	}
	else {
		REP(i, cnt[dep] + 1) {
			if (i == 0) {
				dfs(dep + 1, minn);
			}
			else {
				dfs(dep + 1, min(minn, cnt[dep] / i));
			}
		}
	}
}

int main() {
	LL n;
	prime();
	while (cin >> n, n) {
		LL tmp = n;
		num = 0;
		for (int i = 0; i < tot && 1LL * p[i] * p[i] <= tmp; i++) {
			if (tmp % p[i] == 0) {
				fac[num] = p[i];
				cnt[num] = 0;
				while (tmp % p[i] == 0) {
					cnt[num]++;
					tmp /= p[i];
				}
				num++;
			}
		}
		if (tmp > 1) {
			fac[num] = tmp;
			cnt[num++] = 1;
		}
		ans = 0;
		dfs(0, 100);
		cout << n << ' ' << ans << endl;
	}

	return 0;
}

