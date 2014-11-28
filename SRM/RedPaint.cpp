// BEGIN CUT HERE

// END CUT HERE
#line 5 "RedPaint.cpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <sstream>
#define dou double
#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define mem(a) memset(a, 0, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define INF 2000000000
#define MOD 1000000007

using namespace std;

dou dp[2][2][2][555 * 2][555]; //pos, cnt

class RedPaint {
	public:
	double expectedCells(int N) {
		mem(dp);
		int cur = 0;
		int n = N;
		if (n == 0) return 1.0;
		dp[cur][0][0][555][1] = 1.0;
		REPP(i, 1, n) {
			REPP(j, -i + 555, i + 555) {
				REPP(k, 1, i + 5) {
					REP(l, 2) REP(r, 2) {
						if (l == 0 && r == 0) dp[cur ^ 1][l][r][j][k] = 0;
						else if (l == 0 && r == 1) dp[cur ^ 1][l][r][j][k] = (dp[cur][0][0][j + 1][k - 1] + dp[cur][0][1][j + 1][k - 1] + dp[cur][1][0][j + 1][k] + dp[cur][1][1][j + 1][k]) * 0.5;
						else if (l == 1 && r == 0) dp[cur ^ 1][l][r][j][k] = (dp[cur][1][0][j - 1][k - 1] + dp[cur][1][1][j - 1][k] + dp[cur][0][0][j - 1][k - 1] + dp[cur][0][1][j - 1][k]) * 0.5;
						else dp[cur ^ 1][l][r][j][k] = (dp[cur][0][1][j - 1][k] + dp[cur][1][1][j - 1][k] + dp[cur][1][0][j + 1][k] + dp[cur][1][1][j + 1][k]) * 0.5;
					}
				}
			}
			cur ^= 1;
		}
		//cout << "SSSSSS" << endl;
		//REPP(i, 1, n) cout << i << ' ' <<  dp[cur][1][1][n + 555][i] << endl;
		dou re = 0.0, tmp;
		REPP(i, 555 - n - 10, 555 + n + 10) {
			REPP(t, 1, n + 5) {
				tmp = 0.0;
				REP(j, 2) REP(k, 2) {
					tmp += dp[cur][j][k][i][t];
				}
				re += tmp * t;
			}
		}
		return re;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; double Arg1 = 1.0; verify_case(0, Arg1, expectedCells(Arg0)); }
	void test_case_1() { int Arg0 = 1; double Arg1 = 2.0; verify_case(1, Arg1, expectedCells(Arg0)); }
	void test_case_2() { int Arg0 = 2; double Arg1 = 2.5; verify_case(2, Arg1, expectedCells(Arg0)); }
	void test_case_3() { int Arg0 = 4; double Arg1 = 3.375; verify_case(3, Arg1, expectedCells(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RedPaint ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
