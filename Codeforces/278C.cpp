#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b )  memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 100005;

int p[N], tot;
bool vis[N];

void Init() {
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

LL qp(LL a, LL b, LL MOD) {
	LL re = 1;
	a %= MOD;
	while (b) {
		if (b & 1) re = re * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return re;
}

struct Root{
	int n, g, fac, phi, good;
	//fac is the n's prime factor
	//phi is n's Euler function value
	//g is the prime root
	//good has root 1, not 0

	Root() {}
	Root(int num) {
		good = 0;
		if (check(num)) {
			good = 1, n = num;
			phi = n / fac * (fac - 1);
			g = get();
		}
	}

	//p^k, 2*p^k, 2, 4
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

	int f[40], cnt;//phi's prime factors

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


	bool Test(int g, int phi) {
		if (qp(g, phi, n) != 1) return 0;
		REP(i, cnt) {
			if (qp(g, phi / f[i], n) == 1) return 0;
		}
		return 1;
	}

	int get() {
		getphi();
		do {
			g = rand() % (n - 1) + 1;
		} while (!Test(g, phi));
		return g;
	}
}R;

int pw[N];

int main() {
	// freopen("cf.in", "r", stdin);
	// freopen("cf.out", "w", stdout);
	ios :: sync_with_stdio(0);

	//srand(time(0) % clock());

	int n;
	cin >> n;

	Init();
	if (n == 1) {
		cout << "YES" << endl;
		cout << 1 << endl;
	}
	else if (n == 2) {
		cout << "YES" << endl;
		cout << "1 2" << endl;
	}
	else if (n == 4) {
		cout << "YES" << endl;
		cout << "1 3 2 4" << endl;
	}
	else if (!vis[n]) {
		cout << "YES" << endl;
		int g = Root(n).g;
		pw[0] = 1;
		REPP(i, 1, n) pw[i] = pw[i - 1] * g % n;
		cout << 1 << endl;
		cout << g << endl;

		int a = n - 3, b = 3;
		REP(i, n - 3) {
			if (i & 1) {
				cout << pw[b] << endl;
				b += 2;
			}
			else {
				cout << pw[a] << endl;
				a -= 2;
			}
		}
		cout << n << endl;
	} 
	else {
		cout << "NO" << endl;
	}

	return 0;
}