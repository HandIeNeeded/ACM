// BEGIN CUT HERE

// END CUT HERE
#line 5 "TwoWaysSorting.cpp"

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

class TwoWaysSorting {
	public:
	string sortingMethod(vector <string> stringList) {
		int n = stringList.size();
		int bad = 0, good = 0;
		REP(i, n - 1) if (stringList[i] >= stringList[i + 1]) bad = 1;
		REP(i, n - 1) if (stringList[i].size() >= stringList[i + 1].size()) good = 1;
		if (bad && good) return "none";
		else if (bad && !good) return "lengths";
		else if (!bad && good) return "lexicographically";
		return "both";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a", "aa", "bbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "both"; verify_case(0, Arg1, sortingMethod(Arg0)); }
	void test_case_1() { string Arr0[] = {"c", "bb", "aaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lengths"; verify_case(1, Arg1, sortingMethod(Arg0)); }
	void test_case_2() { string Arr0[] = {"etdfgfh", "aio"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "none"; verify_case(2, Arg1, sortingMethod(Arg0)); }
	void test_case_3() { string Arr0[] = {"aaa", "z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lexicographically"; verify_case(3, Arg1, sortingMethod(Arg0)); }
	void test_case_4() { string Arr0[] = {"z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "both"; verify_case(4, Arg1, sortingMethod(Arg0)); }
	void test_case_5() { string Arr0[] = {"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lexicographically"; verify_case(5, Arg1, sortingMethod(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TwoWaysSorting ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
