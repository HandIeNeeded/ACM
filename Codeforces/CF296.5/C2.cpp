#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
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

const int N = 1e5 + 5;
const int INF = 1e9;

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define PII pair<int, int>

struct SegTree{
	int mi[N << 2];

	void modify(int x, int l, int r, int qx, int qd) {
		if (l == r) {
			mi[x] = qd;
		}
		else {
			if (qx <= MID) modify(LC, qx, qd);
			else modify(RC, qx, qd);
			mi[x] = min(mi[L], mi[R]);
		}
	}

	int query(int x, int l, int r, int ql, int qr) {
		if (ql <= l && qr >= r) {
			return mi[x];
		}
		else {
			int ans = INF;
			if (ql <= MID) ans = min(ans, query(LC, ql, qr));
			if (qr > MID) ans = min(ans, query(RC, ql, qr));
			return ans;
		}
	}
}dir[2];

PII ans[N << 1];
string str[2] = {"YES", "NO"};
vector<PII> p;
int len[2], k, q;

struct Query{
	PII x, y;
	int id;
};

vector<Query> Q[2][N];

void work(int k) {
	REP(turn, 2) {
		sort(p.begin(), p.end());
		int now = 0;
		REPP(i, 1, len[turn]) {
			while (now < k && p[now].first == i) {
				dir[turn].modify(1, 1, len[turn ^ 1], p[now++].second, i);
			}
			bool res = 0;
			for (auto q: Q[turn][i]) {
				if (turn) {
					res = dir[turn].query(1, 1, len[turn ^ 1], q.x.first, q.y.first) < q.x.second;
				}
				else {
					res = dir[turn].query(1, 1, len[turn ^ 1], q.x.second, q.y.second) < q.x.first;
				}
				if (turn) ans[q.id].second = res;
				else ans[q.id].first = res;
			}
		}
		REP(i, p.size()) {
			swap(p[i].first, p[i].second);
		}
	}
}

int main() {
	//freopen("C.in", "r", stdin);
	ios :: sync_with_stdio(0);
	cin >> len[0] >> len[1] >> k >> q;
	REP(i, k) {
		int x, y;
		cin >> x >> y;
		p.push_back({x, y});
	}
	REP(i, q) {
		int x, y, z, w;
		cin >> x >> y >> z >> w;
		Query tmp = {{x, y}, {z, w}, i};
		Q[0][z].push_back(tmp);
		Q[1][w].push_back(tmp);
	}
	work(k);
	REP(i, q) {
		cout << str[ans[i].first & ans[i].second] << endl;
	}

	return 0;
}
