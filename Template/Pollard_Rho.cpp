void add(LL &x, LL y, LL MO) {
	x += y;
	if (x >= MO) x -= MO;
}

LL mul_mod(LL a, LL b, LL MO) {
	a %= MO;
	LL re = 0;
	while (b) {
		if (b & 1) add(re, a, MO);
		b >>= 1;
		add(a, a, MO);
	}
	return re;
}

LL pow_mod(LL a, LL b, LL MO) {
	LL re = 1;
	while (b) {
		if (b & 1) re = mul_mod(re, a, MO);
		b >>= 1;
		a = mul_mod(a, a, MO);
	}
	return re;
}

bool test(LL n, LL b) {
	LL m = n - 1, cnt = 0;
	while (~m & 1) {
		m >>= 1;
		cnt++;
	}
	LL ans = qp(b, m, n);
	if (ans == 1 || ans == n - 1) return 1;
	cnt--;
	while (cnt >= 0) {
		ans = mul_mod(ans, ans, n);
		if (ans == n - 1) return 1;
		cnt--;
	}
	return 0;
}

const int BASE[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool isPrime(LL n) {
	if (n < 2) return 0;
	if (n < 4) return 1;
	if (n == 3215031751LL) return 0;
	for (int i = 0; i < 12 && BASE[i] < n; ++i) {
		if (!test(n, BASE[i])) return 0;
	}
	return 1;
}

LL gcd(LL x, LL y) {return y ? gcd(y, x % y) : x;}

vector<LL> fac;

LL Pollard_Rho(LL n, LL seed) {
	LL x, y, st = 1, ed = 2;
	x = y = rand() % (n - 1) + 1;
	while (1) {
		x = mul_mod(x, x, n);
		add(x, seed, n);
		if (x == y) return n;
		LL d = gcd(abs(x - y), n);
		if (1 < d && d < n) return d;
		st++;
		if (st == ed) {
			y = x;
			ed <<= 1;
		}
	}
}

void factorize(LL n) {
	if (n > 1) {
		if (isPrime(n)) fac.push_back(n);
		else {
			LL d = n;
			while (d >= n) {
				d = Pollard_Rho(n, rand() % (n - 1) + 1);
			}
			factorize(n / d);
			factorize(d);
		}
	}
}
