#line 2 "DrivingPlans.cpp"

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
#define MOD 1000000009
#define N 2111

using namespace std;

vector<int> e[N];
int imp[N], use[N], dis[N], vis[N];
int fi[N << 1], ne[N << 1], en[N << 1], v[N << 1], tot;
int dp[N], target;

void add(int x, int y, int z) {
	ne[++tot] = fi[x], fi[x] = tot, en[tot] = y, v[tot] = z;
}

void dijkstra() {
	memm(dis), mem(vis);
	dis[target] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(MP(dis[target], target));
	while (!q.empty()) {
		int x = q.top().second; q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (int go = fi[x]; go; go = ne[go]) {
			int y=  en[go];
			if (dis[y] == -1 || dis[y] > dis[x] + v[go]) {
				dis[y] = dis[x] + v[go];
				if (imp[x] == 1 || use[y] || use[x]) imp[y] = 1;
				else imp[y] = -1;
				q.push(MP(dis[y], y));
			}
			else if (dis[y] == dis[x] + v[go]) {
				if (imp[x] == 1 || use[x] || use[y]) imp[y] = 1;
			}
		}
	}
}

int dfs(int x) {
	if (x == 1) return 1;
	if (vis[x]) return dp[x];
	vis[x] = 1;
	for (int go = fi[x]; go; go = ne[go]) {
		int y = en[go];
		if (dis[y] == dis[x] + v[go]) {
			dp[x] += dfs(y);
			if (dp[x] >= MOD) dp[x] -= MOD;
		}
	}
	return dp[x];
}

class DrivingPlans {
	public:
	int count(int n, vector <int> A, vector <int> B, vector <int> C) {
		int sz = SZ(A);
		target = n;
		REP(i, sz) {
			add(A[i], B[i], C[i]);
			add(B[i], A[i], C[i]);
			if (C[i] == 0) use[A[i]] = use[B[i]] = 1;
		}
		dijkstra();
		if (imp[1] == 1) return -1;
		else {
			mem(vis);
			dfs(n);
			return dp[n];
		}
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {1,1,2,3,4,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4,5,6,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2,3,3,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	DrivingPlans ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
