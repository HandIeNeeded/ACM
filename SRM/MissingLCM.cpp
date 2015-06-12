#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;
const int N = 1e6 + 5;
int vis[N], p[N], tot;

void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
}
#define LL long long

class MissingLCM {
    public:
    int getMin(int n) {
 		prime();       
		LL ans = 0;
		for (int i = 0; p[i] <= n; i++) {
			int cnt = 0; 
			LL tmp = p[i];
			while (1LL * tmp * p[i] <= n) tmp = 1LL * tmp * p[i], cnt++;
			LL now = tmp;
			while (now <= n) now += tmp;
			ans = max(ans, now);
		}
		ans = max(ans, 1LL * n + 1);
		return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 6; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 8; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 10; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { int Arg0 = 42; int Arg1 = 82; verify_case(5, Arg1, getMin(Arg0)); }
	void test_case_6() { int Arg0 = 999999; int Arg1 = 1999966; verify_case(6, Arg1, getMin(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
    MissingLCM ___test;
    clock_t st = clock(), ed;

    ___test.run_test(6);

    ed = clock();
    cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
// END CUT HERE
