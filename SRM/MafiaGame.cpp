#line 2 "MafiaGame.cpp"

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

class MafiaGame {
	public:
	double probabilityToLose(int N, vector <int> d) {
		int n = SZ(d);
		int cnt[505] = {0};
		REP(i, n) cnt[d[i]]++;
		REP(i, N - n) {
			int mi = INF, id = -1;
			REP(j, N) {
				if (cnt[j] < mi) {
					mi = cnt[j];
					id = j;
				}
			}
			cnt[id]++;
		}
		
		int mx = 0;
		REP(i, N) {
			if (cnt[i] > mx) {
				mx = cnt[i];
			}
		}
		int tot = 0;
		REP(i, N) {
			if (cnt[i] == mx) tot++;
		}
		if (tot == 1) return 1.0;
		int tmp = tot;
		while (tmp != 1 && N % tmp) {
			tmp = N % tmp;
			if (tmp == 1) return 1.0 / tot;
			else if (N % tmp == 0) {
				return 0.0;
			}
		}
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 23; int Arr1[] = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.14285714285714285; verify_case(3, Arg2, probabilityToLose(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	MafiaGame ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
