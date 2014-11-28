#line 2 "DivisorsPower.cpp"

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
#define N 55

using namespace std;

LL qp(LL x, int y) {
	LL re = 1;
	while (y) {
		if (y & 1) re *= x;
		y >>= 1;
		x *= x;
	}
	return re;
}

class DivisorsPower {
	public:
	long long findArgument(long long n) {
		cout << pow(1e18+0.5, 1.0 / 9) << endl;
		for (int i = 62; i >= 2; --i) {
			LL x = (LL) pow(1.0 * n + 0.9, 1.0 / i);
			if (qp(x - 1, i) == n) x--;
			else if(qp(x + 1, i) == n) x++;
			if (qp(x, i) != n) continue;
			else {
				int cnt = 0;
				for (int j = 1; 1ll * j * j <= x; ++j) {
					if (x % j == 0) {
						cnt++;
						if (x / j != j) cnt++;
					}
				}
				if (cnt == i) return x;
			}
		}
		return -1;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 100LL; verify_case(0, Arg1, findArgument(Arg0)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = -1LL; verify_case(1, Arg1, findArgument(Arg0)); }
	void test_case_2() { long long Arg0 = 64LL; long long Arg1 = 4LL; verify_case(2, Arg1, findArgument(Arg0)); }
	void test_case_3() { long long Arg0 = 10000LL; long long Arg1 = 10LL; verify_case(3, Arg1, findArgument(Arg0)); }
	void test_case_4() { long long Arg0 = 2498388559757689LL; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	DivisorsPower ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
