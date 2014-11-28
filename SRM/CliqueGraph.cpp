#line 2 "CliqueGraph.cpp"

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
#define N 5555

using namespace std;

int d[N][N], s[N], vis[N];
vector<int> e[N];

void bfs(int x) {
	queue<int> q;
	d[x][x] = 0;
	mem(vis);
	q.push(x); vis[x] = 1;
	while (!q.empty()) {
		int y = q.front(); q.pop();
		REP(i, SZ(e[y])) {
			if (!vis[e[y][i]]) {
				d[x][e[y][i]] = d[x][y] + 1;
				REPP(i, 1, n) a[i] += 100;
				vis[e[y][i]] = 1;
				q.push(e[y][i]);
			}
		}
	}
}

class CliqueGraph {
	public:
	long long calcSum(int n, vector <int> V, vector <int> S) {
		int sv = SZ(V), ss = SZ(S);
		REPP(i, 1, ss) s[i] = s[i - 1] + S[i - 1];
		REPP(i, 1, ss) {
			REPP(j, s[i - 1], s[i] - 1) {
				e[V[j]].push_back(i + n - 1);
				e[i + n - 1].push_back(V[j]);
			}
		}
		REP(i, n) bfs(i);
		LL ans = 0;
		REP(i, n) REP(j, n) ans += d[i][j];
		return ans >> 2;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {0,1,2,0,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 8LL; verify_case(0, Arg3, calcSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {0,1,2,3,1,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 12LL; verify_case(1, Arg3, calcSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 15; int Arr1[] = {1,3,5,7,9,11,13,0
,2,3,6,7,10,11,14,0
,4,5,6,7,12,13,14,0
,8,9,10,11,12,13,14,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8,8,8,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 130LL; verify_case(2, Arg3, calcSum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	CliqueGraph ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
