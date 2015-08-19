#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<LL, int>

using namespace std;

const int N = 1e5 + 5;
LL gap[N], p[N], d[N], pos[N];
pair<LL, LL> tour[N], exam[N];
priority_queue<PII, vector<PII>, greater<PII> > q;
int n, m;

bool cmp(int i, int j) {
	return d[i] < d[j];
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("intelligent.in", "r", stdin);
	freopen("intelligent.out", "w", stdout);
	while (cin >> n, n) {
		REPP(i, 1, n) {
			cin >> d[i] >> p[i];
			exam[i] = {d[i], p[i]};
		}
		sort(exam + 1, exam + n + 1);
		REPP(i, 1, n) tie(d[i], p[i]) = exam[i];
		//REPP(i, 1, n) {
		//	cout << tmp[i] << ' ';
		//}
		//cout << endl;
		cin >> m;
		REPP(i, 1, m) {
			cin >> tour[i].first >> tour[i].second;
		}
		sort(tour + 1, tour + m + 1);
		REPP(i, 1, m) pos[i] = tour[i].second;
		int right = 0;
		d[0] = 0;
		REPP(i, 1, n) {
			LL tmp = 0;
			while (right < m && pos[right + 1] < d[i]) right++, tmp += tour[right].second - tour[right].first + 1;
			gap[i] = d[i] - d[i - 1] - 1 - tmp;
		}
		//REPP(i, 1, n) {
		//	cout << gap[i] << ' ';
		//}
		//cout << endl;
		int ans = 0;
		vector<int> res;
		for (int i = n; i >= 1; i--) {
			q.push({p[i], i});
			while (gap[i] > 0) {
				if (q.size() == 0) break;
				LL tmp = q.top().first, id = q.top().second;
				//cout << i << ' ' << gap[i] << ' ' << tmp << endl;
				while (gap[i] >= tmp) {
					gap[i] -= tmp;
					ans++;
					res.push_back(id);
					q.pop();
					if (q.size() == 0) break;
					tmp = q.top().first, id = q.top().second;
				}
				if (gap[i] && q.size()) {
					tmp -= gap[i];
					gap[i] = 0;
					q.pop(), q.push({tmp, id});
				}
			}
		}
		cout << ans << endl;
		REP(i, res.size()) {
			cout << res[i] << " \n"[i == ans - 1];
		}
		while (q.size()) q.pop();
	}

    return 0;
}


