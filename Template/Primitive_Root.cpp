//p^k, 2*p^k, 2, 4
int phi, p;

vector<int> fac;

int pow_mod(int x, int y, int mod) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % mod;
		y >>= 1;
		x = 1LL * x * x % mod;
	}
	return ans;
}

void getfac(int phi) {
	for (int i = 2; i * i <= phi; i ++) {
		if (phi % i == 0) {
			fac.push_back(i);
			while (phi % i == 0) {
				phi /= i;
			}
		}
	}
	if (phi > 1) fac.push_back(phi);
}

int primitive_root(int p) {
	REPP(g, 1, p - 1) {
		bool bad = 0;
		REP(i, fac.size()) {
			if (pow_mod(g, phi / fac[i], p) == 1) {
				bad = 1;
				break;
			}
		}
		if (!bad) return g;
	}
}
