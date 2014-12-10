#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cstring>
#include <queue>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a)) 
#define MP make_pair

using namespace std;

const int N = 362880;
const int SZ = 10;
unordered_map<int, int> Hash;
const string dir = "ULRD", turn = "RDUL";
int mp[SZ][SZ], nex[N][4];
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
pair<int, int> pre[SZ][SZ];

void Init() {
	int now = 0;
	string tmp = "012345678";
	MST(nex, -1);
	do{
		int ans = 0;
		REP(i, 9) ans = 10 * ans + tmp[i] - '0';
		Hash[ans] = now++;
	}while (next_permutation(tmp.begin(), tmp.end()));

	tmp = "012345678";
	int i = 0;
	do{
		int pos = tmp.find('8');
		if (pos > 2) {
			string now = tmp;
			swap(now[pos], now[pos - 3]);
			nex[i][0] = Hash[stoi(now)];
		}

		if (pos < 6) {
			string now = tmp;
			swap(now[pos], now[pos + 3]);
			nex[i][3] = Hash[stoi(now)];
		}

		if (pos % 3) {
			string now = tmp;
			swap(now[pos], now[pos - 1]);
			nex[i][1] = Hash[stoi(now)];
		}

		if (pos % 3 != 2) {
			string now = tmp;
			swap(now[pos], now[pos + 1]);
			nex[i][2] = Hash[stoi(now)];
		}
		i++;
	}while (next_permutation(tmp.begin(), tmp.end()));
}

struct Puzzle{
	int pre[N], st;
	bool vis[N];
	string ans;

	Puzzle(int s = 0): st(s) {}

	bool Solve() {
		queue<int> q;
		q.push(st), vis[st] = 1, pre[st] = -1;

		while (q.size()) {
			st = q.front(); q.pop();
			if (st == 0) {
				break;
			}
			else {
				REP(i, 4) if (nex[st][i] >= 0 && !vis[nex[st][i]]){
					int y = nex[st][i];
					vis[y] = 1;
					pre[y] = st;
					q.push(y);
				}
			}
		}
		if (vis[0]) {
			int now = 0;
			while (pre[now] >= 0) {
				REP(i, 4) if (nex[now][i] == pre[now]) {
					ans += dir[3 - i];
				}
				now = pre[now];
			}
			reverse(ans.begin(), ans.end());
			return 1;
		}
		else return 0;
	}
};

bool ban[SZ][SZ], vis[SZ][SZ];

struct Puzzle_Solver{
	int sz;
	string ans;
	vector<vector<int> > mp;
	pair<int, int> pos[SZ * SZ];

	Puzzle_Solver() {}
	Puzzle_Solver(int s, vector<vector<int> > tmp) :sz(s), mp(tmp) {
		ans = string();
		prepare();
	}

	void prepare() {
		vector<int> tmp;
		REP(i, sz) REP(j, sz) {
			tmp.push_back(mp[i][j]);
		}
		sort(tmp.begin(), tmp.end());
		REP(i, sz) REP(j, sz) {
			mp[i][j] = lower_bound(tmp.begin(), tmp.end(), mp[i][j]) - tmp.begin();
			pos[mp[i][j]] = MP(i, j);
		}
	}

	int getnum(int x, int y) {
		return x * sz + y;
	}

	int gethash() {
		int ans = 0;
		REP(i, 3) {
			REP(j, 3) {
				ans = 10 * ans + mp[i][j];
			}
		}
		return Hash[ans];
	}

	void move(int sx, int sy, int ex, int ey) {
		int a = mp[sx][sy], b = mp[ex][ey];
		swap(pos[a], pos[b]);
		swap(mp[sx][sy], mp[ex][ey]);
	}

	bool good(int x, int y) {
		if (x >= 0 && x < sz && y >= 0 && y < sz) {
			return !ban[x][y];
		}
		else {
			return 0;
		}
	}

	char getdir(int a, int b, int c, int d) {
		if (a == c) {
			if (b > d) return 'L';
			else return 'R';
		}
		else if (b == d){
			if (a > c) return 'U';
			else return 'D';
		}
		return 'X';
	}

	void fly(int a, int b, int c, int d, int ty) {
		if (a == c && b == d) return ;
		if (ty == 0) {
			while (a < 2) {
				move(a, b, a + 1, b);
				a++;
				ans += 'D';
			}
			while (abs(b - d)) {
				if (b > d) {
					move(a, b, a, b - 1);
					b--;
					ans += 'L';
				}
				else {
					move(a, b, a, b + 1);
					b++;
					ans += 'R';
				}
			}
			while (a > 1) {
				move(a, b, a - 1, b);
				a--;
				ans += 'U';
			}
		}
		else {
			while (b < 2) {
				move(a, b, a, b + 1);
				b++;
				ans += 'R';
			}
			while (abs(a - c)) {
				if (a > c) {
					move(a, b, a - 1, b);
					a--;
					ans += 'U';
				}
				else {
					move(a, b, a + 1, b);
					a++;
					ans += 'D';
				}
			}
			while (b > 1) {
				move(a, b, a, b - 1);
				b--;
				ans += 'L';
			}
		}
	}

	void goahead(int bx, int by, int x, int y) {
		int mx = sz * sz - 1;
		vector<pair<int, int> > path;
		int sx = pos[mx].first, sy = pos[mx].second;
		bfs(sx, sy, x, y, bx, by, path);
		REP(i, path.size()) {
			ans += getdir(sx, sy, path[i].first, path[i].second);
			move(sx, sy, path[i].first, path[i].second);
			sx = path[i].first, sy = path[i].second;
		}
	}

