// BEGIN CUT HERE

// END CUT HERE
#line 5 "RadioRange.cpp"

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

dou l[111], r[111];

bool cover(int x, int y, int z) {
	return 1ll * x * x + 1ll * y * y <= 1ll * z * z;
}

void go(int id, int x, int y, int z) {
	l[id] = abs(sqrt(1.0 * x * x + 1.0 * y * y) - 1.0 * z);
	r[id] = sqrt(1.0 * x * x + 1.0 * y * y) + 1.0 * z;
}

class RadioRange {
	public:
	double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
		int n = X.size();
		REP(i, n) go(i, X[i], Y[i], R[i]);
		REP(i, n) {
			if (cover(X[i], Y[i], R[i])) l[i] = 0.0;
			if (r[i] > 1.0 * Z) r[i] = 1.0 * Z;
			if (l[i] > r[i]) l[i] = r[i];
		}
		dou st = 0.0, en = 0.0, good = 0.0;
		pair<dou, dou> p[111];
		REP(i, n) p[i] = MP(l[i], r[i]);
		sort(p, p + n);
		REP(i, n) l[i] = p[i].first, r[i] = p[i].second;
		//REP(i, n) cout << i << ' ' << l[i] << ' ' << r[i] << endl;
		REP(i, n) {
			if (l[i] > en) good += l[i] - en, st = l[i], en = r[i];
			else en = max(r[i], en);
		}
		good += 1.0 * Z - en;
		return good / (1.0 * Z);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.5; verify_case(0, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.0; verify_case(1, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.4142135623730951; verify_case(2, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {11, -11, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 11, -11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 10, 10, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 31; double Arg4 = 0.3548387096774194; verify_case(3, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 1.0; verify_case(4, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000000000; double Arg4 = 0.41421356237309503; verify_case(5, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {20, -20, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 20, -20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50, 50, 50, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; double Arg4 = 0.3; verify_case(6, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arr0[] = {0, -60, -62, -60, 63, -97}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-72, 67, 61, -8, -32, 89}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 7, 8, 7, 5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 918; double Arg4 = 0.9407071068962471; verify_case(7, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RadioRange ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
