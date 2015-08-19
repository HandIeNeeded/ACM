#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-9;

double A, B, C, pos[N], sum[N];
pair<double, double> p[N];
pair<int, int> a[N];
int n;

int cmp(double x) {
	if (fabs(x) < eps) return 0;
	else if(x > 0) return 1;
	else return -1;
}

pair<double, double> calc(int i, int j) {
	if (a[i].second == a[j].second) {
		if (cmp(a[i].second - B) > 0 || cmp(a[i].second - A) < 0) {
			return {a[i].first, a[i].first};
		}
		else {
			return {a[i].first, a[j].first};
		}
	}
	else {
		double l = 1.0 * (a[i].first - a[j].first) / (a[i].second - a[j].second) * (A - a[j].second) + a[j].first;
		double r = 1.0 * (a[i].first - a[j].first) / (a[i].second - a[j].second) * (B - a[j].second) + a[j].first;
		if (a[i].second > a[j].second) {
			swap(l, r);
		}
		if (l < a[i].first) l = a[i].first;
		if (r > a[j].first) r = a[j].first;
		if (l > r) l = r = a[i].first;
		return {l, r};
	}
}

int main() {
	freopen("bayes.in", "r", stdin);
	freopen("bayes.out", "w", stdout);
    ios :: sync_with_stdio(0);
	while (scanf("%d", &n), n) {
		scanf("%lf%lf%lf", &A, &B, &C);
		REPP(i, 1, n + 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i] = {x, y};
		}
		REPP(i, 1, n) p[i] = calc(i, i + 1);
		REPP(i, 1, n) pos[i] = p[i].second, sum[i] = sum[i - 1] + p[i].second - p[i].first;
		p[n + 1] = {1e6, 1e6}, pos[n + 1] = 1e6;
		double L = sum[n] * C;
		double ans = 1e100;
		pair<double, double> res = {-1e100, 1e100};
		int right = 0;
		REPP(i, 1, n) {
			double l, r;
			while (right <= n && cmp(sum[right] - sum[i - 1] - L) < 0) right++;
			l = p[i].first;
			r = L - (sum[right - 1] - sum[i - 1]) + p[right].first;
			if (cmp(r - 1e6) > 0) break;
			if (cmp(r - l - ans) < 0) {
				ans = r - l;
				res = {p[i].first, p[i].first + ans};
			}
		}
		printf("%.12f %.12f\n", res.first, res.second);
	}
    return 0;
}
