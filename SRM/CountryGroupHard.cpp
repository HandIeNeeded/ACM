#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

const int N = 105;
int dp[N][N][N];

class CountryGroupHard {
	public:
	string solve(vector <int> a) {
		MST(dp, 0);
		int n = a.size();
		REP(i, a.size()) {
			if (a[i] > n) {
				return "Insufficient";
			}
		}
		REPP(i, 1, n) {
			dp[0][i][0] = 1;
		}
		REPP(i, 1, n) {
			REPP(j, 1, n) {
				if (dp[i - 1][j][j]) {
					if (a[i - 1]) {
						dp[i][a[i - 1]][1] += dp[i - 1][j][j];
						dp[i][a[i - 1]][1] = min(10, dp[i][a[i - 1]][1]);
					}
					else {
						REPP(k, 1, n) {
							dp[i][k][1] += dp[i - 1][j][j];
							dp[i][k][1] = min(10, dp[i][k][1]);
						}
					}
				}
			}
			REPP(j, 1, n) {
				REP(k, j) {
					if (dp[i - 1][j][k]) {
						if (a[i - 1] && a[i - 1] == j) {
							dp[i][j][k + 1] += dp[i - 1][j][k];
							dp[i][j][k + 1] = min(10, dp[i][j][k + 1]);
						}
						else if (a[i - 1] == 0) {
							dp[i][j][k + 1] += dp[i - 1][j][k];
							dp[i][j][k + 1] = min(10, dp[i][j][k + 1]);
						}
					}
				}
			}
		}
		int cnt = 0;
		REPP(i, 1, n) {
			if (dp[n][i][i]) {
				cnt += dp[n][i][i];
			}
		}
		return cnt > 1 ? "Insufficient" : "Sufficient";
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {0,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {0,3,0,0,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,3,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {2,2,0,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	CountryGroupHard ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
