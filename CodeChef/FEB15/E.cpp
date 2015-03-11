#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a):i <= (int) (b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 1e6 + 5;

struct po{
	long long ans[4][4];
	int cnt[4];
}p[N << 2];

char s[N], a[2], b[2];
int ql, qr, qx, qy;

int get(char c) {
	if (c == 'c') return 0;
	else if (c == 'h') return 1;
	else if (c == 'e') return 2;
	else return 3;
}

void build(int x, int l, int r) {
	if (l == r) {
		p[x].cnt[get(s[l - 1])]++;
	}
	else {
		build(LC), build(RC);
		REP(i, 4) {
			REP(j, 4) {
				p[x].ans[i][j] = p[L].ans[i][j] + p[R].ans[i][j];
				p[x].ans[i][j] += 1LL * p[L].cnt[i] * p[R].cnt[j];
			}
		}
		REP(i, 4) {
			p[x].cnt[i] = p[L].cnt[i] + p[R].cnt[i];
		}
	}
}

pair<int, pair<int, int> > query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return {p[x].ans[qx][qy], {p[x].cnt[qx], p[x].cnt[qy]}};
	}
	else {
		if (qr <= MID) return query(LC);
		else if (ql > MID) return query(RC);
		else {
			pair<int, pair<int, int> > a = query(LC), b = query(RC), ans;
			ans.first = a.first + b.first + 1LL * a.second.first * b.second.second;
			ans.second.first = a.second.first + b.second.first;
			ans.second.second = a.second.second + b.second.second;
			return ans;
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("E.in", "r", stdin);
	scanf("%s", s);
	int n = strlen(s);
	int q;
	scanf("%d", &q);
	build(1, 1, n);
	while (q--) {
		scanf("%s %s %d %d", a, b, &ql, &qr);
		qx = get(a[0]);
		qy = get(b[0]);
		printf("%I64d\n", query(1, 1, n).first);
	}

	return 0;
}
