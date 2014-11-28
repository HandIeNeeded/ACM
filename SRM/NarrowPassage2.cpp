#line 2 "NarrowPassage2.cpp"

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
const int MOD = (int) 1e9 + 7;
int c[N][N], fact[N];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int divide(vector<int> &w, int mx) {
	if (SZ(w) <= 1) return 1;
	vector<int> free, left, right;
	int n = SZ(w);
	int largest = -1, id = -1;
	REP(i, n) {
		if (w[i] > largest) {
			largest = w[i];
			id = i;
		}
	}
	REP(i, n) {
		if (i != id && w[i] + largest <= mx) {
			free.push_back(w[i]);
		}
		else if (i < id) {
			left.push_back(w[i]);
		}
		else if (i > id) {
			right.push_back(w[i]);
		}
	}
	int l = divide(left, mx), r = divide(right, mx);
	return 1ll * l * r % MOD * c[n][SZ(free)] % MOD * fact[SZ(free)] % MOD;
}

class NarrowPassage2 {
	public:
	int count(vector <int> s, int mx) {
		int n = SZ(s);
		REPP(i, 0, n) {
			c[i][i] = c[i][0] = 1;
			REPP(j, 1, i - 1) {
				c[i][j] = c[i - 1][j];
				add(c[i][j], c[i - 1][j - 1]);
			}
			if (i <= 1) {
				fact[i] = 1;
			}
			else {
				fact[i] = 1ll * i * fact[i - 1] % MOD;
			}
		}

		return divide(s, mx);
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); 
			if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); 
		}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 6; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 227020758; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,4,6,1,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 60; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = 1; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	NarrowPassage2 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
