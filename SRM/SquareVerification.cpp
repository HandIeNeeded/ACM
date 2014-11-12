#line 2 "SquareVerification.cpp"

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

class SquareVerification {
	public:
	int calculateCode(int x) {
		int y = x * x;
		int ans = 0;
		while (y) {
			ans = max(ans, y % 10);
			y /= 10;
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; verify_case(0, Arg1, calculateCode(Arg0)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 9; verify_case(1, Arg1, calculateCode(Arg0)); }
	void test_case_2() { int Arg0 = 766; int Arg1 = 8; verify_case(2, Arg1, calculateCode(Arg0)); }
	void test_case_3() { int Arg0 = 777; int Arg1 = 9; verify_case(3, Arg1, calculateCode(Arg0)); }
	void test_case_4() { int Arg0 = 1111; int Arg1 = 4; verify_case(4, Arg1, calculateCode(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	SquareVerification ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
