#line 2 "TextCompressor.cpp"

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

int get(string source, string s) {
	int cnt = 0;
	REP(i, SZ(source) - SZ(s) + 1) {
		if (source.substr(i, SZ(s)) == s) {
			cnt++;
			i = i + SZ(s) - 1;
		}
	}
	return cnt;
}

class TextCompressor {
	public:
	string longestRepeat(string sourceText) {
		string ans;
		REP(i, SZ(sourceText)) {
			for (int j = 1; j + i - 1 < SZ(sourceText); ++j) {
				string s = sourceText.substr(i, j);
				int tmp = get(sourceText, s);
				if (tmp > 1) {
					if (SZ(s) > SZ(ans)) ans = s; 
				}
			}
		}
		return ans;
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
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDABCFG"; string Arg1 = "ABC"; verify_case(0, Arg1, longestRepeat(Arg0)); }
	void test_case_1() { string Arg0 = "ABABA"; string Arg1 = "AB"; verify_case(1, Arg1, longestRepeat(Arg0)); }
	void test_case_2() { string Arg0 = "This is a test."; string Arg1 = "is "; verify_case(2, Arg1, longestRepeat(Arg0)); }
	void test_case_3() { string Arg0 = "Testing testing 1 2 3."; string Arg1 = "esting "; verify_case(3, Arg1, longestRepeat(Arg0)); }
	void test_case_4() { string Arg0 = "The quick brown fox jumps over the lazy dog."; string Arg1 = "he "; verify_case(4, Arg1, longestRepeat(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	TextCompressor ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
