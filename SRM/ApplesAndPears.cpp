#line 2 "ApplesAndPears.cpp"

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

int s[3][N][N], lim, can;
string str = ".AP";
vector <string> b;

void cnt(int ty, int r, int c) {
	REPP(i, 1, r) REPP(j, 1, c) s[ty][i][j] = s[ty][i - 1][j] + s[ty][i][j - 1] - s[ty][i - 1][j - 1] + (b[i - 1][j - 1] == str[ty] ? 1 : 0);
}

int get(int x, int y, int z, int w, int ty) {
	return s[ty][x][y] - s[ty][x][w - 1] - s[ty][z-  1][y] + s[ty][z - 1][w - 1];
}

int cal(int ty, int r, int c) {
	int ans = 0;
	REPP(x, 1, r) REPP(y, 1, c) {
		REPP(z, 1, x) REPP(w, 1, y) {
			if (get(x, y, z, w, ty) == (x - z + 1) * (y - w + 1)) ans = max(ans, (x - z + 1) * (y - w + 1));
			else if (can) {
				int area = (x - z + 1) * (y - w + 1);
				if (ty == 0) {
					if (s[ty][r][c] >= area && get(x, y, z, w, 1) + get(x, y, z, w, 2) <= lim) ans = max(ans, area); 
				}
				else if (ty == 1) {
					if (s[ty][r][c] >= area && get(x, y, z, w, 0) + 2 * get(x, y, z, w, 2) <= lim) ans = max(ans, area); 
				}
				else {
					if (s[ty][r][c] >= area && get(x, y, z, w, 0) + 2 * get(x, y, z, w, 1) <= lim) ans = max(ans, area); 
				}
			}
		}
	}
	return ans;
}

class ApplesAndPears {
	public:
	int getArea(vector <string> board, int K) {
		b = board, lim = K;
		mem(s);
		int r = SZ(board), c = SZ(board[0]);
		REP(ty, 3) cnt(ty, r, c);
		int ans = 0;
		can = s[0][r][c];
		REP(ty, 3) ans = max(ans, cal(ty, r, c));
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".A",
 "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".A",
 "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".PP", 
 "PPA", 
 "PAP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(2, Arg2, getArea(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A.P.PAAPPA",
 "PPP..P.PPP",
 "AAP.A.PAPA",
 "P.PA.AAA.A",
 "...PA.P.PA",
 "P..A.A.P..",
 "PAAP..A.A.",
 "PAAPPA.APA",
 ".P.AP.P.AA",
 "..APAPAA.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 21; verify_case(3, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ApplesAndPears ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
