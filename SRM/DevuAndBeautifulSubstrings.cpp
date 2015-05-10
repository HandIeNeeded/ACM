#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define LL long long

using namespace std;

const int N = 55;
LL dp[N][N * N][N];

class DevuAndBeautifulSubstrings {
	public:
	long long countBeautifulSubstrings(int n, int cnt) {
		dp[1][1][1] = 2;
		REPP(i, 1, n - 1) {
			int up = i * (i + 1) / 2;
			REPP(j, i, up) {
				REPP(k, 1, i) {
					dp[i + 1][j + 1][1] += dp[i][j][k];
					dp[i + 1][j + k + 1][k + 1] += dp[i][j][k];
				}
			}
		}
		LL ans = 0;
		REPP(i, 1, n) ans += dp[n][cnt][i];
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; long long Arg2 = 2LL; verify_case(0, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; long long Arg2 = 0LL; verify_case(1, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; long long Arg2 = 4LL; verify_case(2, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 35; long long Arg2 = 642LL; verify_case(3, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 40; int Arg1 = 820; long long Arg2 = 2LL; verify_case(4, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 94; long long Arg2 = 32357325751902LL; verify_case(5, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	DevuAndBeautifulSubstrings ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
