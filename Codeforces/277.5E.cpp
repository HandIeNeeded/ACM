#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
double dp[N];
int a[N], b[N], l, n, tot;
int p[N], pre[N];

bool check(double x) {
	dp[0] = 0;
	REPP(i, 1, n) dp[i] = 1e100;
	REPP(i, 1, n) {
		REPP(j, 0, i - 1) {
			if (dp[j] + sqrt(fabs(a[i] - a[j] - l)) < dp[i]) {
				dp[i] = dp[j] + sqrt(fabs(a[i] - a[j] - l));
				pre[i]  =j;
			}
		}
		dp[i] -= x * b[i];
	}
	int tmp = n;
	tot = 0;
	while (tmp) {
		p[tot++] = tmp;
		tmp = pre[tmp];
	}
	reverse(p, p + tot);
	return dp[n] <= 0;
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("cf.in", "r", stdin);

	cin >> n >> l;
	REPP(i, 1, n) cin >> a[i] >> b[i];
	double l = 0.0, r = 1e4;
	REP(cnt, 100) {
		double mid = (l + r) / 2.0;
		if (check(mid)) r = mid;
		else l = mid;
	}
	check(l);
	REP(i, tot) {
		cout << p[i] << " \n"[i == tot - 1];
	}

	return 0;
}