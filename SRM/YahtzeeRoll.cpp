#line 2 "YahtzeeRoll.cpp"

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
#define N 55

using namespace std;

vector<int> d;
vector<int> change;

int score;

int three_two() {
	int cnt[10] = {0};
	REP(i, 5) cnt[d[i]]++;
	bool three = 0, two = 0;
	REP(i, 10) if (cnt[i] == 3) three = 1; else if (cnt[i] == 2) two = 1;
	if (three && two) return 25;
	return 0;
}

int small_str() {
	int cnt[10] = {0};
	REP(i, 5) cnt[d[i]]++;
	REPP(i, 1, 3) {
		bool good = 1;
		REP(j, 4) good = good && (cnt[i + j] >= 1);
		if (good) return 30;
	}
	return 0;
}

int large_str() {
	int cnt[10] = {0};
	REP(i, 5) cnt[d[i]]++;
	REPP(i, 1, 2) {
		bool good = 1;
		REP(j, 5) good = good && (cnt[i + j] >= 1);
		if (good) return 40;
	}
	return 0;
}

int all_kill() {
	int cnt[10] = {0};
	REP(i, 5) cnt[d[i]]++;
	REP(i, 10) if (cnt[i] == 5) return 50;
	return 0;
}

void dfs(int dep, int st) {
	if (dep > 5) {
		if (all_kill()) score += 50;
		else if (large_str()) score += 40;
		else if (small_str()) score += 30;
		else if (three_two()) score += 25;
		return ;
	}
	if (st & (1 << dep)) {
		REPP(i, 1, 6) {
			d[dep] = i;
			dfs(dep + 1, st);
		}
	}
	else {
		dfs(dep + 1, st);
	}
}

int mypow(int x, int y) {
	int re = 1;
	REP(i, y) re *= x;
	return re;
}

double cal(int st) {
	score = 0;
	int cnt = 0;
	REP(i, 5) if (st & (1 << i)) cnt++;
	dfs(0, st);
	return 1.0 * score / mypow(6, cnt);
}

class YahtzeeRoll {
	public:
	double bestChoice(vector <int> dice) {
		double ans = 0.0;
		REP(i, (1 << 5)) {
			d = dice;
			double tmp = cal(i);
			ans = max(ans, tmp);
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 1, 1, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 8.333333333333334; verify_case(0, Arg1, bestChoice(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 1, 1, 2, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 25.0; verify_case(1, Arg1, bestChoice(Arg0)); }
	void test_case_2() { int Arr0[] = { 2, 3, 4, 5, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 33.333333333333336; verify_case(2, Arg1, bestChoice(Arg0)); }
	void test_case_3() { int Arr0[] = { 2, 2, 3, 4, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 17.77777777777778; verify_case(3, Arg1, bestChoice(Arg0)); }
	void test_case_4() { int Arr0[] = { 6, 1, 3, 5, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.722222222222221; verify_case(4, Arg1, bestChoice(Arg0)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	YahtzeeRoll ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
