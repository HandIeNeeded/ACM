// BEGIN CUT HERE

// END CUT HERE
#line 5 "MyLongCake.cpp"

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

int a[111111];

class MyLongCake {
	public:
	int cut(int n) {
		mem(a);
		REPP(i, 1, n - 1) if (n % i == 0) {
			int st = n / i;
			for (int j = st; j <= n; j += st) a[j] = 1;
		}
		int cnt = 0;
		REPP(i, 1, n) if (a[i]) cnt++;
		return cnt;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 4; verify_case(0, Arg1, cut(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; verify_case(1, Arg1, cut(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 7; verify_case(2, Arg1, cut(Arg0)); }
	void test_case_3() { int Arg0 = 100000; int Arg1 = 60000; verify_case(3, Arg1, cut(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MyLongCake ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
