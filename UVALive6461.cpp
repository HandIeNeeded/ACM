#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = (int) 2e5 + 5;
int a[N], s[N], mx;
int p[N], vis[N], tot;
vector<int> fac[N];

void GetPrime() {
	for (int i = 2; i < N; ++i){
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; ++j) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) {
				break;
			}
		}
	}
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) fac[i].push_back(i);
		else {
			int tmp = i;
			while (tmp % vis[i] == 0) {
				tmp /= vis[i];
			}
			fac[i].push_back(vis[i]);
			REP(j, fac[tmp].size()) {
				fac[i].push_back(fac[tmp][j]);
			}
		}
	}
}

int ql[N], qr[N], ans[N], tmp[N];
int l[N], r[N], lastpos[N];
vector<int> ed[N];

void add(int x, int d) {
	x++;
	while (x <= mx + 1) {
		s[x] += d;
		x += LB(x);
	}
}

int query(int x) {
	x++;
	int re = 0;
	while(x) {
		re += s[x];
		x -= LB(x);
	}
	return re;
}

bool cmp(const int &i, const int &j) {
	if (qr[i] == qr[j]) return ql[i] < ql[j];
	return qr[i] < qr[j];
}

int main() {
	ios :: sync_with_stdio(0);
	// freopen("cf.in", "r", stdin);

	// clock_t st = clock(), ed;
	GetPrime();
	// ed = clock();
	// cout << fixed << setprecision(10) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
	int n, m;
	while (cin >> n >> m, n | m) {
		mx = 0;
		REPP(i, 1, n) {
			cin >> a[i], mx = max(mx, a[i]);
		}
		mx = max(mx, n + 1);
		REPP(i, 1, m) {
			cin >> ql[i] >> qr[i];
		}
		REPP(i, 1, m) tmp[i] = i;
		sort(tmp + 1, tmp + m + 1, cmp);
		REPP(i, 1, mx) lastpos[i] = 0;
		REPP(i, 1, n) {
			int tmp = 0;
			REP(j, fac[a[i]].size()) {
				tmp = max(tmp, lastpos[fac[a[i]][j]]);
				lastpos[fac[a[i]][j]] = i;
			}
			l[i] = tmp;
		}
		REPP(i, 1, mx) lastpos[i] = n + 1;
		for (int i = n; i >= 1; --i) {
			int tmp = n + 1;
			REP(j, fac[a[i]].size()) {
				tmp = min(tmp, lastpos[fac[a[i]][j]]);
				lastpos[fac[a[i]][j]] = i;
			}
			r[i] = tmp;
		}
		REPP(i, 1, n) {
			ed[r[i]].push_back(i);
		}

		int now = 1;
		REPP(ca, 1, m) {
			int i = tmp[ca];
			REPP(j, now, qr[i]) {
				add(l[j], 1);
				REP(k, ed[j].size()) {
					add(l[ed[j][k]], -1);
					add(ed[j][k], 1);
				}
			}
			now = qr[i] + 1;
			ans[i] = (qr[i] - ql[i] + 1) - (query(qr[i]) - query(ql[i] - 1));
		}
		REPP(i, 1, m) cout << ans[i] << endl;
		REPP(i, 1, mx + 1) s[i] = 0, ed[i].clear();
	}

	return 0;
}