#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MP make_pair 

using namespace std;

const int N = 1105;

struct Polygon{
	vector<vector<int> > a;
}ans[N];

string s[N];
int p[N], vis[N], tot;

pair<bool, vector<int> > divide(vector<int> &a, vector<int> &b) {// a/b
	deque<int> tmp;
	vector<int> ans;
	REP(i, a.size() + 1) {
		if (tmp.size() == b.size()) {
			int c = tmp[0] / b[0];
			ans.push_back(c);
			REP(j, b.size()) {
				tmp[j] -= b[j] * c;
			}
		}
		if (tmp.size() && tmp[0] == 0) tmp.pop_front();
		if (i < a.size()) tmp.push_back(a[i]);
	}
	while (tmp.size() && tmp[0] == 0) tmp.pop_front();
	if (!tmp.size()) {
		return MP(1, ans);
	}
	else {
		return MP(0, vector<int> ());
	}
}

bool cmp(vector<int> a, vector<int> b) {
	if (a.size() == b.size()) {
		REP(i, a.size()) {
			int aa = abs(a[i]), bb = abs(b[i]);
			if (aa != bb) {
				return aa < bb;
			}
			else {
				if (a[i] != b[i]) {
					return a[i] < b[i];
				}
			}
		}
		return 0;
	}
	return a.size() < b.size();
}

string getone(vector<int> &a) {
	int len = a.size(), now = len - 1;
	string ans;
	REP(i, len) {
		if (a[i] == 0) {
			now--;
			continue;
		}
		if (a[i] > 0) {
			if (i != 0) ans += '+';
		}
		else {
			ans += '-';
		}
		if (abs(a[i]) > 1 || abs(a[i]) == 1 && now == 0) ans += to_string(abs(a[i]));
		if (now) ans += 'x';
		if (now > 1) {
			ans += '^';
			ans += to_string(now);
		}
		now--;
	}
	return ans;
}

string getstring(Polygon &a) {
	string ans;
	if (a.a.size() == 1) {
		ans = getone(a.a[0]);
	}
	else {
		REP(i, a.a.size()) {
			ans += '(' + getone(a.a[i]) + ')';
		}
	}
	return ans;
}

void Init() {
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) p[tot++] = i;
		for (int j = 0; j < tot && i * p[j] < N; ++j) {
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}

	vector<int> tmp(2);
	tmp[0] = 1, tmp[1] = -1;
	ans[1].a.push_back(tmp);
	REPP(i, 2, 1100) {
		vector<int> now(i + 1, 0);
		now[0] = 1, now[i] = -1;
		for (int j = 1; j * j <= i; ++j) {
			if (i % j == 0) {
				REP(k, ans[j].a.size()) {
					pair<bool, vector<int> > tmp = divide(now, ans[j].a[k]);
					if (tmp.first) {
						ans[i].a.push_back(ans[j].a[k]);
						now = tmp.second;
					}
				}
				if (i / j != j) {
					REP(k, ans[i / j].a.size()) {
						pair<bool, vector<int> > tmp = divide(now, ans[i / j].a[k]);
						if (tmp.first) {
							ans[i].a.push_back(ans[i / j].a[k]);
							now = tmp.second;
						}
					}
				}
			}
		}
		ans[i].a.push_back(now);
		sort(ans[i].a.begin(), ans[i].a.end(), cmp);
		ans[i].a.resize(unique(ans[i].a.begin(), ans[i].a.end()) - ans[i].a.begin());
	}

	REPP(i, 1, 1100) {
		s[i] = getstring(ans[i]);
	}
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("cf.in", "r", stdin);

	Init();
	int n;
	while (cin >> n, n) {
		cout << s[n] << endl;
	}

	return 0;
}