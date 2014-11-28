#line 2 "BuildingHeights.cpp"

#include <bits/stdc++.h>
#define dou double
#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int) a.size())
#define PII pair<int, int>
#define mem(a) memset(a, 10, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define INF 2000000000
#define MOD 1000000007
#define N 4444

using namespace std;

int h[N];

class BuildingHeights {
	public:
	int minimum(vector <int> heights) {
		sort(heights.begin(),heights.end());
		int n = SZ(heights);
		REPP(i, 1, n) h[i] = heights[i - 1];
		REPP(i, 1, n) h[i] += h[i - 1];
		int re = 0;
		REPP(i, 0, n - 1) {
			int mi = INF;
			REPP(j, 1, n - i) {
				if (heights[i + j - 1] * (i + 1) - (h[i + j] - h[j - 1]) < mi) mi = heights[i + j - 1] * (i + 1) - (h[i + j] - h[j - 1]);
			}
			re ^= mi;
		}
		return re;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 5, 4, 3, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; verify_case(0, Arg1, minimum(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimum(Arg0)); }
	void test_case_2() { int Arr0[] = {3, 4, 1, 6, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(2, Arg1, minimum(Arg0)); }
	void test_case_3() { int Arr0[] = {990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
 2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
 929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
 1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
 1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
 1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 56068; verify_case(3, Arg1, minimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BuildingHeights ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
