#line 2 "TheAlmostLuckyNumbersDivOne.cpp"

#include <bits/stdc++.h>
#define dou double
#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int) a.size())
#define PII pair<int, int>
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define INF 2000000000
#define MOD 1000000007
#define N 55

using namespace std;

LL dp[20][2][2][2], vis[20][2][2][2];
int bit[20];

LL go(int dep, int fx, int fy, int fz) { //small, used, prefix
	if (dep < 0) return 1;
	else if (vis[dep][fx][fy][fz]) return dp[dep][fx][fy][fz];
	else {
		vis[dep][fx][fy][fz] = 1;
		LL& re = dp[dep][fx][fy][fz];
		// 0
		if (!fz) re += go(dep - 1, fx || bit[dep] > 0, fy, 0);
		else if (fz && !fy) {
			re += go(dep - 1, fx || bit[dep] > 0, 1, 1);
		}
		// 1--9
		REPP(i, 1, 9) {
			fz = 1;
			if (fx) {
				if (!fy || i == 4 || i == 7) re += go(dep - 1, 1, fy || (i != 4 && i != 7), fz);
			}
			else {
				if (i < bit[dep]) {
					if (!fy) re += go(dep - 1, 1, i != 4 && i != 7, fz);
					else {
						if (i == 4 || i == 7) re += go(dep - 1, 1, fy, fz);
					}
				}
				else if (i == bit[dep]) {
					if (i == 4 || i == 7) re += go(dep - 1, 0, fy, fz);
					else if (!fy) re += go(dep - 1, 0, 1, fz);
				}
			}
		}
		return re;
	}
}

class TheAlmostLuckyNumbersDivOne {
	public:
	long long find(long long a, long long b) {
		mem(dp), mem(vis);
		a--;
		int len = 0;
		while (a) bit[len++] = a % 10, a/= 10;
		LL x = go(len - 1, 0, 0, 0);
		mem(dp), mem(vis);
		len = 0;
		while (b) bit[len++] = b % 10, b/= 10;
		LL y = go(len - 1, 0, 0, 0);
		//cout << y << ' ' << x << endl;
		return y - x;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 7LL; long long Arg2 = 4LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 8LL; long long Arg1 = 19LL; long long Arg2 = 4LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 28LL; long long Arg1 = 33LL; long long Arg2 = 0LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 12345678900LL; long long Arg1 = 98765432100LL; long long Arg2 = 91136LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheAlmostLuckyNumbersDivOne ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
