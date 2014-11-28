#line 2 "ReflectiveRectangle.cpp"

#include <bits/stdc++.h>
#define dou double
#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()
#define PII pair<int, int>
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define INF 2000000000
#define MOD 1000000007
#define N 55

using namespace std;

int qp(int x, int y) {
	int re = 1;
	while (y) {
		if (y & 1) re = 1ll * re * x % MOD;
		y >>= 1;
		x = 1ll * x * x % MOD;
	}
	return re;
}

int inv6 = qp(6, MOD - 2);

int sqr(int x) {return 1ll * x * x % MOD;}
int sum(int x) {
	int re;
	re = 1ll * x * (x + 1) % MOD;
	re = 1ll * re * (2 * x + 1) % MOD;
	re = 1ll * re * inv6 % MOD;
	return re;
}

int fac[50], tot;

void add(int&x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int cal(int x) {
	int xx = x;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			fac[tot++] = i;
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) fac[tot++] = x;
	x = xx;
	int re = sum(x);
	REP(i, (1 << tot)) if (i) {
		int cnt = 0, tem = 1;
		REP(j, tot) if ((1 << j) & i) cnt++, tem *= fac[j];
		int hehe = 1ll * sqr(tem) * sum(x / tem) % MOD;
		if (cnt & 1) add(re, MOD - hehe);
		else add(re, hehe);
	}
	return re;
}

class ReflectiveRectangle {
	public:
	int findSum(int a, int b, int bounces) {
		if (bounces & 1) return 0;
		else {
			mem(fac), tot = 0;
			int mul = (sqr(a) + sqr(b)) % MOD;
			int ans = cal(bounces + 2);
			return 1ll * ans * mul % MOD;
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { 
		if ((Case == -1) || (Case == 0)) test_case_0();
		if ((Case == -1) || (Case == 1)) test_case_1();
		if ((Case == -1) || (Case == 2)) test_case_2();
		if ((Case == -1) || (Case == 3)) test_case_3();
		if ((Case == -1) || (Case == 4)) test_case_4();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 0; int Arg3 = 25; verify_case(0, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arg3 = 180; verify_case(1, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = 17; int Arg2 = 1; int Arg3 = 0; verify_case(2, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 59325; int Arg1 = 31785; int Arg2 = 262142; int Arg3 = 48032850; verify_case(3, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 1000000; int Arg2 = 1000000000; int Arg3 = 145972110; verify_case(4, Arg3, findSum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ReflectiveRectangle ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
