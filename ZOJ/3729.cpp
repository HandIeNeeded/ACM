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
#define LL unsigned long long
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define RL(a) scanf("%lld", &(a))
#define RLL(a, b) scanf("%lld%lld", &(a), &(b))
#define RLLL(a, b, c) scanf("%lld%lld%lld", &(a), &(b), &(c))
#define PI(r) printf("%d\n", (r))
#define PL(r) printf("%lld\n", (r))
#define RS(s) scanf("%s", (s))
#define SL(a) strlen(a)
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FOR(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MID ((l + r) >> 1)
#define L (x << 1)
#define R ((x << 1) | 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))
#pragma warning (disable : 4996)
//#pragma comment(linker, "/STACK:102400000,102400000")
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define LIM (1ll << 60)
#define MOD 1000000007
#define N 211111

using namespace std;

LL n, m;
int p[N], vis[N], tot;

struct mat{
	LL v[2][2];
	mat() { mem(v); }
}I, F;

void add(LL& x, LL y, LL p) {
	x += y;
	if (x >= p) x -= p;
}

mat mul(mat a, mat b, LL p) {
	mat re;
	REP(i, 2) REP(j, 2) REP(k, 2) add(re.v[i][j], a.v[i][k] * b.v[k][j] % p, p);
	return re;
}

mat qp(mat a, LL b, LL p) {
	mat re = I;
	while (b) {
		if (b & 1) re = mul(re, a, p);
		b >>= 1;
		a = mul(a, a, p);
	}
	return re;
}

void Init() {
	REP(i, 2) I.v[i][i] = 1;
	F.v[0][1] = F.v[1][0] = F.v[1][1] = 1;
	for (int i = 2; i < N; ++i){
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; ++j) {
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

LL fac[100], cnt[100], num;

LL qp(LL x, LL y, LL p) {
	LL re = 1;
	while (y) {
		if (y & 1) re = re * x % p;
		x = x * x % p;
		y >>= 1;
	}
	return re;
}

LL gcd(LL x, LL y) { return y ? gcd(y, x % y) : x; }

LL lcm(LL x, LL y) { return x / gcd(x, y) * y; }

LL T[100];

bool issame(const mat& a, const mat& b) {
	REP(i, 2) REP(j, 2) if (a.v[i][j] != b.v[i][j]) return 0;
	return 1;
}

LL loop(LL x) {
	if (x == 2) return 3;
	if (x == 3) return 8;
	if (x == 5) return 20;
	else {
		vector<LL> fac;
		LL y;
		if (qp(5ll, (x - 1) >> 1, x) == 1) y = x - 1;
		else y = (x + 1) << 1;
		for (int i = 1; 1ll * i * i <= y; ++i) {
			if (y % i == 0) fac.push_back(i), fac.push_back(y / i);
		}
		sort(ALL(fac));
		mat fun, tem;
		REP(i, SZ(fac)) {
			fun = F;
			tem = qp(fun, fac[i], x);
			if (issame(tem, I)) return fac[i];
		}
	}
	return -1;
}

LL qp(LL a, LL b) {
    	LL re = 1;
   	while (b) {
       		if (b & 1) re = (re * a);
        		b >>= 1;
        		a *= a;
   	}
    	return re;
}

int main(){
	int t, x, y, z, ca = 1;
	//freopen("D:/Contest/1.in", "r", stdin);
	//freopen("1.ans", "w", stdout);
	//ios :: sync_with_stdio(false);
	Init();
	while (RL(n) > 0) {
		num = 0;
		for (int i = 0; i < tot && 1ll * p[i] * p[i] <= n; ++i) {
			if (n % p[i] == 0) {
				fac[num] = p[i];
				while (n % p[i] == 0) {
					cnt[num]++;
					n /= p[i];
				}
				num++;
			}
		}
		if (n > 1) fac[num] = n, cnt[num++] = 1;
		LL ans = 1;
		REP(i, num) {
			T[i] = loop(fac[i]) * qp(fac[i], cnt[i] - 1);
			ans = lcm(ans, T[i]);
		}
		PL(ans >> 1);
		mem(cnt);
	}

	return 0;
}