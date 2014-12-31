#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#define dou double
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define LL long long
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define RL(a) scanf("%I64d", &(a))
#define RLL(a, b) scanf("%I64d%I64d", &(a), &(b))
#define RLLL(a, b, c) scanf("%I64d%I64d%I64d", &(a), &(b), &(c)) 
#define PI(r) printf("%d\n", (r))
#define PL(r) printf("%I64d\n", (r))
#define RS(s) scanf("%s", (s))
#define SL(a) strlen(a)
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FOR(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
//Segment tree
#define MID ((l + r) >> 1)
#define L (x << 1)
#define R ((x << 1) | 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))
#pragma warning (disable : 4996)
#define EPS 1e-8
#define INF 2000000000
#define LIM (1ll << 60)
#define MOD 1000000007
#define N 111111

using namespace std;

int n, m;

const LL BASE = 1000000000;

struct bign {
	vector<LL> a;
	
	void init(LL x) {
		a.clear();
		if (x == 0) a.push_back(0);
		while (x) {
			a.push_back(x % BASE);
			x /= BASE;
		}
	}

	bign operator * (const bign& b) const {
		bign c;
		c.a.assign(a.size() + b.a.size(), 0);
		LL st = 0, tem;
		REP(i, a.size()) {
			REP(j, b.a.size()) {
				tem = a[i] * b.a[j] + c.a[i + j] + st;
				c.a[i + j] = tem % BASE;
				st = tem / BASE;
			}
			tem = i + b.a.size();
			while (st) c.a[tem] = st % BASE, st /= BASE;
		}
		while (c.a.back() == 0 && c.a.size() > 1) c.a.pop_back(); 
		return c;
	}

	bign operator / (const int& n) const {
		bign b;
		LL st = 0, tem;
		for (int i = a.size() - 1; i >= 0; --i) {
			tem = st * BASE + a[i];
			b.a.push_back(tem / n);
			st = tem % n;
		}
		reverse(b.a.begin(), b.a.end());
		while (b.a.back() == 0 && b.a.size() > 1) b.a.pop_back();
		return b;
	}

	bign operator + (const bign& b) const {
		bign c;
		LL m = min(a.size(), b.a.size()), st = 0, tem;
		REP(i, m) {
			tem = a[i] + b.a[i] + st;
			c.a.push_back(tem % BASE);
			st = tem / BASE;
		}
		if (a.size() < b.a.size()) {
			REPP(j, a.size(), b.a.size() - 1) {
				tem = st + b.a[j];
				st = tem / BASE;
				c.a.push_back(tem % BASE);
			}
		}
		else {
			REPP(j, b.a.size(), a.size() - 1){
				tem = a[j] + st;
				st = tem / BASE;
				c.a.push_back(tem % BASE);
			}
		}
		while (st) c.a.push_back(st % BASE), st /= BASE;
		return c;
	}
};

bign qp(bign a, int y) {
	bign re;
	re.init(1);
	while (y) {
		if (y & 1) re = re * a;
		y >>= 1;
		a = a * a;
	}
	return re;
}

//printf("%09lld", re.a[i]);

int euler(int x) {
	if (x == 1) return 1;
	int re = 1;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			int tmp = (i - 1);
			x /= i;
			while (x % i == 0) {
				tmp *= i;
				x /= i;
			}
			re *= tmp;
		}
	}
	if (x > 1) re *= (x - 1);
	return re;
}

int main(){
	int t, x, y, z, ca = 1;
	//freopen("D:/Contest/in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios :: sync_with_stdio(false);
	RI(n);
	bign re, two, tmp;
	two.init(2);
	re.init(0);
	REPP(i, 1, n) {
		if (n % i == 0) {
			tmp.init(euler(n / i));
			re = re + qp(two, i) * tmp;
		}
	}
	re = re / n;
	reverse(re.a.begin(), re.a.end());
	printf("%I64d", re.a[0]);
	REPP(i, 1, re.a.size() - 1) printf("%09I64d", re.a[i]);
	puts("");

	return 0;
}
