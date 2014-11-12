#line 2 "BlockTheBlockPuzzle.cpp"

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
#define INF 200
#define MOD 1000000007
#define N 2222

using namespace std;

int cnt, source, sink, tot, fi[N], en[N << 4], ne[N << 4], e[N << 4];
int lvl[N], vis[N], cur[N];
char mp[55][55];
int vIn[55][55], vOut[55][55];
int n, sx, sy;

void _add(int x, int y, int flow) {
	ne[++tot] = fi[x], fi[x] = tot, en[tot] = y;
	e[tot] = flow;
}

void add(int x, int y, int z) {
	_add(x, y, z);
	_add(y, x, 0);
}

int bfs() {
	mem(lvl), mem(vis);
	queue<int> q;
	q.push(source), vis[source] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int go = fi[x]; go; go = ne[go]) {
			int y = en[go];
			if (!vis[y] && e[go]) {
				lvl[y] = lvl[x] + 1;
				q.push(y), vis[y] = 1;
			}
		}
	}
	return lvl[sink];
}

#define inv(x) ((x) + ((x) & 1 ? 1 : -1))

int dfs(int x, int flow) {
	int ans = 0, tmpflow = 0;
	if (x == sink || flow == 0) return flow;
	for (int& go = cur[x]; go; go = ne[go]) {
		int y = en[go];
		if (lvl[y] == lvl[x] + 1 && (tmpflow = dfs(y, min(flow, e[go]))) > 0) {
			e[go] -= tmpflow;
			e[inv(go)] += tmpflow;
			ans += tmpflow;
			flow -= tmpflow;
			if (flow == 0) break;
		}
	}
	return ans;
}

int Dinic() {
	int maxflow = 0;
	while (bfs()) {
		REPP(i, 1, cnt) cur[i] = fi[i];
		maxflow += dfs(source, INF);
	}
	return maxflow;
}

bool good(int x, int y) {return x >= 0 && x < n && y >= 0 && y < n;}

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

 void Init() {
 	source = 1, sink = 2;
 	tot = 0, mem(fi);
 	REP(i, n) REP(j, n) {
 		if (i % 3 == sx % 3 && j % 3 == sy % 3) {
 			if (mp[i][j] == 'H') continue;
			if(mp[i][j] == '.') add(vIn[i][j], vOut[i][j], 1);
			if (mp[i][j] == 'b') add(vOut[i][j], sink, INF);
			REP(k, 4) {
				int x = i, y = j;
				int xx = i + 3 * dx[k], yy = j + 3 * dy[k];
				if (good(xx, yy) && mp[xx][yy] != 'H') {
					if (mp[x + dx[k]][y + dy[k]] == 'b' || mp[x + 2 * dx[k]][y + 2 * dy[k]] == 'b') {
						add(vOut[i][j], vIn[xx][yy], INF);
					}
					else {
						int cost = 0;
						if (mp[x + dx[k]][y + dy[k]] == '.') cost++;
						if (mp[x + 2 * dx[k]][y + 2 * dy[k]] == '.') cost++;
						if (cost) add(vOut[i][j], vIn[xx][yy], cost);
					}
				}
			}
 		}
 	}
}

class BlockTheBlockPuzzle {
	public:
	int minimumHoles(vector <string> board) {
		n = SZ(board);
		REP(i, n) REP(j, n) mp[i][j] = board[i][j];
		REP(i, n) REP(j, n) {
			if (board[i][j] == '$') {
				sx= i, sy = j;
				vIn[sx][sy] = vOut[sx][sy] = 1;
			}
		}
		cnt = 2;
		REP(i, n) REP(j, n) if (i % 3 == sx % 3 && j % 3 == sy % 3) {
			if (board[i][j] == '.' || board[i][j] == 'b') {
				if (board[i][j] == '.') {
					vIn[i][j] = ++cnt;
					vOut[i][j] = ++cnt;
				}
				else vIn[i][j] = vOut[i][j] = ++cnt;
			}
		}
		Init();
		int cut = Dinic();
		if (cut >= INF) return -1;
		else return cut;
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
	void test_case_0() { string Arr0[] = {"b..$",
 "....",
 "HHHH",
 "HHHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimumHoles(Arg0)); }
	void test_case_1() { string Arr0[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH.....H..",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minimumHoles(Arg0)); }
	void test_case_2() { string Arr0[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH........",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minimumHoles(Arg0)); }
	void test_case_3() { string Arr0[] = {"b..$...",
 "...H...",
 ".......",
 "b..b..b",
 "...H...",
 ".......",
 "b..b..b"}

; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minimumHoles(Arg0)); }
	void test_case_4() { string Arr0[] = {"b..b..b",
 "..b..b.",
 ".......",
 "b..$bbb",
 ".b.....",
 "....b..",
 "b..b..b"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, minimumHoles(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BlockTheBlockPuzzle ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
