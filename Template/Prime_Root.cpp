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



//rng_58
//find root when N has a root
int g;
while(1){
	g = rand() % (N - 1) + 1;
	LL G = 1;
	for(i=1;;i++){
		G = G * g % N;
		if(G == 1) break;
	}
	if(i == N-1) break;
}