#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

long long ans[2][40];

void getans(int dep, vector<int> &a, int bit) {
	int n = a.size();
	if (n <= 1 || bit == 0) return ;
	vector<int> cnt0(n, 0), cnt1(n, 0);
	vector<int> ta, tb;
	vector<bool> has(n, 0);
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] & bit) {
			ta.push_back(a[i]);
			has[i] = 1;
			if (i == n - 1) {
				cnt1[i] = 1;
				cnt0[i] = 0;
			}
			else {
				cnt1[i] = cnt1[i + 1] + 1;
				cnt0[i] = cnt0[i + 1];
			}
		}
		else {
			tb.push_back(a[i]);
			if (i == n - 1) {
				cnt0[i] = 1;
				cnt1[i] = 0;
			}
			else {
				cnt0[i] = cnt0[i + 1] + 1;
				cnt1[i] = cnt1[i + 1];
			}
		}
	}
	long long ans0 = 0, ans1 = 0;
	REP(i, n - 1) {
		if (has[i]) {
			ans1 += cnt0[i + 1];
		}
		else {
			ans0 += cnt1[i + 1];
		}
	}
	ans[0][dep] += ans0;
	ans[1][dep] += ans1;
	getans(dep + 1, ta, bit >> 1), getans(dep + 1, tb, bit >> 1);
	return ;
}

void add(int &x, int y, int MO) {
	x += y;
	if (x >= MO) x -= MO;
}

class XorSequence {
	public:
	long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R) {
		vector<int> tmp(sz, 0);
		tmp[0] = A0, tmp[1] = A1;
		REPP(i, 2, sz - 1) {
			add(tmp[i], 1LL * tmp[i - 2] * P % N, N);
			add(tmp[i], 1LL * tmp[i - 1] * Q % N, N);
			add(tmp[i], R, N);
		}
		getans(0, tmp, N >> 1);
		long long res = 0;
		REP(i, 40) {
			res += max(ans[0][i], ans[1][i]);
		}
		return res;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 3; int Arg3 = 2; int Arg4 = 0; int Arg5 = 1; int Arg6 = 3; long long Arg7 = 8LL; verify_case(0, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 8; int Arg2 = 2; int Arg3 = 5; int Arg4 = 3; int Arg5 = 1; int Arg6 = 4; long long Arg7 = 13LL; verify_case(1, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 7; int Arg2 = 3; int Arg3 = 0; int Arg4 = 1; int Arg5 = 2; int Arg6 = 4; long long Arg7 = 12LL; verify_case(2, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 32; int Arg1 = 15; int Arg2 = 7; int Arg3 = 9; int Arg4 = 11; int Arg5 = 2; int Arg6 = 1; long long Arg7 = 60LL; verify_case(3, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 131072; int Arg1 = 131072; int Arg2 = 7; int Arg3 = 7; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; long long Arg7 = 0LL; verify_case(4, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_5() { int Arg0 = 131072; int Arg1 = 131070; int Arg2 = 411; int Arg3 = 415; int Arg4 = 398; int Arg5 = 463; int Arg6 = 9191; long long Arg7 = 4302679760LL; verify_case(5, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	XorSequence ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
