#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

int pow_mod(int a, int b, int p) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % p;
		a = 1LL * a * a % p;
		b >>= 1;
	}
	return ans;
}

const int N = 10005;
int p[N], tot;
pair<int, int> ans[N * 100];
int tmp[N * 100];
bool vis[N];

void exgcd(int a, int b, LL &d, LL &x, LL &y) {
	if (!b) d = a, x = 1, y = 0;
	else {
		exgcd(b, a % b, d, y, x);
		y -= (a / b) * x;
	}
}

void init() {
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) {
			p[tot++] = i;
		}
		for (int j = 0; j < tot && i * p[j] < N; ++j) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) {
				break;
			}
		}
	}
}

struct prime_root{
	int n, g, phi;
	int f[40], cnt;

	prime_root(int num) {
		n = num;
		phi = n - 1;
		g = get();
	}

	void getphi() {
		cnt = 0;
		int tmp = phi;
		for (int i = 0; p[i] * p[i] <= tmp; ++i) {
			if (tmp % p[i] == 0) {
				f[cnt] = p[i];
				while (tmp % p[i] == 0) tmp /= p[i];
				cnt++;
			}
		}
		if (tmp > 1) {
			f[cnt++] = tmp;
		}
	}

	bool test(int g, int phi) {
		if (pow_mod(g, phi, n) != 1) return 0;
		REP(i, cnt) {
			if (pow_mod(g, phi / f[i], n) == 1) return 0;
		}
		return 1;
	}

	int get() {
		getphi();
		do {
			g = rand() % (n - 1) + 1;
		} while (!test(g, phi));
		return g;
	}
};

int query[N << 1];
int m, inv, limit;

void prepare(int g, int p) {
	m = (int) min(1000000, p);
	limit = p / m + 1;
	inv = pow_mod(pow_mod(g, m, p), p - 2, p);
	int now = 1;
	ans[0] = make_pair(1, 0);
	for (int i = 1; i < m; i ++) {
		now = 1LL * now * g % p;
		ans[i] = make_pair(now, i);
	}
	sort(ans, ans + m);
	REP(i, m) tmp[i] = ans[i].first;
}

int log_mod(int a, int p) {
	for (int i = 0; i < limit; i ++) {
		int pos = lower_bound(tmp, tmp + m, a) - tmp;
		if (ans[pos].first == a) {
			return i * m + ans[pos].second;
		}
		a = 1LL * a * inv % p;
	}
	return -1;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("alot.in", "r", stdin);
	freopen("alot.out", "w", stdout);
	srand(time(0) % clock());

	int p, q;
	init();
	cin >> p >> q;
	int g = prime_root(p).g;
	
	prepare(g, p);
	REP(i, q) {
		int x, y;
		cin >> x >> y;
		if (y == 0) {
			if (x == 0) {
				cout << 1 << endl;
			}
			else {
				cout << -1 << endl;
			}
			continue;
		}
		if (y == 1) {
			cout << 0 << endl;
			continue;
		}
		if (x == 0) {
			cout << -1 << endl;
			continue;
		}
		x = log_mod(x, p), y = log_mod(y, p);
		int mod = p - 1;
		LL d, a, b;
		exgcd(x, mod, d, a, b);
		if (y % d) {
			cout << -1 << endl;
			continue;
		}
		else {
			int y0 = y / d;
			a *= y0, b *= y0;
			mod /= d;
			a %= mod;
			if (a < 0) a += mod;
			cout << a << endl;
		}
	}
	return 0;
}

