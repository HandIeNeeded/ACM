#line 2 "GraphInversions.cpp"

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
#define LB(x) ((x) & (-(x)))

using namespace std;

int s[N], vis[N], k;
vector<int> e[N], a, b, v;
int best;

void add(int x, int qd) {
	while (x < N) {
		s[x] += qd;
		x += LB(x);
	}
}

int que(int x) {
	int re = 0;
	while (x) {
		re += s[x];
		x -= LB(x);
	}
	return re;
}

void dfs(int x, int inv, int dep) {
	vis[x] = 1;
	//cout << x << ' ' << inv << endl;
	if (dep == k) best = min(inv, best);
	else {
		REP(i, SZ(e[x])) if (!vis[e[x][i]]) {
			int inc = dep - que(v[e[x][i]]);
			add(v[e[x][i]], 1);
			dfs(e[x][i], inv + inc, dep + 1);
			add(v[e[x][i]], -1);
		}
	}
	vis[x] = 0;
}

class GraphInversions {
	public:
	int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
		k = K; v = V;
		int n = SZ(A);
		mem(s);
		REP(i, n) e[i].clear();
		REP(i, n) e[A[i]].push_back(B[i]), e[B[i]].push_back(A[i]);
		int ans = INF;
		REP(i, n) {
			mem(vis);
			best = INF;
			add(v[i], 1);
			dfs(i, 0, 1);
			add(v[i], -1);
			ans = min(best, ans);
		}
		if (ans == INF) ans = -1;
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { 
		if ((Case == -1) || (Case == 0)) test_case_0(); 
		if ((Case == -1) || (Case == 1)) test_case_1(); 
		if ((Case == -1) || (Case == 2)) test_case_2(); 
		if ((Case == -1) || (Case == 3)) test_case_3(); 
		if ((Case == -1) || (Case == 4)) test_case_4(); 
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40,50,60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 0; verify_case(0, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {60,40,50,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 1; verify_case(1, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 1; verify_case(2, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,2,5,3,7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = -1; verify_case(3, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {5,7,7,5,5,7,6,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,2,0,1,4,7,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {15,10,5,30,22,10,5,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = 3; verify_case(4, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	GraphInversions ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
