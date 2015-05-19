#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

const int N = 16;
const int MO = 1e9 + 7;
int dp[2][(1 << N) + 5];
int id[N][N];
int n, m;

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

class CampLunch {
	public:
	int count(int NN, int M, vector <string> a) {
        int cur = 0;
        n = NN, m = M;
        REP(i, n) {
            REP(j, m) {
                id[i][j] = a[i][j] - 'A';
            }
        }
        MST(dp, 0);
        dp[0][0] = 1;
        REP(i, n * m) {
            int x = i / m, y = i % m;
            //cout << x << ' ' << y << endl;
            REP(st, 1 << m) if (dp[cur][st]) {
                if (st & (1 << id[x][y])) {
                    add(dp[cur ^ 1][st ^ (1 << id[x][y])], dp[cur][st]);
                    continue;
                }
                //1 * 1
                add(dp[cur ^ 1][st], dp[cur][st]);
                //1 * 2
                if (y + 1 < m && !(st & (1 << id[x][y + 1]))) {
                    add(dp[cur ^ 1][st | (1 << id[x][y + 1])], dp[cur][st]);
                }
                //2 * 1
                if (x + 1 < n) {
                    add(dp[cur ^ 1][st | (1 << id[x][y])], dp[cur][st]);
                }
            }
            cur ^= 1;
            REP(st, 1 << m) dp[cur ^ 1][st] = 0;
            //REP(st, 1 << m) {
            //    cout << dp[cur][st] << ' ';
            //}
            //cout << endl;
        }
        return dp[cur][0];
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"AB","AB"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; string Arr2[] = {"ABC","ABC"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 22; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; string Arr2[] = {"ABC","BAC"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {"A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 10; string Arr2[] = {"ABDEFHIGJC"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 89; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 16; int Arg1 = 16; string Arr2[] = {"ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 950052677; verify_case(5, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	CampLunch ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
