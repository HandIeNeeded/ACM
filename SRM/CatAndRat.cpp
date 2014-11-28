#line 2 "CatAndRat.cpp"

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
#define pi 3.14159265358979

using namespace std;

class CatAndRat {
	public:
	double getTime(int R, int T, int Vrat, int Vcat) {
		if (Vcat - Vrat <= 0) return -1.0;
		else {
			if (1.0 * T * Vrat > pi * R) {
				return pi * R / (Vcat - Vrat);
			}
			else return 1.0 * T * Vrat / (Vcat - Vrat);
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; double Arg4 = -1.0; verify_case(0, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; double Arg4 = 1.0; verify_case(1, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; double Arg4 = -1.0; verify_case(2, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1000; int Arg2 = 1; int Arg3 = 1000; double Arg4 = 1.001001001001001; verify_case(3, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1000; int Arg2 = 1; int Arg3 = 2; double Arg4 = 3.141592653589793; verify_case(4, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CatAndRat ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
