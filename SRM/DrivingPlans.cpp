#line 2 "DrivingPlans.cpp"

#include <bits/stdc++.h>
#define dou double
#define LL long long
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int) a.size())
#define PII pair<int, int>
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define INF 2000000000
#define MOD 1000000009
#define N 2222

using namespace std;

int dp[N], d[2][N], n, vis[N], dis[N];
vector<int> mp[N], v[N];
queue<int> q;

struct cmp{
	bool operator () (const PII& a, const PII& b) {
		return a.first > b.first;
	}
};

void dijkstra(int x, int dis[N]) {
	priority_queue<PII, vector<PII>, cmp > q;
	REPP(i, 1, n) dis[i] = INF, vis[i] = 0;
	dis[x] = 0, vis[x] = 1;
	REPP(i, 1, n) if (i != x) q.push(MP(INF, i));
	int tot = 1, good = x;
	while (tot < n) {
		REP(i, SZ(mp[good])) if (!vis[mp[good][i]] && dis[mp[good][i]] > dis[good] + v[good][i]) {
			dis[mp[good][i]] = dis[good] + v[good][i];
			q.push(MP(dis[mp[good][i]], mp[good][i]));
		}
		good = q.top().second;
		vis[good] = 1;
		q.pop(); tot++;
	}
	if (x == 1) {
		REPP(i, 1, n) d[0][i] = dis[i];
	}
	else {
		REPP(i, 1, n) d[1][i] = dis[i];
	}
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int dfs(int x) {
	if (vis[x]) return dp[x];
	vis[x] = 1;
	REP(i, SZ(mp[x])) {
		if (d[1][x] == d[1][mp[x][i]] - v[x][i]) add(dp[x], dfs(mp[x][i]));
	}
	return dp[x];
}

bool ZERO(vector<int>& A, vector<int>& B, vector<int>& C) {
	REP(i, SZ(C)) if (C[i] == 0) {
		if (d[0][A[i]] + d[1][B[i]] == d[1][1] || d[1][A[i]] + d[0][B[i]] == d[1][1]) return 1;
	}
	return 0;
}

class DrivingPlans {
	public:
	int count(int NN, vector <int> A, vector <int> B, vector <int> C) {
		n = SZ(A);
		REP(i, n) {
			mp[A[i]].push_back(B[i]), v[A[i]].push_back(C[i]);
			mp[B[i]].push_back(A[i]), v[B[i]].push_back(C[i]);
		}
		n = NN;
		dijkstra(1, dis); dijkstra(n, dis);
		if (ZERO(A, B, C)) return -1;
		mem(vis); vis[1] = dp[1] = 1;
		dfs(n);
		return dp[n];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { 
		if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {1,1,2,3,4,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4,5,6,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2,3,3,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DrivingPlans ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
