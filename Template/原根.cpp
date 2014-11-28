const int N = 1000005;
bool vis[N];
int p[N], tot;

void GetPrime() {
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; ++j) {
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

struct Root{
	int g, fac, flag;
	bool check(int n) {//check n has root or not
		if (n == 2 || n == 4) return 1;
		if (n % 4 == 0) return 0;

		if (n % 2 == 0) n >>= 1;

		for (int i = 0; p[i] * p[i] <= n; ++i) {
			if (n % p[i] == 0) {
				fac = p[i];
				while (n % p[i] == 0) n /= p[i];
				if (n > 1) return 0;
				else return 1;
			}
		}
		fac = n;
		return 1;
	}

	LL qp(LL a, LL b, LL MOD) {
		LL re = 1;
		while (b) {
			if (b & 1) re = re * a % MOD;
			b >>= 1;
			a = a * a % MOD;
		}
		return re;
	}

	int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

	int f[40], num[40], cnt;

	bool dfs(int dep, int now, int g, int MOD, int phi) {
		if (dep == cnt) {
			if (now == phi) return 0;
			if (qp(g, now, MOD) == 1) return 1;
			return 0;
		}
		else {
			REP(i, num[dep] + 1) {
				if (dfs(dep + 1, now, g, MOD, phi)) return 1;
				now *= f[dep];
			}
			return 0;
		}
	}

	bool Test(int g, int MOD, int phi) {
		if (qp(g, phi, MOD) != 1) return 0;
		else if (flag) return !dfs(0, 1, g, MOD, phi);
		else {
			flag = 1;
			cnt = 0;
			int tmp = phi;
			for (int i = 0; p[i] * p[i] <= tmp; ++i) {
				if (tmp % p[i] == 0) {
					f[cnt] = p[i], num[cnt] = 0;
					while (tmp % p[i] == 0) cnt[num]++, tmp /= p[i];
					cnt++;
				}
			}
			if (tmp > 1) {
				f[cnt] = tmp, num[cnt++] = 1;
			}
			return !dfs(0, 1, g, MOD, phi);
		}
	}

	int get() {
		do {
			g = rand() % 1201 * (rand() % 1201) + 10;
		} while (!Test(g, n, phi));
		return g;
	}
}R;
