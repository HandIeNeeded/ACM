#line 2 "ChocolateDividingEasy.cpp"

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

const int N = 55;
int mp[N][N], sum[N][N];
int n, m;

int getsum(int x, int y, int p, int q) {
	return sum[p][q] - sum[x - 1][q] - sum[p][y - 1] + sum[x - 1][y - 1];
}

int get(int i, int j, int k, int t) {
	int ans = INF;
	ans = min(ans, getsum(1, 1, i, k));
	ans = min(ans, getsum(1, k + 1, i, t));
	ans = min(ans, getsum(1, t + 1, i, m));

	ans = min(ans, getsum(i + 1, 1, j, k));
	ans = min(ans, getsum(i + 1, k + 1, j, t));
	ans = min(ans, getsum(i + 1, t + 1, j, m));

	ans = min(ans, getsum(j + 1, 1, n, k));
	ans = min(ans, getsum(j + 1, k + 1, n, t));
	ans = min(ans, getsum(j + 1, t + 1, n, m));

	return ans;
}

class ChocolateDividingEasy {
	public:
	int findBest(vector <string> chocolate) {
		n = SZ(chocolate), m = SZ(chocolate[0]);
		REPP(i, 1, n) REPP(j, 1, m) {
			mp[i][j] = chocolate[i - 1][j - 1] - '0';
		}
		REPP(i, 1, n) REPP(j, 1, m) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mp[i][j];
		}

		// REPP(i, 1, n) {
		// 	REPP(j, 1, m) {
		// 		cout << sum[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }

		int ans = 0;
		REPP(i, 1, n - 2) REPP(j, i + 1, n - 1) REPP(k, 1, m - 2) REPP(t, k + 1, m - 1) {
			ans = max(ans, get(i, j, k, t));
		}
		return ans;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"9768",
"6767",
"5313"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findBest(Arg0)); }
	void test_case_1() { string Arr0[] = {
"36753562",
"91270936",
"06261879",
"20237592",
"28973612",
"93194784"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(1, Arg1, findBest(Arg0)); }
	void test_case_2() { string Arr0[] = {
"012",
"345",
"678"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, findBest(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	ChocolateDividingEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
