// BEGIN CUT HERE

// END CUT HERE
#line 5 "SixteenBricks.cpp"

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
#define memm(a) memset(a, -1, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define INF 2000000000
#define MOD 1000000007

using namespace std;

int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
vector<int> tem;

int good(int x, int y) { return x >= 0 && x < 4 && y >= 0 && y < 4; }

int get(const vector<int> &v) {
	int re = 16;
	REP(i, 16) re += v[i] * 4;
	REP(i, 16) {
		int x = i / 4, y = i % 4;
		REP(j, 4) if(good(x + dx[j], y + dy[j])) re -= min(v[4 * x + y], v[4 * (x + dx[j]) + y + dy[j]]);
	}
	return re;
}

class SixteenBricks {
public:
	int maximumSurface(vector <int> v) {
		int cur = 0;
		while (cur++ < 100000) {
			int x = rand() % 16, y = rand() % 16;
			int a = get(v);
			swap(v[x], v[y]);
			int b = get(v);
			if (a > b) swap(v[x], v[y]);
		}
		return get(v);
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, maximumSurface(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(1, Arg1, maximumSurface(Arg0)); }
	void test_case_2() {
		int Arr0[] = { 77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59 }
		; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1798; verify_case(2, Arg1, maximumSurface(Arg0));
	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SixteenBricks ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
