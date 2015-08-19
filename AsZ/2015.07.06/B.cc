#include <bits/stdc++.h>

#define LL unsigned long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

LL k;
int n, ans[N];

void shift(int l, int r) {
	int tmp = ans[r];
	for (int i = r; i > l; i--) {
		ans[i] = ans[i - 1];
	}
	ans[l] = tmp;
}

void solve(int pos, LL k) {
	if (pos > n) return ;
	int now = min(n - pos - 1, 63), cnt = 0;
	LL sum = 0;
	while (now >= 0 && k >= (1LL << now) + sum) {
		sum += 1LL << now;
		now--, cnt++;
	}
	shift(pos, pos + cnt);
	k -= sum;
	solve(pos + cnt + 1, k);
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);
	while (cin >> n >> k, n) {
		k--;
		REPP(i, 1, n) ans[i] = i;
		solve(1, k);
		REPP(i, 1, n) {
			cout << ans[i] << " \n"[i == n];
		}
	}
	return 0;
}
