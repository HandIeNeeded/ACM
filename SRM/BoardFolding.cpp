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

#define MST(a, b) memset(a, b, sizeof(a))
#define DBG(x, s) cout << (x) << ' ' << (s) << endl
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define RED(i, n) for (int i = (int) (n - 1); i >= 0; --i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define REDD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)

using namespace std;

const int INF = 0x3f3f3f3f;
const LL LIM = 1LL << 62;
const double EPS = 1e-9;

const int N = 255;
const int MOD = 1234567891;
const int K = 79;
int row[N], col[N];
int mp[2][N][N];
LL f[2][N][N], tmp[N][N];
int n, m;

int tonum(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else if (c >= 'a' && c <= 'z') {
		return c - 'a' + 10;
	}
	else if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 36;
	}
	else if (c == '#') {
		return 62;
	}
	else if (c == '@') {
		return 63;
	}
	else return -1;
}

int can[N], dan[N];

void getmp(int ty) {
	MST(can, 0);
	MST(dan, 0);
	REPP(i, 1, m) {
		if (i == 1) can[i] = 1;
		else {
			for (int j = i - 1, k = i; j >= 1 && k <= m; --j, k++) {
				if (can[j] && col[j] == col[k]) {
					can[i] = 1;
					break;
				}
				else if (col[j] != col[k]) {
					can[i] = 0;
					break;
				}
			}
		}
	}

	REPP(i, 1, n) {
		if (i == 1) dan[i] = 1;
		else {
			for (int j = i - 1, k = i; j >= 1 && k <= n; --j, k++) {
				if (dan[j] && row[j] == row[k]) {
					dan[i] = 1;
					break;
				}
				else if (row[j] != row[k]) {
					dan[i] = 0;
					break;
				}
			}
		}
	}

	REPP(i, 1, n) REPP(j, 1, m) {
		f[ty][i][j] = dan[i] && can[j];
	}
}

class BoardFolding {
	public:
	int howMany(int N, int M, vector <string> compressedPaper) {
		n = N, m = M;
		//cout << N << ' ' << M << endl;
		MST(row, 0), MST(col, 0);
		MST(mp, 0);
		REP(i, n) REP(j, m) {
			mp[0][i + 1][j + 1] = (tonum(compressedPaper[i][j / 6]) >> (j % 6)) & 1;
		}

		REP(i, n) REP(j, m) {
			mp[1][i + 1][j + 1] = mp[0][n - i][m - j];
		}
		REP(ty, 2) {
			MST(row, 0), MST(col, 0);
			REPP(i, 1, n) {
				REPP(j, 1, m) {
					row[i] = ((row[i] + 3) * K + mp[ty][i][j]) % MOD;
				} 
			}
			REPP(j, 1, m) {
				REPP(i, 1, n) {
					col[j] = ((col[j] + 3) * K + mp[ty][i][j]) % MOD; 
				}
			}
			getmp(ty);
		}

		REPP(i, 1, n) {
			REPP(j, 1, m) {
				tmp[i][j] = tmp[i - 1][j] + tmp[i][j - 1] - tmp[i - 1][j - 1] + f[1][i][j];
			}
		}

		LL ans = 0;
		REPP(i, 1, n) {
			REPP(j, 1, m) {
				if (f[0][i][j]) {
					ans += tmp[n + 1 - i][m + 1 - j];
				}
			}
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"1", "3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 7; string Arr2[] = {"@@", "@@"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 84; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"6", "9", "9", "6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; string Arr2[] = {"0", "2", "6", "@", "4", "A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0", "2", "0"}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	BoardFolding ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
