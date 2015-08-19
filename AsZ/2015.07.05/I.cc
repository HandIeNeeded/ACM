#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<LL, int>

using namespace std;

const int N = 1e5 + 5;
LL gap[N], p[N], d[N], pos[N], cost[N];
int tmp[N];
pair<LL, LL> tour[N], exam[N];
PII bad[N];
int n, m;

bool cmp(int i, int j) {
	return d[i] < d[j] || (d[i] == d[j] && p[i] < p[j]);
}

bool cmp2(PII a, PII b) {
	return d[a.second] < d[b.second];
}

struct cmp3{
	bool operator () (PII a, PII b) {
		return a.first < b.first || (a.first == b.first && d[a.second] > d[b.second]);
	}
};

priority_queue<PII, vector<PII>, cmp3> q;

int main() {
    ios :: sync_with_stdio(0);
	freopen("intelligent.in", "r", stdin);
	//freopen("intelligent.out", "w", stdout);
	while (cin >> n, n) {
		REPP(i, 1, n) {
			cin >> d[i] >> p[i];
			exam[i] = {d[i], p[i]};
			tmp[i] = i;
		}
		sort(exam + 1, exam + n + 1);
		sort(tmp + 1, tmp + n + 1, cmp);
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
					res.push_back(::tmp[id]);
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
		int tot = 0;
		while (q.size()) {
			bad[++tot] = q.top(); 
			q.pop();
		}
		int cnt = 0;
		sort(bad + 1, bad + tot + 1, cmp2);
		REPP(i, 1, tot) {
			cout << bad[i].first << ' ' << bad[i].second << endl;
		}
		REPP(i, 1, tot) {
			if (cnt >= bad[i].first) {
				cnt -= bad[i].first;
				ans++;
				res.push_back(tmp[bad[i].second]);
			}
			else cnt++;
		}
		cout << ans << endl;
		REP(i, res.size()) {
			cout << res[i] << " \n"[i == ans - 1];
		}
	}
    return 0;
}

