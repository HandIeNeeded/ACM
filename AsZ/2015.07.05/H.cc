#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 205;

vector<int> edge[N << 1];
int n;
vector<int> p[N][N];
string ans[N];
char s[N];

bool process(int tot, int &now) {
	REPP(i, 0, tot) if (p[tot][i].size()) {
		while (p[tot][i].size()) {
			if (p[tot][i + 1].size() == 0) return 0;
			p[tot - 1][i].push_back(++now);
			assert(edge[now].size() == 0);
			edge[now].push_back(p[tot][i].back());
			edge[now].push_back(p[tot][i + 1].back());
			p[tot][i].pop_back();
			p[tot][i + 1].pop_back();
		}
	}
	return 1;
}

void dfs(int x, int dep = 0) {
	if (!edge[x].size()) {
		s[dep] = 0;
		ans[x] = string(s);
	}
	else {
		s[dep] = '1';
		dfs(edge[x][0], dep + 1);
		s[dep] = '0';
		dfs(edge[x][1], dep + 1);
	}
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("huffman.in", "r", stdin);
	freopen("huffman.out", "w", stdout);
	int n;
	while (cin >> n, n) {
		int mx = 0;
		REPP(i, 1, n) {
			int x, y;
			cin >> x >> y;
			p[x + y][x].push_back(i);
			mx = max(mx, x + y);
		}
		int now = n;
		bool flag = 1;
		for (int i = mx; i >= 1; i--) {
			flag &= process(i, now);
			if (!flag) break;
		}
		flag &= p[0][0].size() == 1;
		p[0][0].clear();
		assert(now < 2 * n);
		if (!flag) {
			cout << "No" << endl;
		}
		else {
			dfs(now);
			cout << "Yes" << endl;
			REPP(i, 1, n) {
				//REP(j, ans[i].size()) {
				//	ans[i][j] = '0' ^ '1' ^ ans[i][j];
				//}
				cout << ans[i] << endl;
			}
		}
		REPP(i, 1, mx) {
			REPP(j, 0, i) {
				p[i][j].clear();
			}
		}
		REPP(i, 1, now) edge[i].clear();
	}
    return 0;
}

