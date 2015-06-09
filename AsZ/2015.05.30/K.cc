#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 405;
const int M = 3005;
char s[N];

struct Unit{
	int l, r, w, h;
	char op;
};

struct tree{
	Unit a[N];
	char mp[M][M], op[N];
	int tot, top, id, num[N];

	void init() {
		tot = 0, top = 1, id = 0;
		op[1] = '(';
	}

	bool priority(char a, char b) {
		if (b == '+' || b == '-') {
			return a != '(';
		}
		else if (b == '^') {
			return 0;
		}	
		else {
			return a == '*' || a == '/' || a == '^';
		}
	}

	void solve(char *s, int len) {
		s[len++] = ')';
		REP(i, len) {
			if (s[i] == '(') op[++top] = s[i];
			else if (s[i] == ')') {
				while (top > 0 && op[top] != '(') {
					a[id].op = op[top], a[id].l = num[tot - 1], a[id].r = num[tot];
					a[id].h = max(a[a[id].l].h, a[a[id].r].h) + 2;
					a[id].w = a[a[id].l].w + a[a[id].r].w + 5;
					num[tot - 1] = id++;
					tot--, top--;
				}
				top--;
			}
			else if (isalpha(s[i])) {
				a[id].w = a[id].h = 1, a[id].l = a[id].r = 0, a[id].op = s[i];
				num[++tot] = id++;
			}
			else {
				while (top > 0 && priority(op[top], s[i])) {
					a[id].op = op[top], a[id].l = num[tot - 1], a[id].r = num[tot];
					a[id].h = max(a[a[id].l].h, a[a[id].r].h) + 2;
					a[id].w = a[a[id].l].w + a[a[id].r].w + 5;
					num[tot - 1] = id++;
					tot--, top--;
				}
				op[++top] = s[i];
			}
		}
		//cout << num[1] << endl;
		REP(i, a[num[1]].h) {
			REP(j, a[num[1]].w) {
				mp[i][j] = ' ';
			}
		}
		int r, r1 = -3, r2;
		dfs(num[1], 0, 0, r, r1, r2);
		print();
	}

	void dfs(int now, int x, int y, int &r, int &r1, int &r2) { // r1 [*] r2 a,b
		if (!a[now].l && !a[now].r) {
			mp[x][y] = a[now].op;
			r = r2 = y;
			return ;
		}
		int rl, rr;
		dfs(a[now].l, x + 2, y, rl, r1, r2);
		r1 += 6;
		r = r1;
		dfs(a[now].r, x + 2, r2 + 6, rr, r1, r2);
		mp[x + 1][rl] = mp[x + 1][rr] = '|';
		for (int i = rl + 1; i <= rr - 1; i++) {
			mp[x][i] = '-';
		}
		mp[x][rl] = mp[x][rr] = '.';
		mp[x][r] = a[now].op;
		mp[x][r - 1] = '[', mp[x][r + 1] = ']';
	}

	void print() {
		REP(i, a[num[1]].h) {
			cout << mp[i] << endl;
		}
	}
}t;

int main() {
    ios :: sync_with_stdio(0);
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> s;
	t.init();
	t.solve(s, strlen(s));
    return 0;
}
