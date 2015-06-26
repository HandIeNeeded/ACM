#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define MST(a, b) memset(a, b, sizeof(a))
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)

using namespace std;

const int N = 2800;
int dx[] = {
	1, 0, -1, 0
};

int dy[] = {
	0, 1, 0, -1
};

struct Tree{
	vector<int> edge[N];
	int rt, tot, n, dep[N], id, mx;
	char mp[55][55];
	bool vis[N], use[55][55];
	int num[55][55];

	bool dfs(int x, int target, int &a, int &b, int dep = 0) {
		vis[x] = 1;
		if (x == target) {
			if (dep == mx / 2) a = x;
			if (dep == (mx + 1) / 2) b = x;
			return 1;
		}
		for (auto &y: edge[x]) {
			if (!vis[y]) {
				if (dfs(y, target, a, b, dep + 1)) {
					if (dep == mx / 2) a = x;
					if (dep == (mx + 1) / 2) b = x;
					return 1;
				}
			}
		}
		return 0;
	}

	void bfs(int x) {
		queue<int> q;
		REP(i, tot) vis[i] = 0;
		q.push(x), vis[x] = 1, dep[x] = 0;
		mx = id = -1;
		while (q.size()) {
			x = q.front(); q.pop();
			for (auto &y: edge[x]) {
				if (!vis[y]) {
					q.push(y), vis[y] = 1;
					dep[y] = dep[x] + 1;
				}
			}
		}
		REP(i, tot) if (dep[i] > mx) {
			mx = dep[i], id = i;
		}
	}

	bool good(int x, int y) {
		return x >= 0 && x < n + 2 && y >= 0 && y < n + 2;
	}

	void go(int x, int y, int id) {
		num[x][y] = id, use[x][y] = 1;
		REP(i, 4) {
			int tx = x + dx[i], ty = y + dy[i];
			if (good(tx, ty) && mp[x][y] == mp[tx][ty] && !use[tx][ty]) {
				go(tx, ty, id);
			}
		}
	}

	void get(vector<string> &tmp) {
		tot = rt = 0;
		n = tmp.size();
		REPP(i, 0, n + 1) {
			REPP(j, 0, n + 1) {
				mp[i][j] = '#';
			}
		}
		REP(i, n) {
			REP(j, n) {
				mp[i + 1][j + 1] = tmp[i][j];
			}
		}
		//REP(i, n + 2) {
		//	cout << mp[i] << endl;
		//}
		queue<int> q;
		REP(i, n + 2) REP(j, n + 2) use[i][j] = 0;
		REP(i, n + 2) REP(j, n + 2) {
			if (use[i][j]) continue;
			go(i, j, tot++);
		}
		//REP(i, n + 2) {
		//	REP(j, n + 2) {
		//		cout << num[i][j] << ' ';
		//	}
		//	cout << endl;
		//}
		REP(i, tot) vis[i] = 0;
		REP(i, n + 2) {
			REP(j, n + 2) if (!vis[num[i][j]]) {
				REP(k, 4) {
					int tx = i + dx[k], ty = j + dy[k];
					if (good(tx, ty) && num[tx][ty] < num[i][j]) {
						vis[num[i][j]] = 1;
						edge[num[i][j]].push_back(num[tx][ty]);
						edge[num[tx][ty]].push_back(num[i][j]);
						break;
					}
				}
			}
		}
		rt = 0;
		//int start, end;
		//bfs(0), start = id;
		//bfs(start), end = id;
		//int a, b;
		//REP(i, tot) vis[i] = 0;
		//dfs(start, end, a, b);
		//if (mx & 1) {
		//	rt = tot++;
		//	edge[rt].push_back(a), edge[rt].push_back(b);
		//	edge[a].erase(find(edge[a].begin(), edge[a].end(), b));
		//	edge[b].erase(find(edge[b].begin(), edge[b].end(), a));
		//	edge[a].push_back(rt), edge[b].push_back(rt);
		//	//cout << edge[a].size() << ' ' << edge[b].size() << endl;
		//	//for (auto &y: edge[a]) {
		//	//	cout << y << ' ';
		//	//}
		//	//cout << endl;
		//}
		//else {
		//	rt = a;
		//}
	}

	string getstr(int x, int p = -1) {
		string res;
		vector<string> ans;
		for (auto &y: edge[x]) {
			if (y != p) {
				ans.push_back(getstr(y, x));
			}
		}
		sort(ans.begin(), ans.end());
		for (auto &s: ans) res += s;
		res  = '(' + res + ')';
		return res;
	}
};

class Balance {
    public:
    string canTransform(vector <string> initial, vector <string> target) {
		Tree A, B;
		A.get(initial), B.get(target);
		if (A.mx != B.mx) return "Impossible";
		//cout << A.getstr(A.rt) << endl;
		//cout << B.getstr(B.rt) << endl;
		return A.getstr(A.rt) == B.getstr(B.rt) ? "Possible" : "Impossible";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(0, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".#",
 "##"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...",
 ".#.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"###",
 "#.#",
 "###"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".#.#.......",
 "####.###...",
 ".....####..",
 "..##.#.##.#",
 ".##..#.##.#",
 ".#######...",
 ".#....###.#",
 ".##.#.#....",
 "..#...#...#",
 "..#####...#",
 "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"...........",
 ".###....#..",
 ".#.#..#....",
 ".###.......",
 ".#####.....",
 ".#...#####.",
 ".#.#.....#.",
 ".#.#####.#.",
 ".#.......#.",
 ".#########.",
 "..........."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(3, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".....", ".###.", ".#.#.", ".###.", "....."};
 vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".....", ".###.", ".....", "#####", "....."};
 vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(4, Arg2, canTransform(Arg0, Arg1)); }

// END CUT HERE

};//Created by yuzhou627

// BEGIN CUT HERE
int main() {
    Balance ___test;
    clock_t st = clock(), ed;

    ___test.run_test(-1);

    ed = clock();
    cout << endl << "Time: " << fixed << setprecision(7) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
// END CUT HERE
