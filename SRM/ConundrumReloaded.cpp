#line 2 "ConundrumReloaded.cpp"

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

int dp[N][2];

int go(string s, int now) { //0 H 1 L
	int n = SZ(s), ori = now;
	mem(dp);
	if (now == 0) dp[0][0] = 0, dp[0][1] = -1;
	else dp[0][0] = -1, dp[0][1] = 0;
	REPP(i, 1, n) {
		char c = s[i - 1];
		if (c == '?') {
			if (dp[i - 1][0] >= 0 && dp[i - 1][1] >= 0) dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]),  dp[i][1] = dp[i][0] + 1;
			else if (dp[i - 1][0] >= 0) {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][0] + 1;
			}
			else if (dp[i - 1][1] >= 0) {
				dp[i][0] = dp[i - 1][1];
				dp[i][1] = dp[i - 1][1] + 1;
			}
			else dp[i][0] = dp[i][1] = -1;
		}
		else {
			int per;
			if (c == 'H') per = 0;
			else per = 1;
			if (dp[i - 1][0] >= 0 && dp[i - 1][1] >= 0) dp[i][per] = dp[i - 1][0] + per, dp[i][per ^ 1] = dp[i - 1][1] + (per ^ 1);
			else if (dp[i - 1][0] >= 0) {
				dp[i][per] = dp[i - 1][0] + per;
				dp[i][per ^ 1] = -1;
			} 
			else if (dp[i - 1][1] >= 0) {
				dp[i][per ^ 1] = dp[i - 1][1] + (per ^ 1);
				dp[i][per] = -1;
			}
			else dp[i][per] = -1, dp[i][per ^ 1] = -1;
		}
	}
	return dp[n][ori];
}

class ConundrumReloaded {
	public:
	int minimumLiars(string answers) {
		string s;
		int n  = SZ(answers);
		int good = 0;
		REP(i, n) if (answers[i] != '?') good = 1;
		if (!good) return 0;
		else {
			int pos = 0;
			REP(i, n) {
				if (answers[i] != '?') {
					pos = i;
					break;
				}
			}
			s = answers.substr(pos);
			REP(i, pos) s += answers[i];
			int t1 = go(s, 0);
			int t2 = go(s, 1);
			if (t1 < 0 || t2 < 0) return max(t1, t2);
			return min(t1, t2);
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
	void test_case_0() { string Arg0 = "LLH"; int Arg1 = 1; verify_case(0, Arg1, minimumLiars(Arg0)); }
	void test_case_1() { string Arg0 = "?????"; int Arg1 = 0; verify_case(1, Arg1, minimumLiars(Arg0)); }
	void test_case_2() { string Arg0 = "LHLH?"; int Arg1 = 2; verify_case(2, Arg1, minimumLiars(Arg0)); }
	void test_case_3() { string Arg0 = "??LLLLLL??"; int Arg1 = 3; verify_case(3, Arg1, minimumLiars(Arg0)); }
	void test_case_4() { string Arg0 = "LLL"; int Arg1 = -1; verify_case(4, Arg1, minimumLiars(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ConundrumReloaded ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
