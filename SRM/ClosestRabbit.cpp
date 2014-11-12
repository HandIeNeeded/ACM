#line 2 "ClosestRabbit.cpp"

#include <bits/stdc++.h>

#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VP vector<PII>
#define VS vector<string>
#define PII pair<int, int>
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define DBG(x, s) cout << (x) << ' ' << (s) << endl
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define RED(i, n) for (int i = (int) (n - 1); i >= 0; --i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define REDD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define INF 0x3f3f3f3f

using namespace std;

const int N = 405;
double c[N][N];
VP p;

int sqr(int x) {return x * x;}

int dis(int x, int y) {
	return sqr(p[x].FI - p[y].FI) + sqr(p[x].SE - p[y].SE);
}

class ClosestRabbit {
	public:
	double getExpected(vector <string> board, int r) {
		REP(i, 401) {
			c[i][0] = c[i][i] = 1.0;
			REPP(j, 1, i - 1) {
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			}
		}

		int n = SZ(board), m = SZ(board[0]);
		int tot = 0;
		double ans = 0;

		p.clear();
		REP(i, n) REP(j, m) if (board[i][j] == '.') tot++, p.push_back(MP(i, j));

		REP(i, tot) {
			REPP (j, i + 1, tot - 1) {
				int d = dis(i, j);
				int tmp = 0;
				REP(k, tot) if (k != i && k != j){
					if (dis(k, i) < d || dis(k, j) < d) continue;
					if (dis(k, i) == d && p[k] < p[j]) continue;
					if (dis(k, j) == d && p[k] < p[i]) continue;
					tmp++;
				}
				ans += c[tmp][r - 2] / c[tot][r];
			}
		}

		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".#.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..###.",
 ".###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1.6; verify_case(1, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"..###.",
 ".###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 2.0; verify_case(2, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".....",
 "#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1.253968253968254; verify_case(3, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".#####.#####..#....#",
 "#......#....#.##..##",
 ".####..#####..#.##.#",
 ".....#.#...#..#....#",
 "#####..#....#.#....#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; double Arg2 = 5.77311527122319; verify_case(4, Arg2, getExpected(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	ClosestRabbit ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
