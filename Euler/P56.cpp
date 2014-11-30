#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const LL BASE = 1e9;

struct BigInteger {
	vector<LL> v; //v
	
	BigInteger () {}
	BigInteger (LL x) { Init(x); }
	
	void Init(LL x) {
		v.clear();
		if (x == 0) {
			v.push_back(0);
			return ;
		}
		while (x) {
			v.push_back(x % BASE);
			x /= BASE;
		}
	}

	BigInteger operator + (const BigInteger &b) const {
		LL m = max(v.size(), b.v.size()) + 1;
		BigInteger c;
		c.v.resize(m);//0c(m)cm
		LL st = 0, tmp, aa, bb;

		REP(i, m) {
			if (i >= v.size()) aa = 0;
			else aa = v[i];
			if (i >= b.v.size()) bb = 0;
			else bb = b.v[i];
			tmp = aa + bb + st;
			if (tmp >= BASE) st = 1, tmp -= BASE;
			else st = 0;
			c.v[i] = tmp;
		}
		while (c.v.size() > 1 && c.v.back() == 0) c.v.pop_back();
		return c;
	}

	BigInteger operator * (const BigInteger &b) const {
		BigInteger c; 
		c.v.resize(v.size() + b.v.size()); //max digit a+b 0
		LL st = 0, tmp;
		REP(i, v.size()) {
			REP(j, b.v.size()) {
				tmp = v[i] * b.v[j] + c.v[i + j] + st; //tmp < base^2
				c.v[i + j] = tmp % BASE;
				st = tmp / BASE; //st < base
			}
			c.v[i + b.v.size()] = st, st = 0;
		}
		while (c.v.size() > 1 && c.v.back() == 0) c.v.pop_back(); 
		return c;
	}

	BigInteger operator / (const LL &n) const { //n != 0
		if (n == 0) {
			cout << "Error!" << endl;
			return 0;
		}

		BigInteger b;
		b.v.resize(v.size());
		LL st = 0, tmp;
		for (int i = v.size() - 1, j = 0; i >= 0; --i, j++) {
			tmp = st * BASE + v[i];
			b.v[j] = tmp / n;
			st = tmp % n;
		}
		reverse(b.v.begin(), b.v.end());
		while (b.v.size() > 1 && b.v.back() == 0) b.v.pop_back();
		return b;
	}

	LL operator % (const LL &n) const { //n != 0
		if (n == 0) {
			cout << "Error!" << endl;
			return 0;
		}

		LL st = 0, tmp;
		for (int i = v.size() - 1, j = 0; i >= 0; --i, j++) {
			tmp = st * BASE + v[i];
			st = tmp % n;
		}
		return st;
	}
};

void output(const BigInteger &num) {
	cout << num.v.back(); //0
	int n = num.v.size() - 1;
	while (n) {
		cout << setw(9) << setfill('0') << num.v[n--]; //cout
	}
	cout << endl;
}

BigInteger qp(BigInteger a, LL b) {
	BigInteger ans(1);
	while (b) {
		if (b & 1) {
			ans = ans * a;
		}
		b >>= 1;
		a = a * a;
	}
	return ans;
}


int getnum(LL x) {
	int ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
} 

int getdigit(const BigInteger &a) {
	int ans = 0;
	REP(i, a.v.size()) {
		ans += getnum(a.v[i]);
	}
	return ans;
}

BigInteger qp(BigInteger a, int b) {
	BigInteger ans(1);
	while (b) {
		if (b & 1) {
			ans = ans * a;
		}
		b >>= 1;
		a = a * a;
	}
	return ans;
}

int main() {
	//freopen("cf.in", "r", stdin);
	ios :: sync_with_stdio(0);

	int n;
	cin >> n;
	int ans = 1;

	REPP(i, 1, n) {
		REPP(j, 1, n) {
			BigInteger tmp(i);
			tmp = qp(tmp, j);
			if (getdigit(tmp) > ans) {
				//output(tmp);
				ans = getdigit(tmp);
			}
		}
	}
	cout << ans << endl;

	return 0;
}