	void go(int sx, int sy, vector<pair<int, int> > &path) {
		REP(i, path.size()) {
			goahead(sx, sy, path[i].first, path[i].second);
			move(sx, sy, path[i].first, path[i].second);
			ans += getdir(path[i].first, path[i].second, sx, sy);
			sx = path[i].first, sy = path[i].second;
		}
	}

	void bfs(int sx, int sy, int ex, int ey, int bx, int by, vector<pair<int, int> > &p) {
		MST(vis, 0), MST(pre, -1);
		queue<int> q;
		int x, y;
		q.push(sx), q.push(sy);
		vis[sx][sy] = 1, pre[sx][sy] = MP(-1, -1);
		while (q.size()) {
			int tx = q.front(); q.pop();
			int ty = q.front(); q.pop();
			if (tx == ex && ty == ey) {
				break;
			}
			REP(i, 4) {
				x = tx + dx[i];
				y = ty + dy[i];
				if (good(x, y) && !vis[x][y] && (x != bx || y != by)) {
					pre[x][y] = MP(tx, ty);
					q.push(x), q.push(y);
					vis[x][y] = 1;
				}
			}
		}
		x = ex, y = ey;
		while (pre[x][y].first >= 0 && pre[x][y].second >= 0) {
			p.push_back(MP(x, y));
			ex = x, ey = y;
			x = pre[ex][ey].first, y = pre[ex][ey].second;
		}
		reverse(p.begin(), p.end());
	}
 
	void recover(int x, int y) {
		int num = getnum(x, y), mx = sz * sz - 1;
		vector<pair<int, int> > path;
		if (pos[num].first == x && pos[num].second == y) return ;
		else {
			int sx = pos[num].first, sy = pos[num].second;
			if (abs(sx - x) + abs(sy - y) == 1 && mp[x][y] == mx) {
				move(x, y, sx, sy);
				if (x == sx) {
					if (y > sy) ans += 'L';
					else {
						ans += 'R';
					}
				}
				else {
					if (x > sx) ans += 'U';
					else ans += 'D';
				}
				return ;
			}

			if (x == 0 && y == sz - 1) {
				bfs(sx, sy, x + 1, y - 1, -1, -1, path);
				go(sx, sy, path);
				fly(pos[mx].first, pos[mx].second, x + 1, y - 2, 0);
				move(x + 1, y - 2, x, y - 2);//"U"
				move(x, y - 2, x , y - 1);//"R"
				move(x, y - 1, x + 1, y - 1); //"D"
				move(x + 1, y - 1, x + 1, y);//"R"
				move(x + 1, y, x, y);//"U"
				move(x, y, x, y - 1);//"L"
				move(x, y - 1, x, y - 2);//"L"
				move(x, y - 2, x + 1, y - 2);//"D"
				ans += "URDRULLD";
			}
			else if (x == sz - 1 && y == 0) {
				bfs(sx, sy, x - 1, y + 1, -1, -1, path);
				go(sx, sy, path);
				fly(pos[mx].first, pos[mx].second, x - 2, y + 1, 1);
				move(x - 2, y + 1, x - 2, y);//"L"
				move(x - 2, y, x - 1, y);//"D"
				move(x - 1, y, x - 1, y + 1); //"R"
				move(x - 1, y + 1, x, y + 1);//"D"
				move(x, y + 1, x, y);//"L"
				move(x, y, x - 1, y);//"U"
				move(x - 1, y, x - 2, y);//"U"
				move(x - 2, y, x - 2, y + 1);//"R"
				ans += "LDRDLUUR";
			}
			else {
				bfs(sx, sy, x, y, -1, -1, path);
				go(sx, sy, path);
			}
		}
	}

	bool try4() {
		string now;
		int pos = 0;
		const int f[4] = {1, 3, 0, 2};
		REP(i, 2) REP(j, 2) {
			now += (char) (mp[i][j] + '0');
		}
		REP(step, 100) {
			pos = now.find('3');
			swap(now[pos], now[f[pos]]);
			ans += turn[pos];
			if (now == "0123") {
				return 1;
			}
		}
		return 0;
	}

	bool Solve() {
		if (sz == 1) {
			return 1;
		}
		else if (sz == 2) {
			return try4();
		}
		else if (sz == 3) {
			struct Puzzle AsZ(gethash());
			bool res = AsZ.Solve();
			ans += AsZ.ans;
			return res;
		}
		else {
			MST(ban, 0);
			REP(i, sz) recover(0, i), ban[0][i] = 1;
			REP(i, sz) recover(i, 0), ban[i][0] = 1;
			vector<vector<int> > tmp;
			REPP(i, 1, sz - 1) {
				vector<int> now;
				REPP(j, 1, sz - 1) {
					now.push_back(mp[i][j]);
				}
				tmp.push_back(now);
			}
			struct Puzzle_Solver AsZ(sz - 1, tmp);
			bool res = AsZ.Solve();
			ans += AsZ.ans;
			return res;
		}
	}
}AsZ;

//0-N^2-1, N^2-1 for blank
bool getask() {
	int sz;
	if (!(cin >> sz)) return 0;
	REP(i, sz) REP(j, sz) {
		if (cin >> mp[i][j]) {
			continue;
		}
		else return 0;
	}
	vector<vector<int> > tmp;
	REP(i, sz) {
		vector<int> now;
		REP(j, sz) {
			now.push_back(mp[i][j]);
		}
		tmp.push_back(now);
	}
	AsZ = Puzzle_Solver(sz, tmp);
	return 1;
}

int main() {
	// freopen("cf.in", "r", stdin);
	ios :: sync_with_stdio(0);

	Init();

	while (getask()) {
		if (AsZ.Solve()) {
			cout << "Solution found!" << endl;
			cout << AsZ.ans << endl;
		}
		else {
			cout << "No solution!" << endl;
		}
	}

	return 0;
}