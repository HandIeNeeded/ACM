#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
int a[N];

#define LL long long

const LL BASE = 1e9;

struct BigInteger {
	vector<LL> v; //v中倒序存放数字
	
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
		c.v.resize(m);//全0，注意不能c(m)这样写，因为这样是把c初始化成m
		LL st = 0, tmp, aa, bb;

		REP(i, m) {
			if (i >= (int) v.size()) aa = 0;
			else aa = v[i];
			if (i >= (int) b.v.size()) bb = 0;
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
		c.v.resize(v.size() + b.v.size()); //max digit a+b 全0
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
	cout << num.v.back(); //最前面没有前导0，后面都是有前导零的
	int n = num.v.size() - 1;
	while (n) {
		cout << setw(9) << setfill('0') << num.v[--n]; //这里改变了cout对于固定宽度的输出的设置
	}
	cout << endl;
}

BigInteger pow(BigInteger a, LL b) {
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
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) cin >> a[i];
	int cnt = 0, sum = 0;
	bool bad = 0;
	REPP(i, 1, n) {
		if (a[i] >= 0) {
			if (a[i] == 0) {
				bad = 1;
				break;
			}
			sum += a[i];
			cnt++;
		}
	}
	if (cnt > n - 2 || sum > 2 * n - 2) bad = 1;
	if (bad) {
		cout << 0 << endl;
	}
	else {
		sum -= cnt;
		BigInteger ans(1);
		for (int i = n - 2; i > n - 2 - sum; i--) {
			ans = ans * i;
		}
		REPP(i, 1, n) {
			if (a[i] >= 0) {
				REPP(j, 1, a[i] - 1) {
					ans = ans / j;
				}
			}
		}
		REPP(i, 1, n - 2 - sum) ans = ans * (n - cnt);
		output(ans);
	}

	return 0;
}

