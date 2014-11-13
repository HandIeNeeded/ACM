const LL BASE = 1000000000;//1e9

struct BigInteger {
	vector<LL> a;
	
	BigInteger () {}
	BigInteger (LL x) { Init(x); }
	
	void Init(LL x) {
		a.clear();
		if (x == 0) {
			a.push_back(0);
			return ;
		}
		while (x) {
			a.push_back(x % BASE);
			x /= BASE;
		}
	}

	BigInteger operator + (const BigInteger &b) const {
		LL m = max(SZ(a), SZ(b.a)) + 1;
		BigInteger c;
		c.a.resize(m);//全0，注意不能c(m)这样写，因为这样是把c初始化成m
		LL st = 0, tmp, aa, bb;

		REP(i, m) {
			if (i >= SZ(a)) aa = 0;
			else aa = a[i];
			if (i >= SZ(b.a)) bb = 0;
			else bb = b.a[i];
			tmp = aa + bb + st;
			if (tmp >= BASE) st = 1, tmp -= BASE;
			else st = 0;
			c.a[i] = tmp;
		}
		while (SZ(c.a) > 1 && c.a.back() == 0) c.a.pop_back();
		return c;
	}

	BigInteger operator * (const BigInteger &b) const {
		BigInteger c; 
		c.a.resize(SZ(a) + SZ(b.a)); //max digit a+b 全0
		LL st = 0, tmp;
		REP(i, SZ(a)) {
			REP(j, SZ(b.a)) {
				tmp = a[i] * b.a[j] + c.a[i + j] + st; //tmp < base^2
				c.a[i + j] = tmp % BASE;
				st = tmp / BASE; //st < base
			}
			c.a[i + SZ(b.a)] = st, st = 0;
		}
		while (SZ(c.a) > 1 && c.a.back() == 0) c.a.pop_back(); 
		return c;
	}

	BigInteger operator / (const LL &n) const { //n != 0
		BigInteger b;
		b.a.resize(SZ(a));
		LL st = 0, tmp;
		for (int i = SZ(a) - 1, j = 0; i >= 0; --i, j++) {
			tmp = st * BASE + a[i];
			b.a[j] = tmp / n;
			st = tmp % n;
		}
		reverse(ALL(b.a));
		while (SZ(b.a) > 1 && b.a.back() == 0) b.a.pop_back();
		return b;
	}
	//除法（除单精）很容易改写成 %，上面的st就是结果。
};

void output(const BigInteger &num) {
	printf("%lld", num.a.back()); //最前面没有前导0，后面都是有前导零的。
	int n = SZ(num.a) - 1;
	while (n) {
		n--;
		printf("%09lld", num.a[n]);
	}
	putchar('\n');
}
