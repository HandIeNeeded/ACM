#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 30005;

LL sqr(int x) {return 1LL * x * x;}

struct point{
	int x, y;

	point (int _x = 0, int _y = 0) :x(_x), y(_y) {}

	LL len2() {
		return sqr(x) + sqr(y);
	}

	void in() {
		cin >> x >> y;
	}

	void print() {
		cout << x << ' ' << y << endl;
	}

	int dim() const {
		return x < 0 || x == 0 && y < 0;
	}
};

point operator + (const point &a, const point &b) {
	return point(a.x + b.x, a.y + b.y);
}

point operator - (const point &a, const point &b) {
	return point(a.x - b.x, a.y - b.y);
}

LL det(const point &a, const point &b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool byAng(const point &a, const point &b) {
	if (a.dim() == b.dim()) {
		return det(a, b) < 0;
	}
	else {
		return a.dim() < b.dim();
	}
}

int n;
point p[N << 1], sum[N << 1];
LL ans;

LL cal(int l, int r) {
	return (sum[r] - sum[l - 1]).len2();
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("cf.in", "r", stdin);

	cin >> n;
	REPP(i, 1, n) {
		p[i].in();
	}
	sort(p + 1, p + n + 1, byAng);
	// REPP(i, 1, n) {
	// 	p[i].print();
	// }
	REPP(i, 1, n) p[i + n] = p[i];
	REPP(i, 1, 2 * n) {
		sum[i] = sum[i - 1] + p[i];
	}
	ans = 0;
	int r = 1;
	REPP(l, 1, n) {
		ans = max(ans, cal(l, r));
		while (r + 1 < l + n && det(p[r + 1], p[l]) >= 0) {
			r++;
			ans = max(ans, cal(l, r));
		}
	}
	cout << ans << endl;

	return 0;
}