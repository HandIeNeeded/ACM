#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

class DevuAndPlantingTrees {
	public:
	vector<string> garden;
	int n, m;

	bool good(int x, int y) {
		REPP(i, -1, 1) {
			REPP(j, -1, 1) {
				if (x + i >= 0 && x + i < 2 && y + j >= 0 && y + j < m) {
					if (garden[x + i][y + j] == '*') return 0;
				}
			}
		}
		return 1;
	}

	int maximumTreesDevuCanGrow(vector <string> g) {
		garden = g;
		n = garden.size();
		m = garden[0].size();
		int ans = 0;
		REP(i, 2) {
			REP(j, m) {
				if (good(i, j)) {
					garden[i][j] = '*';
				}
			}
		}
		//cout << garden[0] << endl << garden[1] << endl;
		REP(i, 2) {
			REP(j, m) if (garden[i][j] == '*') ans++;
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..", ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_1() { string Arr0[] = {"..", ".*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_2() { string Arr0[] = {"...",
"..*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_3() { string Arr0[] = {".....*..........",
".*.......*.*..*."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_4() { string Arr0[] = {"....*.*.*...........*........",
"*..........*..*.*.*....*...*."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_5() { string Arr0[] = {".....*..*..........*............................*",
"*..*.............*...*.*.*.*..*.....*.*...*...*.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; verify_case(5, Arg1, maximumTreesDevuCanGrow(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	DevuAndPlantingTrees ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
