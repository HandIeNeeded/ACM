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

#define MST(a, b) memset(a, b, sizeof(a))
#define DBG(x, s) cout << (x) << ' ' << (s) << endl
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define RED(i, n) for (int i = (int) (n - 1); i >= 0; --i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define REDD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)

using namespace std;

const LL LIM = 1LL << 62;
const double EPS = 1e-9;

const int N = 55;
const int M = 205;
const int INF = 0x3f3f3f3f;

struct MaxFlow{
	int edge, source, sink;
	int lvl[N], vis[N], cur[N];
	int fi[N], ne[M << 1], en[M << 1], cap[M << 1];
	
	void init(int S, int T) {
		source = S, sink = T;
		MST(fi, 0), edge = 1;
	}

	void _add(int x, int y, int z) {
		ne[++edge] = fi[x];
		fi[x] = edge;
		en[edge] = y;
		cap[edge] = z;
	}

	void add(int x, int y, int z) {
		_add(x, y, z);
		_add(y, x, 0);
	}
	
	bool bfs() {
		queue<int> q;
		MST(lvl, 0), MST(vis, 0);
		q.push(source);
		vis[source] = 1;

		while(q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && !vis[en[go]]) {
				int y = en[go];
				lvl[y] = lvl[x] + 1;
				q.push(y);
				vis[y] = 1;
			}
		}
		return vis[sink];
	}

	int dfs(int x, int flow) {
		if (x == sink || flow == 0) {
			return flow;
		}
		int ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
				ans += tmp;
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
				flow -= tmp;
				if (flow == 0) {
					return ans;
				}
			}
		}
		return ans;
	}

	int dinic() {
		int ans = 0;
		while (bfs()) {
			memcpy(cur, fi, sizeof(fi));
			ans += dfs(source, INF);
		}	
		return ans;
	}
}Flow;

int mp[N][N], g[N][N], n;
bool use[N][N];

void dfs(int x, int pre, int (*mp)[N]) {
	REP(i, n) {
		if(mp[x][i] && i != pre) {
			if (!use[x][i]) {
				use[x][i] = 1;
				Flow.add(i, x, INF);
			}
			dfs(i, x, mp);
		}
	}
}

class DoubleTree {
	public:
	int maximalScore(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> score) {
		MST(mp, 0), MST(g, 0), MST(use, 0);
		int ans = 0, sum = 0;
		n = SZ(score);
		REP(i, n) {
			if (score[i] >= 0) {
				sum += score[i];
			}
		}
		REP(i, n - 1) {
			mp[a[i]][b[i]] = mp[b[i]][a[i]] = 1;
			g[c[i]][d[i]] = g[d[i]][c[i]] = 1;
		}
		REP(i, n) {
			Flow.init(n, n + 1);
			int source = n, sink = n + 1;
			MST(use, 0);
			REP(j, n) {
				if (j != i && score[j] >= 0) {
					Flow.add(source, j, score[j]);
				}
				else if (j != i) {
					Flow.add(j, sink, -score[j]);
				}
			}
			REP(j, n) {
				if (mp[i][j]) {
					dfs(j, i, mp);
				}
				if (g[i][j]) {
					dfs(j, i, g);
				}
			}
			int tmp = sum - Flow.dinic();
			if (score[i] < 0) {
				tmp += score[i];
			}
			ans = max(ans, tmp);
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1000,24,100,-200}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1024; verify_case(0, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1000,24,100,200}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1324; verify_case(1, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {-1000,-24,-100,-200}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 0; verify_case(2, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {-1000,24,100,200}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 200; verify_case(3, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = {0,0,1,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,1,1,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4,5,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {-3,2,2,-1,2,2,-1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; verify_case(4, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arr0[] = {0,0,1,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0,0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4,5,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {-3,2,2,-1,2,2,-1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; verify_case(5, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
	DoubleTree ___test;
	clock_t st = clock(), ed;

	___test.run_test(-1);
	
	ed = clock();
	cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
// END CUT HERE
