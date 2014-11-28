#line 2 "GameOfSegments.cpp"

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
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define N 1111

using namespace std;
int sg[N], vis[N];

int Init(int n) {
	sg[0] = sg[1] = 0, sg[2] = 1;
	REPP(i, 3, n) {
		mem(vis);
		for (int j = 0, k = i - 2; j <= k; j++, k--) vis[sg[j] ^ sg[k]] = 1;
		int now = 0;
		while (vis[now]) now++;
		sg[i] = now;
	}
	return sg[n];
}

class GameOfSegments {
	public:
	int winner(int n) {
		return Init(n) ? 1 : 2;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 1; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 2; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { int Arg0 = 191; int Arg1 = 2; verify_case(3, Arg1, winner(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	GameOfSegments ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
