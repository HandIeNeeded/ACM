#line 2 "SubstringReversal.cpp"

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

vector<string> v;

class SubstringReversal {
	public:
	vector <int> solve(string s) {
		v.clear();
		int n = SZ(s), st, en;
		int find = 0;
		char c = 127;
		vector<int> ans;
		for (int i = 0; i < n && !find; ++i) {
			REPP(j, i + 1, n - 1) {
				if (s[j] < s[i]) {
					find = 1;
					st = i;
					if (s[j] < c) c = s[j];
				}
			}
		}
		if (!find) {
			ans.push_back(0), ans.push_back(0);
			return ans;
		}
		else {
			string re;
			REP(i, n) re += 'z';
			REPP(i, st + 1, n - 1) {
				if (s[i] == c) {
					string tem;
					REP(j, st) tem += s[j];
					REPP(j, st, i) tem += s[i - (j - st)];
					REPP(j, i + 1, n - 1) tem += s[j];
					if (re > tem) re = tem, en = i;
				}
			}
			ans.push_back(st), ans.push_back(en);
			return ans;
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "abdc"; int Arr1[] = {2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arg0 = "aabbcc"; int Arr1[] = {0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arg0 = "misof"; int Arr1[] = {0, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arg0 = "ivan"; int Arr1[] = {0, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { string Arg0 = "thisseemstobeaneasyproblem"; int Arr1[] = {0, 13 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SubstringReversal ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
