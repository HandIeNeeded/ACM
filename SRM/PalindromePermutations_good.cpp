#line 2 "PalindromePermutations.cpp"

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

int cnt[55], num[26];

class PalindromePermutations {
	public:
	double palindromeProbability(string word) {
		mem(cnt), mem(num);
		int n = SZ(word);
		int odd = 0;
		REP(i, n) num[word[i] - 'a']++;
		REP(i, 26) if (num[i] & 1) odd++;
		if (odd > 1) return 0;
		else {
			REPP(i, 1, n / 2) cnt[i]++;
			REPP(i, 1, n) cnt[i]--;
			REP(i, 26) {
				REPP(j, 1, num[i]) cnt[j]++;
				REPP(j, 1, num[i] / 2) cnt[j]--;
			}
			dou re = 1.0;
			REPP(i, 1, 50) {
				while (cnt[i] > 0) re *= i, cnt[i]--;
				while (cnt[i] < 0) re /= i, cnt[i]++;
			}
			return re;
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "haha"; double Arg1 = 0.3333333333333333; verify_case(0, Arg1, palindromeProbability(Arg0)); }
	void test_case_1() { string Arg0 = "xxxxy"; double Arg1 = 0.2; verify_case(1, Arg1, palindromeProbability(Arg0)); }
	void test_case_2() { string Arg0 = "xxxx"; double Arg1 = 1.0; verify_case(2, Arg1, palindromeProbability(Arg0)); }
	void test_case_3() { string Arg0 = "abcde"; double Arg1 = 0.0; verify_case(3, Arg1, palindromeProbability(Arg0)); }
	void test_case_4() { string Arg0 = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"; double Arg1 = 0.025641025641025637; verify_case(4, Arg1, palindromeProbability(Arg0)); }
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromePermutations ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
