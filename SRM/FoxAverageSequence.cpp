#line 2 "FoxAverageSequence.cpp"

#include <bits/stdc++.h>

#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VP vector<PII>
#define VS vector<string>
#define PII pair<int, int>
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define DBG(x, s) cout << (x) << ' ' << (s) << endl
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define RED(i, n) for (int i = (int) (n - 1); i >= 0; --i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define REDD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define INF 0x3f3f3f3f

using namespace std;
const int MOD = (int) 1e9 + 7;
const int N = 45;
int n;

int dp[2][N * N][N][2];
int a[N];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

class FoxAverageSequence {
	public:
	int theCount(vector <int> seq) {
		//mem(dp);
		n = SZ(seq);
		REP(i, n) a[i + 1] = seq[i];
		int cur = 0;
		dp[0][0][0][1] = 1;

		REPP(i, 1, n) {
			REPP(j, 0, 40 * i) {
				if (a[i] == -1) {
					REPP(las, 0, 40) {
						int pre = j - las;
						if ((i - 1) * las <= pre) {
							REPP(k, 0, las) {//0 ^   1 v
								add(dp[cur ^ 1][j][las][0], dp[cur][pre][k][0]);
								add(dp[cur ^ 1][j][las][0], dp[cur][pre][k][1]);
							}
							REPP(k, las + 1, 40) {
								add(dp[cur ^ 1][j][las][1], dp[cur][pre][k][0]);
							}
						}
					}
				}
				else {
					int las = a[i];
					int pre = j - las;
					if ((i - 1) * las <= pre) {
						REPP(k, 0, las) {//0 ^   1 v
							add(dp[cur ^ 1][j][las][0], dp[cur][pre][k][0]);
							add(dp[cur ^ 1][j][las][0], dp[cur][pre][k][1]);
						}
						REPP(k, las + 1, 40) {
							add(dp[cur ^ 1][j][las][1], dp[cur][pre][k][0]);
						}
					}
				}
			}
			REPP(j, 0, 40 * i) REPP(k, 0, 40) REP(t, 2) dp[cur][j][k][t] = 0;
			cur ^= 1;
		}
		int ans = 0;
		REPP(i, 0, 40 * n) REPP(j, 0, 40) {
			add(ans, dp[cur][i][j][0]);
			add(ans, dp[cur][i][j][1]);
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, 0, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 579347890; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 12, 25, 0, 18, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	FoxAverageSequence ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
