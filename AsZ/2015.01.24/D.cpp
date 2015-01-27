#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int up = 1e7 + 1;
const int down = -1;

void exgcd(int a, int b, int &d, int &x, int &y) {
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a % b, d, y, x), y -= (a / b) * x;
}

bool check(int x) {
	return x > down && x < up;
}

int solve(int p, int q) {
	int x, y, d;
	exgcd(abs(p), abs(q), d, x, y);
	if (p < 0) x = -x;
	if (q < 0) y = -y;
	pair<int, int> a, b, c;
	a.first = (-x + down) / q, a.second = (up - x) / q;
	if (q < 0) swap(a.first, a.second);
	b.first = (y - up) / p, b.second = (down - y) / p;
	if (p < 0) swap(b.first, b.second); 
	c.first = max(a.first, b.first),  c.second = min(a.second, b.second);
	int l, r;
	REPP(i, -5, 5) {
		int t = c.first + i;
		if (check(x + q * t) && check(y - p * t)) {
			l = t;
			break;
		}
	}
	for (int i = 5; i >= -5; i--) {
		int t = c.second + i;
		if (check(x + q * t) && check(y - p * t)) {
			r = t;
			break;
		}
	}
	return r - l + 1;
}

int main() {
	ios :: sync_with_stdio(0);

	int n, m;
	while (cin >> n >> m, n | m) {
		if (n == 0 || m == 0) {
			cout << up << endl;
			continue;
		}
		int d, x, y;
		exgcd(n, m, d, x, y);
		int p = m / d, q = n / d;
		int ans = 0;
		ans += solve(-p, q);
		ans += solve(p, -q);
		cout << ans << endl;
	}

	return 0;
}

