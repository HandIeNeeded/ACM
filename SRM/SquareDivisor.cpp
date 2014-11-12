#line 2 "SquareDivisor.cpp"

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
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define N 1111111

using namespace std;

int vis[N], p[N], tot;

void Init() {
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && p[j] * i < N; ++j) {
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break; 
		}
	}
}

LL sqr(LL x) {return 1ll * x * x;}

class SquareDivisor {
	public:
	long long biggest(long long n) {
		Init();
		LL ans = 1;
		for (int i = 0; i < tot; ++i) {
			if (n % p[i] == 0) {
				int tt = 0;
				while (n % p[i] == 0) {
					ans *= p[i];
					n /= p[i];
					tt++;
				}
				if (tt & 1) ans /= p[i];
			}
		}
		if (n > 1) {
			LL x = sqrt(n + 0.5);
			if (sqr(x + 1) == n) x++;
			if (sqr(x - 1) == n) x--;
			if (sqr(x) == n) ans *= n;
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 12LL; long long Arg1 = 4LL; verify_case(0, Arg1, biggest(Arg0)); }
	void test_case_1() { long long Arg0 = 100LL; long long Arg1 = 100LL; verify_case(1, Arg1, biggest(Arg0)); }
	void test_case_2() { long long Arg0 = 2014LL; long long Arg1 = 1LL; verify_case(2, Arg1, biggest(Arg0)); }
	void test_case_3() { long long Arg0 = 999999875021574338LL; long long Arg1 = 499999937510787169LL; verify_case(3, Arg1, biggest(Arg0)); }
	void test_case_4() { long long Arg0 = 999999998000000002LL; long long Arg1 = 1LL; verify_case(4, Arg1, biggest(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	SquareDivisor ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
