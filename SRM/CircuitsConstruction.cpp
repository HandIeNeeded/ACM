#line 2 "CircuitsConstruction.cpp"

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
#define N 4222

using namespace std;

string s;
int tot, len;

vector<int> e[N];
int ty[N];

int build(int& pos) {
	int now, cnt = 0;
	if (s[pos] == 'A') {
		now = ++tot;
		ty[tot] = 1;
	}
	else if (s[pos] == 'B') {
		now = ++tot;
		ty[tot] = 2;
	}
	pos++;
	while (pos < len && cnt < 2) {
		if (s[pos] == 'X') {
			pos++;
			ty[++tot] = 0;
			e[now].push_back(tot);
			cnt++;
		}
		else cnt++, e[now].push_back(build(pos));
	}
	return now;
}

int dfs(int x) {
	if (ty[x] == 0) return 1;
	int tt = 0, rr = 0;
	tt = dfs(e[x][0]);
	rr = dfs(e[x][1]);
	if (ty[x] == 1) return tt + rr;
	return max(tt, rr);
}

class CircuitsConstruction {
	public:
	int maximizeResistance(string circuit, vector <int> conductors) {
		s = circuit, tot = 0;
		len = SZ(s);
		int now = 0;
		build(now);
		int n = dfs(1);
		sort(ALL(conductors));
		reverse(ALL(conductors));
		int ans = 0;
		REP(i, n) ans += conductors[i];
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BXBXX"; int Arr1[] = {8, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAXXAXAXX"; int Arr1[] = {1, 1, 2, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(1, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AXBXX"; int Arr1[] = {8, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(2, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BAAXBXXBXAXXBBAXXBXXAAXXX"; int Arr1[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 454; verify_case(3, Arg2, maximizeResistance(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	CircuitsConstruction ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
